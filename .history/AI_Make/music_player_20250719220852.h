// music_player.h
#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <windows.h>

// 播放器状态结构体
typedef struct {
    HWND hWndNotify;   // 通知窗口句柄
    BOOL isPlaying;    // 播放状态标志
    BOOL isPaused;     // 暂停状态标志
} PlayerState;

// 函数声明
PlayerState* init_player(void);
void play_music(PlayerState* state, const char* filename);
void pause_music(PlayerState* state);
void resume_music(PlayerState* state);
void stop_music(PlayerState* state);
void cleanup_player(PlayerState* state);

#endif