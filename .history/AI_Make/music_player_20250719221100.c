#include "music_player.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>  // 添加 malloc/free 支持

// 播放器状态结构体
typedef struct {
    HWND hWndNotify;   // 通知窗口句柄
    BOOL isPlaying;    // 播放状态标志
    BOOL isPaused;     // 暂停状态标志
} PlayerState;

// 初始化播放器状态
PlayerState* init_player() {
    PlayerState* state = (PlayerState*)malloc(sizeof(PlayerState));
    if (state) {
        state->hWndNotify = NULL;
        state->isPlaying = FALSE;
        state->isPaused = FALSE;
    }
    return state;
}

// 打开并播放音乐文件
void play_music(PlayerState* state, const char* filename) {
    if (!state || state->isPlaying) return;

    // 创建不可见窗口接收播放完成通知
    if (!state->hWndNotify) {
        WNDCLASS wc = {0};
        wc.lpfnWndProc = DefWindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "MusicPlayerClass";
        RegisterClass(&wc);
        
        state->hWndNotify = CreateWindow(
            "MusicPlayerClass", 
            NULL, 0, 0, 0, 0, 0, NULL, NULL, 
            GetModuleHandle(NULL), NULL);
    }

    char cmd[512];
    sprintf(cmd, "open \"%s\" alias mytrack", filename);
    
    // 发送MCI命令
    if (mciSendString(cmd, NULL, 0, NULL) == 0) {
        sprintf(cmd, "play mytrack notify");
        if (mciSendString(cmd, NULL, 0, state->hWndNotify) == 0) {
            state->isPlaying = TRUE;
            state->isPaused = FALSE;
            printf("开始播放: %s\n", filename);
        }
    }
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

// 清理播放器资源
void cleanup_player(PlayerState* state) {
    if (state) {
        stop_music(state);
        if (state->hWndNotify) DestroyWindow(state->hWndNotify);
        free(state);
    }
}