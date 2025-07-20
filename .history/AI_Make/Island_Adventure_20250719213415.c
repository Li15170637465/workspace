#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��Ϸ����
#define MAP_SIZE 19
#define TILE_WATER 'ˮ'
#define TILE_SAND 'ɳ'
#define TILE_GRASS '��'
#define TILE_FOREST '��'
#define TILE_MOUNTAIN 'ɽ'
#define PLAYER '��'

int main() {
    // ��ʼ���������
    srand(time(0));
    
    // ������ͼ����
    char map[MAP_SIZE][MAP_SIZE];
    
    // ��ʼ����ͼ - ����Ϊ½�أ�����Ϊˮ
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            // ���������ĵľ���
            int dist = abs(r - MAP_SIZE/2) + abs(c - MAP_SIZE/2);
            
            if (dist < 3) {
                // �������� - �ݵ�
                map[r][c] = TILE_GRASS;
            } else if (dist < 7) {
                // �м����� - �������
                int randType = rand() % 100;
                if (randType < 40) map[r][c] = TILE_GRASS;
                else if (randType < 70) map[r][c] = TILE_SAND;
                else if (randType < 90) map[r][c] = TILE_FOREST;
                else map[r][c] = TILE_MOUNTAIN;
            } else if (dist < 10) {
                // ��Χ���� - ɳ̲
                map[r][c] = TILE_SAND;
            } else {
                // ����� - ˮ
                map[r][c] = TILE_WATER;
            }
        }
    }
    
    // ���һЩ�������
    for (int i = 0; i < 15; i++) {
        int r = rand() % MAP_SIZE;
        int c = rand() % MAP_SIZE;
        if (map[r][c] != TILE_WATER) {
            map[r][c] = TILE_MOUNTAIN;
        }
    }
    
    for (int i = 0; i < 20; i++) {
        int r = rand() % MAP_SIZE;
        int c = rand() % MAP_SIZE;
        if (map[r][c] != TILE_WATER && map[r][c] != TILE_MOUNTAIN) {
            map[r][c] = TILE_FOREST;
        }
    }
    
    // ��ҳ�ʼλ��
    int player_row = MAP_SIZE/2;
    int player_col = MAP_SIZE/2;
    
    // ��Ϸ״̬
    int steps = 0;
    int health = 100;
    int water = 100;
    int food = 100;
    char input;
    
    printf("=================================================\n");
    printf("|             �ĵ����� - ����ð����Ϸ           |\n");
    printf("=================================================\n");
    printf("| �㱻����һ���ĵ��ϣ�̽������Ѱ��������Դ      |\n");
    printf("| ���Ʒ�ʽ: w(��) s(��) a(��) d(��)            |\n");
    printf("|         i(״̬) q(�˳�)                      |\n");
    printf("| ���η���: ��=��, ˮ=ˮ��, ɳ=ɳ̲, ��=�ݵ�   |\n");
    printf("|          ��=ɭ��, ɽ=ɽ��                    |\n");
    printf("=================================================\n\n");
    
    while (1) {
        // ��ʾ��ͼ
        printf("\n��ǰ��ͼ:\n");
        for (int r = 0; r < MAP_SIZE; r++) {
            for (int c = 0; c < MAP_SIZE; c++) {
                if (r == player_row && c == player_col) {
                    printf("%c", PLAYER);
                } else {
                    printf("%c", map[r][c]);
                }
            }
            printf("\n");
        }
        
        // ��ʾ���״̬
        printf("\n����: %d, ����ֵ: %d, ��ˮ: %d, ʳ��: %d\n", steps, health, water, food);
        
        // ����Ч��
        char current_tile = map[player_row][player_col];
        switch(current_tile) {
            case TILE_WATER:
                printf("����ˮ�У�С����ˮ��\n");
                health -= 5;
                break;
            case TILE_SAND:
                printf("����ɳ̲������\n");
                water -= 2;
                food -= 1;
                break;
            case TILE_GRASS:
                printf("���ڲݵ�������\n");
                water -= 1;
                food -= 1;
                break;
            case TILE_FOREST:
                printf("����ɭ���У������ҵ�ʳ���ˮԴ\n");
                water += 5;
                food += 3;
                if (water > 100) water = 100;
                if (food > 100) food = 100;
                break;
            case TILE_MOUNTAIN:
                printf("������ɽ�����ĸ�������\n");
                water -= 3;
                food -= 3;
                health -= 1;
                break;
        }
        
        // �������״̬
        if (health <= 0 || water <= 0 || food <= 0) {
            printf("\n��������Ϸ���� ������\n");
            if (health <= 0) printf("�������ֵ�ľ�\n");
            else if (water <= 0) printf("����ˮ����\n");
            else printf("�������\n");
            break;
        }
        
        // ��ȡ�������
        printf("\n�ж�: ");
        scanf(" %c", &input);
        
        // ������������
        if (input == 'q') {
            printf("��Ϸ������\n");
            break;
        } else if (input == 'i') {
            printf("=== ����״̬ ===\n");
            printf("����ֵ: %d/100\n", health);
            printf("��ˮ: %d/100\n", water);
            printf("ʳ��: %d/100\n", food);
            printf("����: %d\n", steps);
            continue;
        }
        
        // �����λ��
        int old_row = player_row;
        int old_col = player_col;
        
        // ���������ƶ����
        switch (input) {
            case 'w': player_row--; break;
            case 's': player_row++; break;
            case 'a': player_col--; break;
            case 'd': player_col++; break;
            default: 
                printf("��Ч����! ʹ�� w, a, s, d �ƶ�\n");
                continue;
        }
        
        // �߽���
        if (player_row < 0) player_row = 0;
        if (player_row >= MAP_SIZE) player_row = MAP_SIZE - 1;
        if (player_col < 0) player_col = 0;
        if (player_col >= MAP_SIZE) player_col = MAP_SIZE - 1;
        
        // ���λ�÷����仯�����²�������Դ
        if (player_row != old_row || player_col != old_col) {
            steps++;
            water -= 1;
            food -= 1;
        }
    }
    
    printf("\n��л����ĵ�������\n");
    printf("�������� %d ��\n", steps);
    
    return 0;
}