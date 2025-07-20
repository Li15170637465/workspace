
#include "music_player.h"
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // 添加字符串处理支持

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
        wc.lpfnWndProc = DefWindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "MusicPlayerClass";
        
        if (!RegisterClass(&wc)) {
            printf("注册窗口类失败! 错误代码: %d\n", GetLastError());
            return;
        }
        
        state->hWndNotify = CreateWindow(
            "MusicPlayerClass", NULL, 0, 0, 0, 0, 0, NULL, NULL, 
            GetModuleHandle(NULL), NULL);
            
        if (!state->hWndNotify) {
            printf("创建通知窗口失败! 错误代码: %d\n", GetLastError());
            return;
        }
    }

    char cmd[512];
    sprintf(cmd, "open \"%s\" alias mytrack", filename);
    
    // 添加错误处理
    MCIERROR err = mciSendString(cmd, NULL, 0, NULL);
    if (err != 0) {
        char errorMsg[256];
        mciGetErrorString(err, errorMsg, sizeof(errorMsg));
        printf("打开文件失败: %s\n", errorMsg);
        return;
    }
    
    sprintf(cmd, "play mytrack notify");
    err = mciSendString(cmd, NULL, 0, state->hWndNotify);
    if (err != 0) {
        char errorMsg[256];
        mciGetErrorString(err, errorMsg, sizeof(errorMsg));
        printf("播放失败: %s\n", errorMsg);
        
        // 关闭已打开的文件
        mciSendString("close mytrack", NULL, 0, NULL);
        return;
    }
    
    state->isPlaying = TRUE;
    state->isPaused = FALSE;
    printf("开始播放: %s\n", filename);
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
            printf("播放已暂停\n");
        }
    }
}

// 恢复播放
void resume_music(PlayerState* state) {
    if (state && state->isPlaying && state->isPaused) {
        if (mciSendString("resume mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = FALSE;
            printf("继续播放\n");
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
        printf("播放已停止\n");
    }
}

// 播放下一首
void next_track(PlayerState* state) {
    if (!state || state->playlist_size == 0) return;
    
    // 停止当前播放
    stop_music(state);
    
    // 计算下一首索引（循环播放）
    state->current_track = (state->current_track + 1) % state->playlist_size;
    
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
    
    // 播放新曲目
    play_current(state);
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