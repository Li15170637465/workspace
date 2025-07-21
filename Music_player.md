# C语言主函数版本的完整音乐播放器实现

下面是使用C语言作为主函数文件的完整音乐播放器实现，结合EasyX图形库进行可视化开发：

```c
// music_player.h
#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <windows.h>

// 回调函数类型定义
typedef void (*PlayerCallback)(int event, void* userdata);
typedef void (*ErrorCallback)(const char* errorMsg, void* userdata);

// 播放器状态结构体
typedef struct PlayerState {
    HWND hWndNotify;
    BOOL isPlaying;
    BOOL isPaused;
  
    // 播放列表管理
    char** playlist;       // 播放列表
    int playlist_size;     // 播放列表大小
    int current_track;     // 当前播放曲目索引
  
    // 播放进度
    DWORD current_position; // 当前播放位置（毫秒）
    DWORD total_length;    // 当前曲目的总长度（毫秒）
  
    // 回调函数
    PlayerCallback callback;
    ErrorCallback error_callback;
    void* userdata;        // 用户数据指针
  
    // 音量控制
    DWORD volume;          // 当前音量 (0-1000)
} PlayerState;

// 事件类型定义
#define PLAYER_EVENT_PLAYING 1
#define PLAYER_EVENT_PAUSED 2
#define PLAYER_EVENT_STOPPED 3
#define PLAYER_EVENT_TRACK_CHANGED 4
#define PLAYER_EVENT_POSITION_CHANGED 5

// 函数声明
PlayerState* init_player(void);
void set_playlist(PlayerState* state, char** files, int count);
void play_music(PlayerState* state, const char* filename);
void play_current(PlayerState* state);
void pause_music(PlayerState* state);
void resume_music(PlayerState* state);
void stop_music(PlayerState* state);
void next_track(PlayerState* state);
void prev_track(PlayerState* state);
void cleanup_player(PlayerState* state);
void set_volume(PlayerState* state, DWORD volume);
DWORD get_volume(PlayerState* state);
void seek_music(PlayerState* state, DWORD position);
void set_callback(PlayerState* state, PlayerCallback callback, void* userdata);
void set_error_callback(PlayerState* state, ErrorCallback callback, void* userdata);
void update_playback_position(PlayerState* state);

#endif
```

