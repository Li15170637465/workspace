# ��ǿ�����ֲ���������Ӱ������ƹ���

�ҽ�Ϊ�������ֲ�������Ӽ��̿��ƹ��ܣ����û�����ֱ�Ӱ��°��������Ʋ��š�������������ʵ�ַ�����

## �ļ��ṹ

### music_player.h (ͷ�ļ�)

```c
#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <windows.h>

// ������״̬�ṹ��
typedef struct PlayerState {
    HWND hWndNotify;
    BOOL isPlaying;
    BOOL isPaused;
  
    // �����б����
    char** playlist;
    int playlist_size;
    int current_track;
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
```

### music_player.c (ʵ���ļ�) - ���ֲ���

(ʹ��֮ǰ��ʵ��)

### main.c (������) - ��Ӱ�������

```c
#include "music_player.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h> // ���ڼ�������

// ��ʾ������Ϣ
void show_help() {
    printf("\n===== ���ֲ��������� =====\n");
    printf("  [P] ����/��ͣ\n");
    printf("  [S] ֹͣ����\n");
    printf("  [N] ��һ��\n");
    printf("  [B] ��һ��\n");
    printf("  [Q] �˳�����\n");
    printf("  [H] ��ʾ����\n");
    printf("==========================\n\n");
}

int main() {
    PlayerState* player = init_player();
  
    // ���������б� - �滻Ϊ����ʵ���ļ�·��
    char* playlist[] = {
        "D:\\workspace\\AI_Make\\song1.mp3",
        "D:\\workspace\\AI_Make\\song2.mp3",
        "D:\\workspace\\AI_Make\\song3.mp3"
    };
    int playlist_size = sizeof(playlist) / sizeof(playlist[0]);
  
    // ���ò����б�
    set_playlist(player, playlist, playlist_size);
  
    printf("===== ���ֲ����� =====\n");
    printf("��ǰ�����б�:\n");
    for (int i = 0; i < playlist_size; i++) {
        printf(" %d. %s\n", i + 1, playlist[i]);
    }
  
    show_help();
  
    // ���ŵ�һ��
    printf("���ŵ�һ��...\n");
    play_current(player);
  
    // ������ѭ��
    int running = 1;
    while (running) {
        // ��鰴�����루��������
        if (_kbhit()) {
            char key = _getch();
            key = toupper(key); // ת��Ϊ��д
          
            switch (key) {
                case 'P': // ����/��ͣ
                    if (player->isPlaying) {
                        if (player->isPaused) {
                            printf("��������...\n");
                            resume_music(player);
                        } else {
                            printf("��ͣ����...\n");
                            pause_music(player);
                        }
                    } else {
                        printf("��ʼ����...\n");
                        play_current(player);
                    }
                    break;
                  
                case 'S': // ֹͣ
                    printf("ֹͣ����...\n");
                    stop_music(player);
                    break;
                  
                case 'N': // ��һ��
                    printf("�л�����һ��...\n");
                    next_track(player);
                    break;
                  
                case 'B': // ��һ��
                    printf("�л�����һ��...\n");
                    prev_track(player);
                    break;
                  
                case 'H': // ��ʾ����
                    show_help();
                    break;
                  
                case 'Q': // �˳�
                    printf("�˳�����...\n");
                    running = 0;
                    break;
                  
                default:
                    // ������������
                    break;
            }
        }
      
        // ����˯���Լ���CPUռ��
        Sleep(100);
    }
  
    // ������Դ
    stop_music(player);
    cleanup_player(player);
  
    return 0;
}
```

## ���̿��ƹ���˵��

### ��������

| ���� | ����      | ����                     |
| ---- | --------- | ------------------------ |
| P    | ����/��ͣ | �л����ź���ͣ״̬       |
| S    | ֹͣ      | ֹͣ��ǰ����             |
| N    | ��һ��    | �л��������б��е���һ�� |
| B    | ��һ��    | �л��������б��е���һ�� |
| H    | ����      | ��ʾ���ư�����Ϣ         |
| Q    | �˳�      | �˳�����                 |

### ʵ��ԭ��

1. **����������**��

   - ʹ�� `_kbhit()` ��������Ƿ��а�������
   - ʹ�� `_getch()` ��ȡ���µļ�ֵ
   - ��������ʽ��⣬������ͣ����ִ��
