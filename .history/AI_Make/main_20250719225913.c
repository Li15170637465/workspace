#include "music_player.h"
#include <windows.h>

int main()
     {
    PlayerState* player = init_player();
    play_music("player, "D:\\workspace\AI_Make\music\bgm1.mp3");
    
    Sleep(3000);       // ����3��
    pause_music(player);
    Sleep(1000);       // ��ͣ1��
    resume_music(player);
    Sleep(2000);       // �ٲ���2��
    stop_music(player);
    
     ������Դ
    cleanup_player(player);
    return 0;
    }