```c
// music_player.c
#include "music_player.h"
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 窗口过程函数，用于处理MCI通知消息
LRESULT CALLBACK PlayerWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    PlayerState* state = (PlayerState*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
  
    if (state && msg == MM_MCINOTIFY) {
        if (wParam == MCI_NOTIFY_SUCCESSFUL) {
            // 播放完成，自动播放下一首
            if (state->isPlaying) {
                next_track(state);
            }
        }
    }
  
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

PlayerState* init_player(void) {
    PlayerState* state = (PlayerState*)malloc(sizeof(PlayerState));
    if (state) {
        state->hWndNotify = NULL;
        state->isPlaying = FALSE;
        state->isPaused = FALSE;
      
        // 初始化播放列表
        state->playlist = NULL;
        state->playlist_size = 0;
        state->current_track = -1;  // -1 表示没有选择曲目
      
        // 初始化进度和音量
        state->current_position = 0;
        state->total_length = 0;
        state->volume = 500;  // 默认音量50%
      
        // 初始化回调
        state->callback = NULL;
        state->error_callback = NULL;
        state->userdata = NULL;
    }
    return state;
}

// 设置播放列表
void set_playlist(PlayerState* state, char** files, int count) {
    if (!state || count <= 0) return;
  
    // 清理现有播放列表
    if (state->playlist) {
        for (int i = 0; i < state->playlist_size; i++) {
            free(state->playlist[i]);
        }
        free(state->playlist);
    }
  
    // 分配新播放列表内存
    state->playlist = (char**)malloc(count * sizeof(char*));
    state->playlist_size = count;
  
    // 复制文件路径
    for (int i = 0; i < count; i++) {
        state->playlist[i] = _strdup(files[i]);  // 复制字符串
    }
  
    // 设置当前曲目为第一首
    state->current_track = 0;
  
    // 触发回调
    if (state->callback) {
        state->callback(PLAYER_EVENT_TRACK_CHANGED, state->userdata);
    }
}

// 设置回调函数
void set_callback(PlayerState* state, PlayerCallback callback, void* userdata) {
    if (state) {
        state->callback = callback;
        state->userdata = userdata;
    }
}

// 设置错误回调函数
void set_error_callback(PlayerState* state, ErrorCallback callback, void* userdata) {
    if (state) {
        state->error_callback = callback;
        state->userdata = userdata;
    }
}

// 播放指定文件
void play_music(PlayerState* state, const char* filename) {
    if (!state || !filename) return;
  
    // 如果正在播放，先停止
    if (state->isPlaying) {
        stop_music(state);
    }

    // 创建通知窗口（如果尚未创建）
    if (!state->hWndNotify) {
        WNDCLASS wc = {0};
        wc.lpfnWndProc = PlayerWndProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "MusicPlayerClass";
      
        if (!RegisterClass(&wc)) {
            if (state->error_callback) {
                char errorMsg[256];
                sprintf(errorMsg, "注册窗口类失败! 错误代码: %d", GetLastError());
                state->error_callback(errorMsg, state->userdata);
            }
            return;
        }
      
        state->hWndNotify = CreateWindow(
            "MusicPlayerClass", NULL, 0, 0, 0, 0, 0, NULL, NULL, 
            GetModuleHandle(NULL), NULL);
          
        if (!state->hWndNotify) {
            if (state->error_callback) {
                char errorMsg[256];
                sprintf(errorMsg, "创建通知窗口失败! 错误代码: %d", GetLastError());
                state->error_callback(errorMsg, state->userdata);
            }
            return;
        }
      
        // 将状态指针存储到窗口的userdata中
        SetWindowLongPtr(state->hWndNotify, GWLP_USERDATA, (LONG_PTR)state);
    }

    char cmd[512];
    sprintf(cmd, "open \"%s\" type mpegvideo alias mytrack", filename);
  
    // 添加错误处理
    MCIERROR err = mciSendString(cmd, NULL, 0, NULL);
    if (err != 0) {
        if (state->error_callback) {
            char errorMsg[256];
            mciGetErrorString(err, errorMsg, sizeof(errorMsg));
            state->error_callback(errorMsg, state->userdata);
        }
        return;
    }
  
    // 设置音量
    sprintf(cmd, "setaudio mytrack volume to %d", state->volume);
    mciSendString(cmd, NULL, 0, NULL);
  
    // 播放音乐，并请求结束时通知
    sprintf(cmd, "play mytrack notify");
    err = mciSendString(cmd, NULL, 0, state->hWndNotify);
    if (err != 0) {
        if (state->error_callback) {
            char errorMsg[256];
            mciGetErrorString(err, errorMsg, sizeof(errorMsg));
            state->error_callback(errorMsg, state->userdata);
        }
      
        // 关闭已打开的文件
        mciSendString("close mytrack", NULL, 0, NULL);
        return;
    }
  
    // 获取总长度
    char cmdLen[128];
    sprintf(cmdLen, "status mytrack length");
    char lenBuf[128] = {0};
    err = mciSendString(cmdLen, lenBuf, sizeof(lenBuf), NULL);
    if (err == 0) {
        state->total_length = atol(lenBuf);
    } else {
        state->total_length = 0;
    }
  
    state->current_position = 0;
    state->isPlaying = TRUE;
    state->isPaused = FALSE;
  
    // 触发回调
    if (state->callback) {
        state->callback(PLAYER_EVENT_PLAYING, state->userdata);
    }
}

// 播放当前选中的曲目
void play_current(PlayerState* state) {
    if (!state || state->current_track < 0 || 
        state->current_track >= state->playlist_size) {
        return;
    }
  
    play_music(state, state->playlist[state->current_track]);
}

// 暂停播放
void pause_music(PlayerState* state) {
    if (state && state->isPlaying && !state->isPaused) {
        if (mciSendString("pause mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = TRUE;
          
            // 触发回调
            if (state->callback) {
                state->callback(PLAYER_EVENT_PAUSED, state->userdata);
            }
        }
    }
}

// 恢复播放
void resume_music(PlayerState* state) {
    if (state && state->isPlaying && state->isPaused) {
        if (mciSendString("resume mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = FALSE;
          
            // 触发回调
            if (state->callback) {
                state->callback(PLAYER_EVENT_PLAYING, state->userdata);
            }
        }
    }
}

// 停止播放并释放资源
void stop_music(PlayerState* state) {
    if (state && state->isPlaying) {
        mciSendString("stop mytrack", NULL, 0, NULL);
        mciSendString("close mytrack", NULL, 0, NULL);
      
        state->isPlaying = FALSE;
        state->isPaused = FALSE;
        state->current_position = 0;
        state->total_length = 0;
      
        // 触发回调
        if (state->callback) {
            state->callback(PLAYER_EVENT_STOPPED, state->userdata);
        }
    }
}

// 播放下一首
void next_track(PlayerState* state) {
    if (!state || state->playlist_size == 0) return;
  
    // 停止当前播放
    stop_music(state);
  
    // 计算下一首索引（循环播放）
    state->current_track = (state->current_track + 1) % state->playlist_size;
  
    // 触发回调
    if (state->callback) {
        state->callback(PLAYER_EVENT_TRACK_CHANGED, state->userdata);
    }
  
    // 播放新曲目
    play_current(state);
}

// 播放上一首
void prev_track(PlayerState* state) {
    if (!state || state->playlist_size == 0) return;
  
    // 停止当前播放
    stop_music(state);
  
    // 计算上一首索引（循环播放）
    state->current_track = (state->current_track - 1 + state->playlist_size) % state->playlist_size;
  
    // 触发回调
    if (state->callback) {
        state->callback(PLAYER_EVENT_TRACK_CHANGED, state->userdata);
    }
  
    // 播放新曲目
    play_current(state);
}

// 设置音量
void set_volume(PlayerState* state, DWORD volume) {
    if (!state) return;
  
    // 音量范围限制在0-1000
    if (volume > 1000) volume = 1000;
  
    state->volume = volume;
  
    if (state->isPlaying) {
        char cmd[128];
        sprintf(cmd, "setaudio mytrack volume to %d", volume);
        mciSendString(cmd, NULL, 0, NULL);
    }
}

// 获取音量
DWORD get_volume(PlayerState* state) {
    return state ? state->volume : 0;
}

// 跳转到指定位置
void seek_music(PlayerState* state, DWORD position) {
    if (!state || !state->isPlaying || position > state->total_length) 
        return;
  
    char cmd[128];
    sprintf(cmd, "seek mytrack to %d", position);
    if (mciSendString(cmd, NULL, 0, NULL) == 0) {
        sprintf(cmd, "play mytrack notify");
        mciSendString(cmd, NULL, 0, state->hWndNotify);
      
        state->current_position = position;
      
        // 触发回调
        if (state->callback) {
            state->callback(PLAYER_EVENT_POSITION_CHANGED, state->userdata);
        }
    }
}

// 更新播放位置
void update_playback_position(PlayerState* state) {
    if (!state || !state->isPlaying) {
        return;
    }

    char cmd[128];
    char buf[128] = {0};

    // 获取当前位置
    sprintf(cmd, "status mytrack position");
    if (mciSendString(cmd, buf, sizeof(buf), NULL) == 0) {
        DWORD new_position = atol(buf);
        if (new_position != state->current_position) {
            state->current_position = new_position;
          
            // 触发回调
            if (state->callback) {
                state->callback(PLAYER_EVENT_POSITION_CHANGED, state->userdata);
            }
        }
    }
}

// 清理播放器资源
void cleanup_player(PlayerState* state) {
    if (state) {
        stop_music(state);
      
        // 清理播放列表
        if (state->playlist) {
            for (int i = 0; i < state->playlist_size; i++) {
                free(state->playlist[i]);
            }
            free(state->playlist);
        }
      
        if (state->hWndNotify) DestroyWindow(state->hWndNotify);
        free(state);
    }
}
```

