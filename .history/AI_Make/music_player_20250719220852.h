// music_player.h
#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <windows.h>

// ������״̬�ṹ��
typedef struct {
    HWND hWndNotify;   // ֪ͨ���ھ��
    BOOL isPlaying;    // ����״̬��־
    BOOL isPaused;     // ��ͣ״̬��־
} PlayerState;

// ��������
PlayerState* init_player(void);
void play_music(PlayerState* state, const char* filename);
void pause_music(PlayerState* state);
void resume_music(PlayerState* state);
void stop_music(PlayerState* state);
void cleanup_player(PlayerState* state);

#endif