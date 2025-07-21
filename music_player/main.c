
#include "music_player.h"
#include <windows.h>
#include <stdio.h>

int main() {
    PlayerState* player = init_player();
    
    // ���������б�
    char* playlist[] = {
        "D:\\workspace\\music_player\\song1.wav",
        "D:\\workspace\\music_player\\song2.wav",
        "D:\\workspace\\music_player\\song3.wav",
        "D:\\workspace\\music_player\\song4.wav"
    };
    int playlist_size = sizeof(playlist) / sizeof(playlist[0]);
    
    // ���ò����б�
    set_playlist(player, playlist, playlist_size);
    
    printf("===== ���ֲ����� =====\n");
    printf("��ǰ�����б�:\n");
    for (int i = 0; i < playlist_size; i++) {
        printf(" %d. %s\n", i + 1, playlist[i]);
    }
    printf("\n");
    
    // ���ŵ�һ��
    printf("���ŵ�һ��...\n");
    play_current(player);
    
    // ģ���û�����
    Sleep(3000);       // ����3��
    
    printf("\n�л�����һ��...\n");
    next_track(player);
    Sleep(300000);       // ����3��
    
    printf("\n�л�����һ��...\n");
    prev_track(player);
    Sleep(300000);       // ����3��
    
    printf("\n��ͣ����...\n");
    pause_music(player);
    Sleep(100000);       // ��ͣ1��
    
    printf("\n��������...\n");
    resume_music(player);
    Sleep(200000);       // �ٲ���2��
    
    printf("\nֹͣ����...\n");
    stop_music(player);
    
    cleanup_player(player);
    
    // ��ӵȴ�����ֹ���������˳�
    printf("\n����ִ����ϣ����س����˳�...");
    getchar();
    
    return 0;
}