```c
// main.c - C语言主函数版本
#include <graphics.h>
#include "music_player.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

// 界面尺寸
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// 颜色定义
const COLORREF BACKGROUND_COLOR = RGB(40, 44, 52);
const COLORREF PANEL_COLOR = RGB(30, 34, 42);
const COLORREF TEXT_COLOR = RGB(220, 220, 220);
const COLORREF HIGHLIGHT_COLOR = RGB(97, 175, 239);
const COLORREF BUTTON_COLOR = RGB(86, 182, 194);
const COLORREF BUTTON_HOVER_COLOR = RGB(106, 202, 214);
const COLORREF PROGRESS_BG_COLOR = RGB(60, 64, 72);
const COLORREF PROGRESS_FG_COLOR = RGB(152, 195, 121);

// 控件区域
const RECT PLAYLIST_RECT = {20, 20, 780, 300};
const RECT PROGRESS_RECT = {20, 340, 780, 360};
const RECT TIME_RECT = {20, 370, 780, 390};
const RECT VOLUME_RECT = {20, 410, 780, 430};

// 按钮
const RECT PLAY_BTN = {280, 470, 330, 520};
const RECT PAUSE_BTN = {340, 470, 390, 520};
const RECT STOP_BTN = {400, 470, 450, 520};
const RECT PREV_BTN = {220, 470, 270, 520};
const RECT NEXT_BTN = {460, 470, 510, 520};
const RECT VOLUME_UP_BTN = {520, 470, 570, 520};
const RECT VOLUME_DOWN_BTN = {580, 470, 630, 520};

// 全局变量
PlayerState* player = NULL;
int isDraggingProgress = 0;
int isDraggingVolume = 0;

// 获取文件名
void getFileName(const char* fullPath, char* fileName) {
    const char* lastSlash = strrchr(fullPath, '\\');
    if (lastSlash == NULL) {
        lastSlash = strrchr(fullPath, '/');
    }
  
    if (lastSlash != NULL) {
        strcpy(fileName, lastSlash + 1);
    } else {
        strcpy(fileName, fullPath);
    }
}

// 格式化时间
void formatTime(DWORD milliseconds, char* buffer) {
    int seconds = (milliseconds / 1000) % 60;
    int minutes = (milliseconds / (1000 * 60)) % 60;
    int hours = (milliseconds / (1000 * 60 * 60)) % 24;
  
    if (hours > 0) {
        sprintf(buffer, "%02d:%02d:%02d", hours, minutes, seconds);
    } else {
        sprintf(buffer, "%02d:%02d", minutes, seconds);
    }
}

// 绘制按钮
void drawButton(const RECT* rect, const char* text, int hover) {
    setfillcolor(hover ? BUTTON_HOVER_COLOR : BUTTON_COLOR);
    solidroundrect(rect->left, rect->top, rect->right, rect->bottom, 10, 10);
  
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(16, 0, "Arial");
    int textWidth = textwidth(text);
    int textHeight = textheight(text);
    outtextxy((rect->left + rect->right - textWidth) / 2, 
              (rect->top + rect->bottom - textHeight) / 2, 
              text);
}

// 绘制播放列表
void drawPlaylist() {
    if (!player) return;
  
    setfillcolor(PANEL_COLOR);
    solidrectangle(PLAYLIST_RECT.left, PLAYLIST_RECT.top, 
                  PLAYLIST_RECT.right, PLAYLIST_RECT.bottom);
  
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(14, 0, "Arial");
  
    // 绘制标题
    outtextxy(PLAYLIST_RECT.left + 10, PLAYLIST_RECT.top + 10, "播放列表");
  
    // 绘制列表项
    int startY = PLAYLIST_RECT.top + 40;
    for (int i = 0; i < player->playlist_size; i++) {
        // 获取文件名（不含路径）
        char fileName[256] = {0};
        getFileName(player->playlist[i], fileName);
      
        // 高亮当前播放项
        if (i == player->current_track) {
            setfillcolor(HIGHLIGHT_COLOR);
            solidrectangle(PLAYLIST_RECT.left + 10, startY - 5, 
                          PLAYLIST_RECT.right - 10, startY + 25);
            settextcolor(BACKGROUND_COLOR);
        } else {
            settextcolor(TEXT_COLOR);
        }
      
        outtextxy(PLAYLIST_RECT.left + 20, startY, fileName);
        startY += 30;
    }
}

// 绘制进度条
void drawProgressBar() {
    setfillcolor(PROGRESS_BG_COLOR);
    solidrectangle(PROGRESS_RECT.left, PROGRESS_RECT.top, 
                  PROGRESS_RECT.right, PROGRESS_RECT.bottom);
  
    // 绘制进度
    if (player && player->total_length > 0) {
        int width = PROGRESS_RECT.right - PROGRESS_RECT.left;
        int progressWidth = (int)((double)player->current_position / player->total_length * width);
      
        setfillcolor(PROGRESS_FG_COLOR);
        solidrectangle(PROGRESS_RECT.left, PROGRESS_RECT.top, 
                      PROGRESS_RECT.left + progressWidth, PROGRESS_RECT.bottom);
      
        // 绘制拖动点
        setfillcolor(HIGHLIGHT_COLOR);
        solidcircle(PROGRESS_RECT.left + progressWidth, 
                   (PROGRESS_RECT.top + PROGRESS_RECT.bottom) / 2, 8);
    }
  
    // 绘制边框
    setlinecolor(TEXT_COLOR);
    rectangle(PROGRESS_RECT.left, PROGRESS_RECT.top, 
             PROGRESS_RECT.right, PROGRESS_RECT.bottom);
}

// 绘制时间信息
void drawTimeInfo() {
    if (!player) return;
  
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(14, 0, "Arial");
  
    char currentTime[20] = {0};
    char totalTime[20] = {0};
    formatTime(player->current_position, currentTime);
    formatTime(player->total_length, totalTime);
  
    char timeStr[50] = {0};
    sprintf(timeStr, "%s / %s", currentTime, totalTime);
  
    int textWidth = textwidth(timeStr);
    outtextxy((PROGRESS_RECT.left + PROGRESS_RECT.right - textWidth) / 2, 
             TIME_RECT.top, timeStr);
}

// 绘制音量控制
void drawVolumeControl() {
    setfillcolor(PROGRESS_BG_COLOR);
    solidrectangle(VOLUME_RECT.left, VOLUME_RECT.top, 
                  VOLUME_RECT.right, VOLUME_RECT.bottom);
  
    // 绘制音量条
    if (player) {
        int width = VOLUME_RECT.right - VOLUME_RECT.left;
        int volumeWidth = (int)((double)player->volume / 1000 * width);
      
        setfillcolor(BUTTON_COLOR);
        solidrectangle(VOLUME_RECT.left, VOLUME_RECT.top, 
                      VOLUME_RECT.left + volumeWidth, VOLUME_RECT.bottom);
      
        // 绘制拖动点
        setfillcolor(HIGHLIGHT_COLOR);
        solidcircle(VOLUME_RECT.left + volumeWidth, 
                   (VOLUME_RECT.top + VOLUME_RECT.bottom) / 2, 8);
    }
  
    // 绘制边框
    setlinecolor(TEXT_COLOR);
    rectangle(VOLUME_RECT.left, VOLUME_RECT.top, 
             VOLUME_RECT.right, VOLUME_RECT.bottom);
  
    // 音量标签
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(14, 0, "Arial");
    outtextxy(VOLUME_RECT.left, VOLUME_RECT.top - 20, "音量");
}

// 绘制状态信息
void drawStatusInfo() {
    if (!player) return;
  
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(16, 0, "Arial");
  
    const char* statusText = "";
    if (player->isPlaying) {
        statusText = player->isPaused ? "状态: 暂停" : "状态: 播放中";
    } else {
        statusText = "状态: 停止";
    }
  
    // 获取当前曲目文件名
    char fileName[256] = {0};
    if (player->current_track >= 0 && player->current_track < player->playlist_size) {
        getFileName(player->playlist[player->current_track], fileName);
    }
  
    char info[256] = {0};
    sprintf(info, "%s - %s", statusText, fileName);
  
    int textWidth = textwidth(info);
    outtextxy((WINDOW_WIDTH - textWidth) / 2, 440, info);
}

// 绘制整个界面
void drawUI() {
    // 开始批量绘图
    BeginBatchDraw();
  
    // 绘制背景
    setbkcolor(BACKGROUND_COLOR);
    cleardevice();
  
    // 绘制播放列表
    drawPlaylist();
  
    // 绘制进度条
    drawProgressBar();
  
    // 绘制时间信息
    drawTimeInfo();
  
    // 绘制音量控制
    drawVolumeControl();
  
    // 绘制状态信息
    drawStatusInfo();
  
    // 绘制控制按钮
    drawButton(&PLAY_BTN, ">", 0);
    drawButton(&PAUSE_BTN, "||", 0);
    drawButton(&STOP_BTN, "[]", 0);
    drawButton(&PREV_BTN, "<<", 0);
    drawButton(&NEXT_BTN, ">>", 0);
    drawButton(&VOLUME_UP_BTN, "+", 0);
    drawButton(&VOLUME_DOWN_BTN, "-", 0);
  
    // 结束批量绘图
    EndBatchDraw();
}

// 播放器回调函数
void playerCallback(int event, void* userdata) {
    // 需要重绘界面
    drawUI();
}

// 错误回调函数
void errorCallback(const char* errorMsg, void* userdata) {
    // 显示错误消息
    MessageBoxA(GetHWnd(), errorMsg, "播放错误", MB_OK | MB_ICONERROR);
}

// 检查点是否在矩形内
int pointInRect(int x, int y, const RECT* rect) {
    return x >= rect->left && x <= rect->right && y >= rect->top && y <= rect->bottom;
}

// 主函数
int main() {
    // 初始化图形窗口
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    setbkcolor(BACKGROUND_COLOR);
    cleardevice();
  
    // 初始化播放器
    player = init_player();
  
    // 设置回调函数
    set_callback(player, playerCallback, NULL);
    set_error_callback(player, errorCallback, NULL);
  
    // 创建播放列表
    const char* playlist[] = {
        "res/song1.mp3",
        "res/song2.mp3",
        "res/song3.mp3",
        "res/song4.mp3"
    };
    int playlist_size = sizeof(playlist) / sizeof(playlist[0]);
    set_playlist(player, (char**)playlist, playlist_size);
  
    // 初始绘制
    drawUI();
  
    // 主循环
    ExMessage msg;
    int running = 1;
  
    while (running) {
        // 获取消息
        if (peekmessage(&msg, EX_MOUSE)) {
            switch (msg.message) {
                case WM_LBUTTONDOWN:
                    // 按钮点击
                    if (pointInRect(msg.x, msg.y, &PLAY_BTN)) {
                        if (player->isPlaying && player->isPaused) {
                            resume_music(player);
                        } else {
                            play_current(player);
                        }
                    } else if (pointInRect(msg.x, msg.y, &PAUSE_BTN)) {
                        if (player->isPlaying && !player->isPaused) {
                            pause_music(player);
                        }
                    } else if (pointInRect(msg.x, msg.y, &STOP_BTN)) {
                        stop_music(player);
                    } else if (pointInRect(msg.x, msg.y, &PREV_BTN)) {
                        prev_track(player);
                    } else if (pointInRect(msg.x, msg.y, &NEXT_BTN)) {
                        next_track(player);
                    } else if (pointInRect(msg.x, msg.y, &VOLUME_UP_BTN)) {
                        DWORD newVolume = player->volume + 100;
                        if (newVolume > 1000) newVolume = 1000;
                        set_volume(player, newVolume);
                        drawUI();
                    } else if (pointInRect(msg.x, msg.y, &VOLUME_DOWN_BTN)) {
                        DWORD newVolume = player->volume > 100 ? player->volume - 100 : 0;
                        set_volume(player, newVolume);
                        drawUI();
                    } else if (pointInRect(msg.x, msg.y, &PROGRESS_RECT)) {
                        isDraggingProgress = 1;
                        // 更新进度
                        int progress = (msg.x - PROGRESS_RECT.left) * player->total_length / 
                                      (PROGRESS_RECT.right - PROGRESS_RECT.left);
                        seek_music(player, progress);
                    } else if (pointInRect(msg.x, msg.y, &VOLUME_RECT)) {
                        isDraggingVolume = 1;
                        // 更新音量
                        int volume = (msg.x - VOLUME_RECT.left) * 1000 / 
                                    (VOLUME_RECT.right - VOLUME_RECT.left);
                        set_volume(player, volume);
                    }
                    break;
                  
                case WM_MOUSEMOVE:
                    // 进度条拖动
                    if (isDraggingProgress) {
                        int progress = (msg.x - PROGRESS_RECT.left) * player->total_length / 
                                      (PROGRESS_RECT.right - PROGRESS_RECT.left);
                        if (progress < 0) progress = 0;
                        if (progress > player->total_length) progress = player->total_length;
                        seek_music(player, progress);
                    } 
                    // 音量条拖动
                    else if (isDraggingVolume) {
                        int volume = (msg.x - VOLUME_RECT.left) * 1000 / 
                                    (VOLUME_RECT.right - VOLUME_RECT.left);
                        if (volume < 0) volume = 0;
                        if (volume > 1000) volume = 1000;
                        set_volume(player, volume);
                    }
                    break;
                  
                case WM_LBUTTONUP:
                    isDraggingProgress = 0;
                    isDraggingVolume = 0;
                    break;
            }
        }
      
        // 更新播放位置
        if (player && player->isPlaying && !player->isPaused) {
            update_playback_position(player);
        }
      
        // 稍微延迟以降低CPU使用率
        Sleep(50);
    }
  
    // 清理播放器
    cleanup_player(player);
  
    // 关闭图形窗口
    closegraph();
    return 0;
}
```

