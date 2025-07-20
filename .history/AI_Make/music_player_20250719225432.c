#include "music_player.h"
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>

PlayerState* init_player(void) {
    PlayerState* state = (PlayerState*)malloc(sizeof(PlayerState));
    if (state) {
        state->hWndNotify = NULL;
        state->isPlaying = FALSE;
        state->isPaused = FALSE;
    }
    return state;
}

void play_music(PlayerState* state, const char* filename) {
    if (!state || state->isPlaying) return;

    if (!state->hWndNotify) {
        WNDCLASS wc = {0};
        wc.lpfnWndProc = DefWindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "MusicPlayerClass";
        RegisterClass(&wc);
        
        state->hWndNotify = CreateWindow(
            "MusicPlayerClass", NULL, 0, 0, 0, 0, 0, NULL, NULL, 
            GetModuleHandle(NULL), NULL);
    }

    char cmd[512];
    sprintf(cmd, "open \"%s\" alias mytrack", filename);
    
    if (mciSendString(cmd, NULL, 0, NULL) == 0) {
        sprintf(cmd, "play mytrack notify");
        if (mciSendString(cmd, NULL, 0, state->hWndNotify) == 0) {
            state->isPlaying = TRUE;
            state->isPaused = FALSE;
            printf("开始播放: %s\n", filename);
        }
    }
}

void pause_music(PlayerState* state) {
    if (state && state->isPlaying && !state->isPaused) {
        if (mciSendString("pause mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = TRUE;
            printf("播放已暂停\n");
        }
    }
}

void resume_music(PlayerState* state) {
    if (state && state->isPlaying && state->isPaused) {
        if (mciSendString("resume mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = FALSE;
            printf("继续播放\n");
        }
    }
}

void stop_music(PlayerState* state) {
    if (state && state->isPlaying) {
        mciSendString("stop mytrack", NULL, 0, NULL);
        mciSendString("close mytrack", NULL, 0, NULL);
        
        state->isPlaying = FALSE;
        state->isPaused = FALSE;
        printf("播放已停止\n");
    }
}

void cleanup_player(PlayerState* state) {
    if (state) {
        stop_music(state);
        if (state->hWndNotify) DestroyWindow(state->hWndNotify);
        free(state);
    }
}