#include "music_player.h"
#include "music_player.h"  // �����Զ���ͷ�ļ�

int main() {
    // ��ʼ��������
    PlayerState* player = init_player();
    
    // ���������ļ�
    play_music(player, "C:\\Music\\sample.mp3");
    
    // ģ���û�����
    Sleep(3000);       // ����3��
    pause_music(player);
    Sleep(1000);       // ��ͣ1��
    resume_music(player);
    Sleep(2000);       // �ٲ���2��
    stop_music(player);
    
    // ������Դ
    cleanup_player(player);
    return 0;
}