## 项目结构说明

1. **核心文件**：

   - `music_player.h`：播放器头文件
   - `music_player.c`：播放器核心实现（C语言）
   - `main.c`：主程序（C语言），包含图形界面和用户交互
2. **资源目录**：

   - 创建 `res`文件夹存放音乐文件
   - 示例音乐文件：song1.mp3, song2.mp3等

## 功能特点

1. **完整的音乐播放功能**：

   - 播放/暂停/停止控制
   - 上一曲/下一曲切换
   - 播放进度控制（可拖动进度条）
   - 音量调节
2. **播放列表管理**：

   - 显示当前播放列表
   - 高亮当前播放曲目
   - 支持自动循环播放
3. **可视化界面**：

   - 现代深色主题设计
   - 清晰的播放状态显示
   - 进度条和时间显示
   - 音量控制条
4. **错误处理**：

   - 完善的错误回调机制
   - 错误消息弹窗提示

## 在Visual Studio中的配置步骤

1. **创建新项目**：

   - 选择"空项目"模板
   - 命名为"MusicPlayer_C"
2. **添加源代码文件**：

   - 添加 `music_player.h`
   - 添加 `music_player.c`
   - 添加 `main.c`
3. **安装EasyX图形库**：

   - 下载地址：https://easyx.cn
   - 运行安装程序，选择与VS版本匹配的选项
