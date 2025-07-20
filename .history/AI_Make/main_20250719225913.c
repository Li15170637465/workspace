#include "music_player.h"
#include <windows.h>

int main()
     {
    PlayerState* player = init_player();
    play_music("player, "D:\\workspace\AI_Make\music\bgm1.mp3");
    
    Sleep(3000);       // 播放3秒
    pause_music(player);
    Sleep(1000);       // 暂停1秒
    resume_music(player);
    Sleep(2000);       // 再播放2秒
    stop_music(player);
    
     清理资源
    cleanup_player(player);
    return 0;
    }
