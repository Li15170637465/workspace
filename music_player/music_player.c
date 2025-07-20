
#include "music_player.h"
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // ����ַ�������֧��

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
        wc.lpfnWndProc = DefWindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "MusicPlayerClass";
        
        if (!RegisterClass(&wc)) {
            printf("ע�ᴰ����ʧ��! �������: %d\n", GetLastError());
            return;
        }
        
        state->hWndNotify = CreateWindow(
            "MusicPlayerClass", NULL, 0, 0, 0, 0, 0, NULL, NULL, 
            GetModuleHandle(NULL), NULL);
            
        if (!state->hWndNotify) {
            printf("����֪ͨ����ʧ��! �������: %d\n", GetLastError());
            return;
        }
    }

    char cmd[512];
    sprintf(cmd, "open \"%s\" alias mytrack", filename);
    
    // ��Ӵ�����
    MCIERROR err = mciSendString(cmd, NULL, 0, NULL);
    if (err != 0) {
        char errorMsg[256];
        mciGetErrorString(err, errorMsg, sizeof(errorMsg));
        printf("���ļ�ʧ��: %s\n", errorMsg);
        return;
    }
    
    sprintf(cmd, "play mytrack notify");
    err = mciSendString(cmd, NULL, 0, state->hWndNotify);
    if (err != 0) {
        char errorMsg[256];
        mciGetErrorString(err, errorMsg, sizeof(errorMsg));
        printf("����ʧ��: %s\n", errorMsg);
        
        // �ر��Ѵ򿪵��ļ�
        mciSendString("close mytrack", NULL, 0, NULL);
        return;
    }
    
    state->isPlaying = TRUE;
    state->isPaused = FALSE;
    printf("��ʼ����: %s\n", filename);
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
            printf("��������ͣ\n");
        }
    }
}

// �ָ�����
void resume_music(PlayerState* state) {
    if (state && state->isPlaying && state->isPaused) {
        if (mciSendString("resume mytrack", NULL, 0, NULL) == 0) {
            state->isPaused = FALSE;
            printf("��������\n");
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
        printf("������ֹͣ\n");
    }
}

// ������һ��
void next_track(PlayerState* state) {
    if (!state || state->playlist_size == 0) return;
    
    // ֹͣ��ǰ����
    stop_music(state);
    
    // ������һ��������ѭ�����ţ�
    state->current_track = (state->current_track + 1) % state->playlist_size;
    
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
    
    // ��������Ŀ
    play_current(state);
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