4. **配置项目属性**：

   - 右键项目 > 属性
   - 配置属性 > 高级：
     - 字符集：使用多字节字符集
   - 配置属性 > 链接器 > 输入：
     - 附加依赖项：添加 `winmm.lib`
   - 配置属性 > C/C++ > 预处理器：
     - 预处理器定义：添加 `_CRT_SECURE_NO_WARNINGS`
5. **创建资源文件夹**：

   - 在项目目录中创建 `res`文件夹
   - 添加测试音乐文件（MP3格式）
6. **生成可执行文件**：

   - 选择Release配置
   - 菜单栏 > 生成 > 生成解决方案

## 运行和分发

1. **运行程序**：

   - 在VS中按F5运行调试
   - 或直接运行生成的 `MusicPlayer_C.exe`
2. **分发应用程序**：

   - 创建包含以下内容的文件夹：
     - `MusicPlayer_C.exe`
     - `res`文件夹（包含音乐文件）
     - `EasyX_Redist.dll`（如果使用动态链接）
3. **创建安装包**：

   - 使用Inno Setup等工具创建安装程序
   - 添加桌面快捷方式
   - 添加开始菜单项

## 注意事项

1. **文件路径**：

   - 确保音乐文件放在项目目录的 `res`文件夹中
   - 或修改代码中的文件路径
2. **音乐格式支持**：

   - 支持MP3、WAV等Windows Media Player支持的格式
   - 如果播放失败，检查文件路径和格式
3. **图形库依赖**：

   - 如果使用静态链接的EasyX版本，分发时不需要额外DLL
   - 如果使用动态链接，需要包含 `EasyX_Redist.dll`

这个C语言版本的播放器具有与C++版本相同的功能，但完全使用C语言编写，适合需要纯C开发环境的场景。界面简洁现代，功能完整，是学习C语言图形界面开发的好项目。
