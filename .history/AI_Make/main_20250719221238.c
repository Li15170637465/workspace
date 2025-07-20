#include "music_player.h"
#include "music_player.h"  // 包含自定义头文件

int main() {
    // 初始化播放器
    PlayerState* player = init_player();
    
    // 播放音乐文件
    play_music(player, "C:\\Music\\sample.mp3");
    
    // 模拟用户交互
    Sleep(3000);       // 播放3秒
    pause_music(player);
    Sleep(1000);       // 暂停1秒
    resume_music(player);
    Sleep(2000);       // 再播放2秒
    stop_music(player);
    
    // 清理资源
    cleanup_player(player);
    return 0;
}