// music_player.c
#include "music_player.h"
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>  // 添加 malloc/free 支持

// 函数实现（与原始代码相同）
PlayerState* init_player() {
    PlayerState* state = (PlayerState*)malloc(sizeof(PlayerState));
    if (state) {
        state->hWndNotify = NULL;
        state->isPlaying = FALSE;
        state->isPaused = FALSE;
    }
    return state;
}

void play_music(PlayerState* state, const char* filename) {
    // 实现代码与原始相同...
}

void pause_music(PlayerState* state) {
    // 实现代码与原始相同...
}

void resume_music(PlayerState* state) {
    // 实现代码与原始相同...
}

void stop_music(PlayerState* state) {
    // 实现代码与原始相同...
}

void cleanup_player(PlayerState* state) {
    // 实现代码与原始相同...
}