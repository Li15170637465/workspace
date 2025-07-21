# C�����������汾���������ֲ�����ʵ��

������ʹ��C������Ϊ�������ļ����������ֲ�����ʵ�֣����EasyXͼ�ο���п��ӻ�������

```c
// music_player.h
#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <windows.h>

// �ص��������Ͷ���
typedef void (*PlayerCallback)(int event, void* userdata);
typedef void (*ErrorCallback)(const char* errorMsg, void* userdata);

// ������״̬�ṹ��
typedef struct PlayerState {
    HWND hWndNotify;
    BOOL isPlaying;
    BOOL isPaused;
  
    // �����б����
    char** playlist;       // �����б�
    int playlist_size;     // �����б��С
    int current_track;     // ��ǰ������Ŀ����
  
    // ���Ž���
    DWORD current_position; // ��ǰ����λ�ã����룩
    DWORD total_length;    // ��ǰ��Ŀ���ܳ��ȣ����룩
  
    // �ص�����
    PlayerCallback callback;
    ErrorCallback error_callback;
    void* userdata;        // �û�����ָ��
  
    // ��������
    DWORD volume;          // ��ǰ���� (0-1000)
} PlayerState;

// �¼����Ͷ���
#define PLAYER_EVENT_PLAYING 1
#define PLAYER_EVENT_PAUSED 2
#define PLAYER_EVENT_STOPPED 3
#define PLAYER_EVENT_TRACK_CHANGED 4
#define PLAYER_EVENT_POSITION_CHANGED 5

// ��������
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

// ���ڹ��̺��������ڴ���MCI֪ͨ��Ϣ
LRESULT CALLBACK PlayerWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    PlayerState* state = (PlayerState*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
  
    if (state && msg == MM_MCINOTIFY) {
        if (wParam == MCI_NOTIFY_SUCCESSFUL) {
            // ������ɣ��Զ�������һ��
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
      
        // ��ʼ�������б�
        state->playlist = NULL;
        state->playlist_size = 0;
        state->current_track = -1;  // -1 ��ʾû��ѡ����Ŀ
      
        // ��ʼ�����Ⱥ�����
        state->current_position = 0;
        state->total_length = 0;
        state->volume = 500;  // Ĭ������50%
      
        // ��ʼ���ص�
        state->callback = NULL;
        state->error_callback = NULL;
        state->userdata = NULL;
    }
    return state;
}

// ���ò����б�
void set_playlist(PlayerState* state, char** files, int count) {
    if (!state || count <= 0) return;
  
    // �������в����б�
    if (state->playlist) {
        for (int i = 0; i < state->playlist_size; i++) {
            free(state->playlist[i]);
        }
        free(state->playlist);
    }
  
    // �����²����б��ڴ�
    state->playlist = (char**)malloc(count * sizeof(char*));
    state->playlist_size = count;
  
    // �����ļ�·��
    for (int i = 0; i < count; i++) {
        state->playlist[i] = _strdup(files[i]);  // �����ַ���
    }
  
    // ���õ�ǰ��ĿΪ��һ��
    state->current_track = 0;
  
    // �����ص�
    if (state->callback) {
        state->callback(PLAYER_EVENT_TRACK_CHANGED, state->userdata);
    }
}

// ���ûص�����
void set_callback(PlayerState* state, PlayerCallback callback, void* userdata) {
    if (state) {
        state->callback = callback;
        state->userdata = userdata;
    }
}

// ���ô���ص�����
void set_error_callback(PlayerState* state, ErrorCallback callback, void* userdata) {
    if (state) {
        state->error_callback = callback;
        state->userdata = userdata;
    }
}

// ����ָ���ļ�
void play_music(PlayerState* state, const char* filename) {
    if (!state || !filename) return;
  
    // ������ڲ��ţ���ֹͣ
    if (state->isPlaying) {
        stop_music(state);
    }

    // ����֪ͨ���ڣ������δ������
    if (!state->hWndNotify) {
        WNDCLASS wc = {0};
        wc.lpfnWndProc = PlayerWndProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "MusicPlayerClass";
      
        if (!RegisterClass(&wc)) {
            if (state->error_callback) {
                char errorMsg[256];
                sprintf(errorMsg, "ע�ᴰ����ʧ��! �������: %d", GetLastError());
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
                sprintf(errorMsg, "����֪ͨ����ʧ��! �������: %d", GetLastError());
                state->error_callback(errorMsg, state->userdata);
            }
            return;
        }
      
        // ��״ָ̬��洢�����ڵ�userdata��
        SetWindowLongPtr(state->hWndNotify, GWLP_USERDATA, (LONG_PTR)state);
    }

    char cmd[512];
    sprintf(cmd, "open \"%s\" type mpegvideo alias mytrack", filename);
  
    // ��Ӵ�����
    MCIERROR err = mciSendString(cmd, NULL, 0, NULL);
    if (err != 0) {
        if (state->error_callback) {
            char errorMsg[256];
            mciGetErrorString(err, errorMsg, sizeof(errorMsg));
            state->error_callback(errorMsg, state->userdata);
        }
        return;
    }
  
    // ��������
    sprintf(cmd, "setaudio mytrack volume to %d", state->volume);
    mciSendString(cmd, NULL, 0, NULL);
  
    // �������֣����������ʱ֪ͨ
    sprintf(cmd, "play mytrack notify");
    err = mciSendString(cmd, NULL, 0, state->hWndNotify);
    if (err != 0) {
        if (state->error_callback) {
            char errorMsg[256];
            mciGetErrorString(err, errorMsg, sizeof(errorMsg));
            state->error_callback(errorMsg, state->userdata);
        }
      
        // �ر��Ѵ򿪵��ļ�
        mciSendString("close mytrack", NULL, 0, NULL);
        return;
    }
  
    // ��ȡ�ܳ���
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
  
    // �����ص�
    if (state->callback) {
        state->callback(PLAYER_EVENT_PLAYING, state->userdata);
    }
}

// ���ŵ�ǰѡ�е���Ŀ
void play_current(PlayerState* state) {
    if (!state || state->current_track < 0 || 
        state->current_track >= state->playlist_size) {
        return;
    }
  
    play_music(state, state->playlist[state->current_track]);
}

// ��ͣ����
void pause_music(PlayerState* state) {
    if (state && state->isPlaying && !state->isPaused) {
        if (mciSendString("pause mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = TRUE;
          
            // �����ص�
            if (state->callback) {
                state->callback(PLAYER_EVENT_PAUSED, state->userdata);
            }
        }
    }
}

// �ָ�����
void resume_music(PlayerState* state) {
    if (state && state->isPlaying && state->isPaused) {
        if (mciSendString("resume mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = FALSE;
          
            // �����ص�
            if (state->callback) {
                state->callback(PLAYER_EVENT_PLAYING, state->userdata);
            }
        }
    }
}

// ֹͣ���Ų��ͷ���Դ
void stop_music(PlayerState* state) {
    if (state && state->isPlaying) {
        mciSendString("stop mytrack", NULL, 0, NULL);
        mciSendString("close mytrack", NULL, 0, NULL);
      
        state->isPlaying = FALSE;
        state->isPaused = FALSE;
        state->current_position = 0;
        state->total_length = 0;
      
        // �����ص�
        if (state->callback) {
            state->callback(PLAYER_EVENT_STOPPED, state->userdata);
        }
    }
}

// ������һ��
void next_track(PlayerState* state) {
    if (!state || state->playlist_size == 0) return;
  
    // ֹͣ��ǰ����
    stop_music(state);
  
    // ������һ��������ѭ�����ţ�
    state->current_track = (state->current_track + 1) % state->playlist_size;
  
    // �����ص�
    if (state->callback) {
        state->callback(PLAYER_EVENT_TRACK_CHANGED, state->userdata);
    }
  
    // ��������Ŀ
    play_current(state);
}

// ������һ��
void prev_track(PlayerState* state) {
    if (!state || state->playlist_size == 0) return;
  
    // ֹͣ��ǰ����
    stop_music(state);
  
    // ������һ��������ѭ�����ţ�
    state->current_track = (state->current_track - 1 + state->playlist_size) % state->playlist_size;
  
    // �����ص�
    if (state->callback) {
        state->callback(PLAYER_EVENT_TRACK_CHANGED, state->userdata);
    }
  
    // ��������Ŀ
    play_current(state);
}

// ��������
void set_volume(PlayerState* state, DWORD volume) {
    if (!state) return;
  
    // ������Χ������0-1000
    if (volume > 1000) volume = 1000;
  
    state->volume = volume;
  
    if (state->isPlaying) {
        char cmd[128];
        sprintf(cmd, "setaudio mytrack volume to %d", volume);
        mciSendString(cmd, NULL, 0, NULL);
    }
}

// ��ȡ����
DWORD get_volume(PlayerState* state) {
    return state ? state->volume : 0;
}

// ��ת��ָ��λ��
void seek_music(PlayerState* state, DWORD position) {
    if (!state || !state->isPlaying || position > state->total_length) 
        return;
  
    char cmd[128];
    sprintf(cmd, "seek mytrack to %d", position);
    if (mciSendString(cmd, NULL, 0, NULL) == 0) {
        sprintf(cmd, "play mytrack notify");
        mciSendString(cmd, NULL, 0, state->hWndNotify);
      
        state->current_position = position;
      
        // �����ص�
        if (state->callback) {
            state->callback(PLAYER_EVENT_POSITION_CHANGED, state->userdata);
        }
    }
}

// ���²���λ��
void update_playback_position(PlayerState* state) {
    if (!state || !state->isPlaying) {
        return;
    }

    char cmd[128];
    char buf[128] = {0};

    // ��ȡ��ǰλ��
    sprintf(cmd, "status mytrack position");
    if (mciSendString(cmd, buf, sizeof(buf), NULL) == 0) {
        DWORD new_position = atol(buf);
        if (new_position != state->current_position) {
            state->current_position = new_position;
          
            // �����ص�
            if (state->callback) {
                state->callback(PLAYER_EVENT_POSITION_CHANGED, state->userdata);
            }
        }
    }
}

// ����������Դ
void cleanup_player(PlayerState* state) {
    if (state) {
        stop_music(state);
      
        // �������б�
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
// main.c - C�����������汾
#include <graphics.h>
#include "music_player.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

// ����ߴ�
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// ��ɫ����
const COLORREF BACKGROUND_COLOR = RGB(40, 44, 52);
const COLORREF PANEL_COLOR = RGB(30, 34, 42);
const COLORREF TEXT_COLOR = RGB(220, 220, 220);
const COLORREF HIGHLIGHT_COLOR = RGB(97, 175, 239);
const COLORREF BUTTON_COLOR = RGB(86, 182, 194);
const COLORREF BUTTON_HOVER_COLOR = RGB(106, 202, 214);
const COLORREF PROGRESS_BG_COLOR = RGB(60, 64, 72);
const COLORREF PROGRESS_FG_COLOR = RGB(152, 195, 121);

// �ؼ�����
const RECT PLAYLIST_RECT = {20, 20, 780, 300};
const RECT PROGRESS_RECT = {20, 340, 780, 360};
const RECT TIME_RECT = {20, 370, 780, 390};
const RECT VOLUME_RECT = {20, 410, 780, 430};

// ��ť
const RECT PLAY_BTN = {280, 470, 330, 520};
const RECT PAUSE_BTN = {340, 470, 390, 520};
const RECT STOP_BTN = {400, 470, 450, 520};
const RECT PREV_BTN = {220, 470, 270, 520};
const RECT NEXT_BTN = {460, 470, 510, 520};
const RECT VOLUME_UP_BTN = {520, 470, 570, 520};
const RECT VOLUME_DOWN_BTN = {580, 470, 630, 520};

// ȫ�ֱ���
PlayerState* player = NULL;
int isDraggingProgress = 0;
int isDraggingVolume = 0;

// ��ȡ�ļ���
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

// ��ʽ��ʱ��
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

// ���ư�ť
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

// ���Ʋ����б�
void drawPlaylist() {
    if (!player) return;
  
    setfillcolor(PANEL_COLOR);
    solidrectangle(PLAYLIST_RECT.left, PLAYLIST_RECT.top, 
                  PLAYLIST_RECT.right, PLAYLIST_RECT.bottom);
  
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(14, 0, "Arial");
  
    // ���Ʊ���
    outtextxy(PLAYLIST_RECT.left + 10, PLAYLIST_RECT.top + 10, "�����б�");
  
    // �����б���
    int startY = PLAYLIST_RECT.top + 40;
    for (int i = 0; i < player->playlist_size; i++) {
        // ��ȡ�ļ���������·����
        char fileName[256] = {0};
        getFileName(player->playlist[i], fileName);
      
        // ������ǰ������
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

// ���ƽ�����
void drawProgressBar() {
    setfillcolor(PROGRESS_BG_COLOR);
    solidrectangle(PROGRESS_RECT.left, PROGRESS_RECT.top, 
                  PROGRESS_RECT.right, PROGRESS_RECT.bottom);
  
    // ���ƽ���
    if (player && player->total_length > 0) {
        int width = PROGRESS_RECT.right - PROGRESS_RECT.left;
        int progressWidth = (int)((double)player->current_position / player->total_length * width);
      
        setfillcolor(PROGRESS_FG_COLOR);
        solidrectangle(PROGRESS_RECT.left, PROGRESS_RECT.top, 
                      PROGRESS_RECT.left + progressWidth, PROGRESS_RECT.bottom);
      
        // �����϶���
        setfillcolor(HIGHLIGHT_COLOR);
        solidcircle(PROGRESS_RECT.left + progressWidth, 
                   (PROGRESS_RECT.top + PROGRESS_RECT.bottom) / 2, 8);
    }
  
    // ���Ʊ߿�
    setlinecolor(TEXT_COLOR);
    rectangle(PROGRESS_RECT.left, PROGRESS_RECT.top, 
             PROGRESS_RECT.right, PROGRESS_RECT.bottom);
}

// ����ʱ����Ϣ
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

// ������������
void drawVolumeControl() {
    setfillcolor(PROGRESS_BG_COLOR);
    solidrectangle(VOLUME_RECT.left, VOLUME_RECT.top, 
                  VOLUME_RECT.right, VOLUME_RECT.bottom);
  
    // ����������
    if (player) {
        int width = VOLUME_RECT.right - VOLUME_RECT.left;
        int volumeWidth = (int)((double)player->volume / 1000 * width);
      
        setfillcolor(BUTTON_COLOR);
        solidrectangle(VOLUME_RECT.left, VOLUME_RECT.top, 
                      VOLUME_RECT.left + volumeWidth, VOLUME_RECT.bottom);
      
        // �����϶���
        setfillcolor(HIGHLIGHT_COLOR);
        solidcircle(VOLUME_RECT.left + volumeWidth, 
                   (VOLUME_RECT.top + VOLUME_RECT.bottom) / 2, 8);
    }
  
    // ���Ʊ߿�
    setlinecolor(TEXT_COLOR);
    rectangle(VOLUME_RECT.left, VOLUME_RECT.top, 
             VOLUME_RECT.right, VOLUME_RECT.bottom);
  
    // ������ǩ
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(14, 0, "Arial");
    outtextxy(VOLUME_RECT.left, VOLUME_RECT.top - 20, "����");
}

// ����״̬��Ϣ
void drawStatusInfo() {
    if (!player) return;
  
    settextcolor(TEXT_COLOR);
    setbkmode(TRANSPARENT);
    settextstyle(16, 0, "Arial");
  
    const char* statusText = "";
    if (player->isPlaying) {
        statusText = player->isPaused ? "״̬: ��ͣ" : "״̬: ������";
    } else {
        statusText = "״̬: ֹͣ";
    }
  
    // ��ȡ��ǰ��Ŀ�ļ���
    char fileName[256] = {0};
    if (player->current_track >= 0 && player->current_track < player->playlist_size) {
        getFileName(player->playlist[player->current_track], fileName);
    }
  
    char info[256] = {0};
    sprintf(info, "%s - %s", statusText, fileName);
  
    int textWidth = textwidth(info);
    outtextxy((WINDOW_WIDTH - textWidth) / 2, 440, info);
}

// ������������
void drawUI() {
    // ��ʼ������ͼ
    BeginBatchDraw();
  
    // ���Ʊ���
    setbkcolor(BACKGROUND_COLOR);
    cleardevice();
  
    // ���Ʋ����б�
    drawPlaylist();
  
    // ���ƽ�����
    drawProgressBar();
  
    // ����ʱ����Ϣ
    drawTimeInfo();
  
    // ������������
    drawVolumeControl();
  
    // ����״̬��Ϣ
    drawStatusInfo();
  
    // ���ƿ��ư�ť
    drawButton(&PLAY_BTN, ">", 0);
    drawButton(&PAUSE_BTN, "||", 0);
    drawButton(&STOP_BTN, "[]", 0);
    drawButton(&PREV_BTN, "<<", 0);
    drawButton(&NEXT_BTN, ">>", 0);
    drawButton(&VOLUME_UP_BTN, "+", 0);
    drawButton(&VOLUME_DOWN_BTN, "-", 0);
  
    // ����������ͼ
    EndBatchDraw();
}

// �������ص�����
void playerCallback(int event, void* userdata) {
    // ��Ҫ�ػ����
    drawUI();
}

// ����ص�����
void errorCallback(const char* errorMsg, void* userdata) {
    // ��ʾ������Ϣ
    MessageBoxA(GetHWnd(), errorMsg, "���Ŵ���", MB_OK | MB_ICONERROR);
}

// �����Ƿ��ھ�����
int pointInRect(int x, int y, const RECT* rect) {
    return x >= rect->left && x <= rect->right && y >= rect->top && y <= rect->bottom;
}

// ������
int main() {
    // ��ʼ��ͼ�δ���
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    setbkcolor(BACKGROUND_COLOR);
    cleardevice();
  
    // ��ʼ��������
    player = init_player();
  
    // ���ûص�����
    set_callback(player, playerCallback, NULL);
    set_error_callback(player, errorCallback, NULL);
  
    // ���������б�
    const char* playlist[] = {
        "res/song1.mp3",
        "res/song2.mp3",
        "res/song3.mp3",
        "res/song4.mp3"
    };
    int playlist_size = sizeof(playlist) / sizeof(playlist[0]);
    set_playlist(player, (char**)playlist, playlist_size);
  
    // ��ʼ����
    drawUI();
  
    // ��ѭ��
    ExMessage msg;
    int running = 1;
  
    while (running) {
        // ��ȡ��Ϣ
        if (peekmessage(&msg, EX_MOUSE)) {
            switch (msg.message) {
                case WM_LBUTTONDOWN:
                    // ��ť���
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
                        // ���½���
                        int progress = (msg.x - PROGRESS_RECT.left) * player->total_length / 
                                      (PROGRESS_RECT.right - PROGRESS_RECT.left);
                        seek_music(player, progress);
                    } else if (pointInRect(msg.x, msg.y, &VOLUME_RECT)) {
                        isDraggingVolume = 1;
                        // ��������
                        int volume = (msg.x - VOLUME_RECT.left) * 1000 / 
                                    (VOLUME_RECT.right - VOLUME_RECT.left);
                        set_volume(player, volume);
                    }
                    break;
                  
                case WM_MOUSEMOVE:
                    // �������϶�
                    if (isDraggingProgress) {
                        int progress = (msg.x - PROGRESS_RECT.left) * player->total_length / 
                                      (PROGRESS_RECT.right - PROGRESS_RECT.left);
                        if (progress < 0) progress = 0;
                        if (progress > player->total_length) progress = player->total_length;
                        seek_music(player, progress);
                    } 
                    // �������϶�
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
      
        // ���²���λ��
        if (player && player->isPlaying && !player->isPaused) {
            update_playback_position(player);
        }
      
        // ��΢�ӳ��Խ���CPUʹ����
        Sleep(50);
    }
  
    // ��������
    cleanup_player(player);
  
    // �ر�ͼ�δ���
    closegraph();
    return 0;
}
```

