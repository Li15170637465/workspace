#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <windows.h>

// ������״̬�ṹ��
typedef struct PlayerState {
    HWND hWndNotify;
    BOOL isPlaying;
    BOOL isPaused;
    
    // �����������б����
    char** playlist;       // �����б�
    int playlist_size;     // �����б��С
    int current_track;     // ��ǰ������Ŀ����
} PlayerState;

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

#endif