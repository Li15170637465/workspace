# 增强版音乐播放器：添加按键控制功能

我将为您的音乐播放器添加键盘控制功能，让用户可以直接按下按键来控制播放。以下是完整的实现方案：

## 文件结构

### music_player.h (头文件)

```c
#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <windows.h>

// 播放器状态结构体
typedef struct PlayerState {
    HWND hWndNotify;
    BOOL isPlaying;
    BOOL isPaused;
  
    // 播放列表管理
    char** playlist;
    int playlist_size;
    int current_track;
} PlayerState;

// 函数声明
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

### music_player.c (实现文件) - 保持不变

(使用之前的实现)

### main.c (主程序) - 添加按键控制

```c
#include "music_player.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h> // 用于键盘输入

// 显示帮助信息
void show_help() {
    printf("\n===== 音乐播放器控制 =====\n");
    printf("  [P] 播放/暂停\n");
    printf("  [S] 停止播放\n");
    printf("  [N] 下一首\n");
    printf("  [B] 上一首\n");
    printf("  [Q] 退出程序\n");
    printf("  [H] 显示帮助\n");
    printf("==========================\n\n");
}

int main() {
    PlayerState* player = init_player();
  
    // 创建播放列表 - 替换为您的实际文件路径
    char* playlist[] = {
        "D:\\workspace\\AI_Make\\song1.mp3",
        "D:\\workspace\\AI_Make\\song2.mp3",
        "D:\\workspace\\AI_Make\\song3.mp3"
    };
    int playlist_size = sizeof(playlist) / sizeof(playlist[0]);
  
    // 设置播放列表
    set_playlist(player, playlist, playlist_size);
  
    printf("===== 音乐播放器 =====\n");
    printf("当前播放列表:\n");
    for (int i = 0; i < playlist_size; i++) {
        printf(" %d. %s\n", i + 1, playlist[i]);
    }
  
    show_help();
  
    // 播放第一首
    printf("播放第一首...\n");
    play_current(player);
  
    // 主控制循环
    int running = 1;
    while (running) {
        // 检查按键输入（非阻塞）
        if (_kbhit()) {
            char key = _getch();
            key = toupper(key); // 转换为大写
          
            switch (key) {
                case 'P': // 播放/暂停
                    if (player->isPlaying) {
                        if (player->isPaused) {
                            printf("继续播放...\n");
                            resume_music(player);
                        } else {
                            printf("暂停播放...\n");
                            pause_music(player);
                        }
                    } else {
                        printf("开始播放...\n");
                        play_current(player);
                    }
                    break;
                  
                case 'S': // 停止
                    printf("停止播放...\n");
                    stop_music(player);
                    break;
                  
                case 'N': // 下一首
                    printf("切换到下一首...\n");
                    next_track(player);
                    break;
                  
                case 'B': // 上一首
                    printf("切换到上一首...\n");
                    prev_track(player);
                    break;
                  
                case 'H': // 显示帮助
                    show_help();
                    break;
                  
                case 'Q': // 退出
                    printf("退出程序...\n");
                    running = 0;
                    break;
                  
                default:
                    // 忽略其他按键
                    break;
            }
        }
      
        // 短暂睡眠以减少CPU占用
        Sleep(100);
    }
  
    // 清理资源
    stop_music(player);
    cleanup_player(player);
  
    return 0;
}
```

## 键盘控制功能说明

### 按键分配

| 按键 | 功能      | 描述                     |
| ---- | --------- | ------------------------ |
| P    | 播放/暂停 | 切换播放和暂停状态       |
| S    | 停止      | 停止当前播放             |
| N    | 下一首    | 切换到播放列表中的下一首 |
| B    | 上一首    | 切换到播放列表中的上一首 |
| H    | 帮助      | 显示控制帮助信息         |
| Q    | 退出      | 退出程序                 |

### 实现原理

1. **键盘输入检测**：

   - 使用 `_kbhit()` 函数检查是否有按键按下
   - 使用 `_getch()` 获取按下的键值
   - 非阻塞方式检测，不会暂停程序执行
2. **主控制循环**：

   - 持续检查键盘输入
   - 根据按键执行相应操作
   - 包含短暂睡眠以降低CPU使用率
3. **帮助系统**：

   - 按 H 键显示可用按键及其功能
   - 程序启动时自动显示帮助信息

## 编译和运行

### 编译命令

```bash
gcc main.c music_player.c -o player.exe -lwinmm
```

### 运行说明

1. 打开命令提示符
2. 导航到程序所在目录
3. 运行 `player.exe`
4. 使用键盘按键控制播放器

## 增强功能建议

### 1. 添加音量控制

```c
// 在music_player.h中添加声明
void set_volume(PlayerState* state, int volume);

// 在music_player.c中实现
void set_volume(PlayerState* state, int volume) {
    if (!state) return;
  
    // 确保音量在0-1000范围内
    volume = (volume < 0) ? 0 : (volume > 1000) ? 1000 : volume;
  
    char cmd[64];
    sprintf(cmd, "setaudio mytrack volume to %d", volume);
    mciSendString(cmd, NULL, 0, NULL);
  
    printf("音量设置为: %d\n", volume);
}
```

### 2. 添加进度条显示

```c
// 显示当前播放进度
void show_progress(PlayerState* state) {
    if (!state || !state->isPlaying) return;
  
    char position[32] = {0};
    char length[32] = {0};
  
    // 获取当前位置
    mciSendString("status mytrack position", position, sizeof(position), NULL);
    // 获取总长度
    mciSendString("status mytrack length", length, sizeof(length), NULL);
  
    // 转换为毫秒
    long pos_ms = atol(position);
    long len_ms = atol(length);
  
    if (len_ms > 0) {
        int progress = (int)((double)pos_ms / len_ms * 50); // 50个字符的进度条
      
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

### 3. 添加文件浏览功能

```c
// 添加文件浏览功能
void browse_files(PlayerState* player) {
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile("*.mp3", &findData);
  
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("未找到MP3文件\n");
        return;
    }
  
    printf("\n===== 当前目录中的MP3文件 =====\n");
    int count = 0;
    char* files[100]; // 最多100个文件
  
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
        printf("\n已设置播放列表! 按P开始播放\n");
    }
  
    // 释放临时内存
    for (int i = 0; i < count; i++) {
        free(files[i]);
    }
}
```

### 4. 在main.c中集成新功能

```c
// 更新按键处理
switch (key) {
    // ... 现有按键处理 ...
  
    case 'V': // 音量控制
        printf("音量控制: [+]增加 [-]减少\n");
        break;
      
    case '+': // 增加音量
        if (player->volume < 1000) {
            player->volume += 50;
            set_volume(player, player->volume);
        }
        break;
      
    case '-': // 减少音量
        if (player->volume > 0) {
            player->volume -= 50;
            set_volume(player, player->volume);
        }
        break;
      
    case 'F': // 浏览文件
        browse_files(player);
        break;
}
```

## 完整使用流程

1. 编译程序：

   ```bash
   gcc main.c music_player.c -o player.exe -lwinmm
   ```
2. 运行程序：

   ```bash
   player.exe
   ```
3. 使用按键控制：

   - 按 P 播放/暂停
   - 按 S 停止
   - 按 N 下一首
   - 按 B 上一首
   - 按 H 显示帮助
   - 按 Q 退出
4. 增强功能使用：

   - 按 V 显示音量控制提示
   - 按 + 增加音量
   - 按 - 减少音量
   - 按 F 浏览并添加当前目录的MP3文件

这个增强版音乐播放器现在支持完整的键盘控制功能，让用户可以轻松地控制音乐播放，无需使用鼠标或复杂的菜单系统。