## ��Ŀ�ṹ˵��

1. **�����ļ�**��

   - `music_player.h`��������ͷ�ļ�
   - `music_player.c`������������ʵ�֣�C���ԣ�
   - `main.c`��������C���ԣ�������ͼ�ν�����û�����
2. **��ԴĿ¼**��

   - ���� `res`�ļ��д�������ļ�
   - ʾ�������ļ���song1.mp3, song2.mp3��

## �����ص�

1. **���������ֲ��Ź���**��

   - ����/��ͣ/ֹͣ����
   - ��һ��/��һ���л�
   - ���Ž��ȿ��ƣ����϶���������
   - ��������
2. **�����б����**��

   - ��ʾ��ǰ�����б�
   - ������ǰ������Ŀ
   - ֧���Զ�ѭ������
3. **���ӻ�����**��

   - �ִ���ɫ�������
   - �����Ĳ���״̬��ʾ
   - ��������ʱ����ʾ
   - ����������
4. **������**��

   - ���ƵĴ���ص�����
   - ������Ϣ������ʾ

## ��Visual Studio�е����ò���

1. **��������Ŀ**��

   - ѡ��"����Ŀ"ģ��
   - ����Ϊ"MusicPlayer_C"
2. **���Դ�����ļ�**��

   - ��� `music_player.h`
   - ��� `music_player.c`
   - ��� `main.c`