2. **������ѭ��**��

   - ��������������
   - ���ݰ���ִ����Ӧ����
   - ��������˯���Խ���CPUʹ����
3. **����ϵͳ**��

   - �� H ����ʾ���ð������书��
   - ��������ʱ�Զ���ʾ������Ϣ

## ���������

### ��������

```bash
gcc main.c music_player.c -o player.exe -lwinmm
```

### ����˵��

1. ��������ʾ��
2. ��������������Ŀ¼
3. ���� `player.exe`
4. ʹ�ü��̰������Ʋ�����

## ��ǿ���ܽ���

### 1. �����������

```c
// ��music_player.h���������
void set_volume(PlayerState* state, int volume);

// ��music_player.c��ʵ��
void set_volume(PlayerState* state, int volume) {
    if (!state) return;
  
    // ȷ��������0-1000��Χ��
    volume = (volume < 0) ? 0 : (volume > 1000) ? 1000 : volume;
  
    char cmd[64];
    sprintf(cmd, "setaudio mytrack volume to %d", volume);
    mciSendString(cmd, NULL, 0, NULL);
  
    printf("��������Ϊ: %d\n", volume);
}
```

### 2. ��ӽ�������ʾ

```c
// ��ʾ��ǰ���Ž���
void show_progress(PlayerState* state) {
    if (!state || !state->isPlaying) return;
  
    char position[32] = {0};
    char length[32] = {0};
  
    // ��ȡ��ǰλ��
    mciSendString("status mytrack position", position, sizeof(position), NULL);
    // ��ȡ�ܳ���
    mciSendString("status mytrack length", length, sizeof(length), NULL);
  
    // ת��Ϊ����
    long pos_ms = atol(position);
    long len_ms = atol(length);
  
    if (len_ms > 0) {
        int progress = (int)((double)pos_ms / len_ms * 50); // 50���ַ��Ľ�����
      
        printf("[");
        for (int i = 0; i < 50; i++) {
            if (i < progress) printf("=");
            else if (i == progress) printf(">");
            else printf(" ");
        }
        printf("] %d%%\r", (int)((double)pos_ms / len_ms * 100));
    }
}
```

### 3. ����ļ��������

```c
// ����ļ��������
void browse_files(PlayerState* player) {
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile("*.mp3", &findData);
  
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("δ�ҵ�MP3�ļ�\n");
        return;
    }
  
    printf("\n===== ��ǰĿ¼�е�MP3�ļ� =====\n");
    int count = 0;
    char* files[100]; // ���100���ļ�
  
    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            files[count] = _strdup(findData.cFileName);
            printf("%2d. %s\n", count + 1, files[count]);
            count++;
        }
    } while (FindNextFile(hFind, &findData) && count < 100);
  
    FindClose(hFind);
  
    if (count > 0) {
        set_playlist(player, files, count);
        printf("\n�����ò����б�! ��P��ʼ����\n");
    }
  
    // �ͷ���ʱ�ڴ�
    for (int i = 0; i < count; i++) {
        free(files[i]);
    }
}
```

### 4. ��main.c�м����¹���

```c
// ���°�������
switch (key) {
    // ... ���а������� ...
  
    case 'V': // ��������
        printf("��������: [+]���� [-]����\n");
        break;
      
    case '+': // ��������
        if (player->volume < 1000) {
            player->volume += 50;
            set_volume(player, player->volume);
        }
        break;
      
    case '-': // ��������
        if (player->volume > 0) {
            player->volume -= 50;
            set_volume(player, player->volume);
        }
        break;
      
    case 'F': // ����ļ�
        browse_files(player);
        break;
}
```

## ����ʹ������

1. �������

   ```bash
   gcc main.c music_player.c -o player.exe -lwinmm
   ```
2. ���г���

   ```bash
   player.exe
   ```
3. ʹ�ð������ƣ�

   - �� P ����/��ͣ
   - �� S ֹͣ
   - �� N ��һ��
   - �� B ��һ��
   - �� H ��ʾ����
   - �� Q �˳�
4. ��ǿ����ʹ�ã�

   - �� V ��ʾ����������ʾ
   - �� + ��������
   - �� - ��������
   - �� F �������ӵ�ǰĿ¼��MP3�ļ�

�����ǿ�����ֲ���������֧�������ļ��̿��ƹ��ܣ����û��������ɵؿ������ֲ��ţ�����ʹ�������ӵĲ˵�ϵͳ��
