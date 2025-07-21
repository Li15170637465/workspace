
#include "music_player.h"
#include <windows.h>
#include <stdio.h>

int main() {
    PlayerState* player = init_player();
    
    // 创建播放列表
    char* playlist[] = {
        "D:\\workspace\\music_player\\song1.wav",
        "D:\\workspace\\music_player\\song2.wav",
        "D:\\workspace\\music_player\\song3.wav",
        "D:\\workspace\\music_player\\song4.wav"
    };
    int playlist_size = sizeof(playlist) / sizeof(playlist[0]);
    
    // 设置播放列表
    set_playlist(player, playlist, playlist_size);
    
    printf("===== 音乐播放器 =====\n");
    printf("当前播放列表:\n");
    for (int i = 0; i < playlist_size; i++) {
        printf(" %d. %s\n", i + 1, playlist[i]);
    }
    printf("\n");
    
    // 播放第一首
    printf("播放第一首...\n");
    play_current(player);
    
    // 模拟用户操作
    Sleep(3000);       // 播放3秒
    
    printf("\n切换到下一首...\n");
    next_track(player);
    Sleep(300000);       // 播放3秒
    
    printf("\n切换到上一首...\n");
    prev_track(player);
    Sleep(300000);       // 播放3秒
    
    printf("\n暂停播放...\n");
    pause_music(player);
    Sleep(100000);       // 暂停1秒
    
    printf("\n继续播放...\n");
    resume_music(player);
    Sleep(200000);       // 再播放2秒
    
    printf("\n停止播放...\n");
    stop_music(player);
    
    cleanup_player(player);
    
    // 添加等待，防止程序立即退出
    printf("\n程序执行完毕，按回车键退出...");
    getchar();
    
    return 0;
}