3. **��װEasyXͼ�ο�**��

   - ���ص�ַ��https://easyx.cn
   - ���а�װ����ѡ����VS�汾ƥ���ѡ��
4. **������Ŀ����**��

   - �Ҽ���Ŀ > ����
   - �������� > �߼���
     - �ַ�����ʹ�ö��ֽ��ַ���
   - �������� > ������ > ���룺
     - ������������ `winmm.lib`
   - �������� > C/C++ > Ԥ��������
     - Ԥ���������壺��� `_CRT_SECURE_NO_WARNINGS`
5. **������Դ�ļ���**��

   - ����ĿĿ¼�д��� `res`�ļ���
   - ��Ӳ��������ļ���MP3��ʽ��
6. **���ɿ�ִ���ļ�**��

   - ѡ��Release����
   - �˵��� > ���� > ���ɽ������

## ���кͷַ�

1. **���г���**��

   - ��VS�а�F5���е���
   - ��ֱ���������ɵ� `MusicPlayer_C.exe`
2. **�ַ�Ӧ�ó���**��

   - ���������������ݵ��ļ��У�
     - `MusicPlayer_C.exe`
     - `res`�ļ��У����������ļ���
     - `EasyX_Redist.dll`�����ʹ�ö�̬���ӣ�
3. **������װ��**��

   - ʹ��Inno Setup�ȹ��ߴ�����װ����
   - ��������ݷ�ʽ
   - ��ӿ�ʼ�˵���

## ע������

1. **�ļ�·��**��

   - ȷ�������ļ�������ĿĿ¼�� `res`�ļ�����
   - ���޸Ĵ����е��ļ�·��
2. **���ָ�ʽ֧��**��

   - ֧��MP3��WAV��Windows Media Player֧�ֵĸ�ʽ
   - �������ʧ�ܣ�����ļ�·���͸�ʽ
3. **ͼ�ο�����**��

   - ���ʹ�þ�̬���ӵ�EasyX�汾���ַ�ʱ����Ҫ����DLL
   - ���ʹ�ö�̬���ӣ���Ҫ���� `EasyX_Redist.dll`

���C���԰汾�Ĳ�����������C++�汾��ͬ�Ĺ��ܣ�����ȫʹ��C���Ա�д���ʺ���Ҫ��C���������ĳ������������ִ���������������ѧϰC����ͼ�ν��濪���ĺ���Ŀ��
