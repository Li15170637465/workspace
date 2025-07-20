#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 游戏配置
#define MAP_SIZE 19
#define TILE_WATER '水'
#define TILE_SAND '沙'
#define TILE_GRASS '草'
#define TILE_FOREST '林'
#define TILE_MOUNTAIN '山'
#define PLAYER '人'

int main() {
    // 初始化随机种子
    srand(time(0));
    
    // 创建地图数组
    char map[MAP_SIZE][MAP_SIZE];
    
    // 初始化地图 - 中心为陆地，四周为水
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            // 计算离中心的距离
            int dist = abs(r - MAP_SIZE/2) + abs(c - MAP_SIZE/2);
            
            if (dist < 3) {
                // 中心区域 - 草地
                map[r][c] = TILE_GRASS;
            } else if (dist < 7) {
                // 中间区域 - 随机地形
                int randType = rand() % 100;
                if (randType < 40) map[r][c] = TILE_GRASS;
                else if (randType < 70) map[r][c] = TILE_SAND;
                else if (randType < 90) map[r][c] = TILE_FOREST;
                else map[r][c] = TILE_MOUNTAIN;
            } else if (dist < 10) {
                // 外围区域 - 沙滩
                map[r][c] = TILE_SAND;
            } else {
                // 最外层 - 水
                map[r][c] = TILE_WATER;
            }
        }
    }
    
    // 添加一些特殊地形
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
    
    // 玩家初始位置
    int player_row = MAP_SIZE/2;
    int player_col = MAP_SIZE/2;
    
    // 游戏状态
    int steps = 0;
    int health = 100;
    int water = 100;
    int food = 100;
    char input;
    
    printf("=================================================\n");
    printf("|             荒岛求生 - 文字冒险游戏           |\n");
    printf("=================================================\n");
    printf("| 你被困在一个荒岛上，探索岛屿寻找求生资源      |\n");
    printf("| 控制方式: w(上) s(下) a(左) d(右)            |\n");
    printf("|         i(状态) q(退出)                      |\n");
    printf("| 地形符号: 人=你, 水=水域, 沙=沙滩, 草=草地   |\n");
    printf("|          林=森林, 山=山脉                    |\n");
    printf("=================================================\n\n");
    
    while (1) {
        // 显示地图
        printf("\n当前地图:\n");
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
        
        // 显示玩家状态
        printf("\n步数: %d, 生命值: %d, 饮水: %d, 食物: %d\n", steps, health, water, food);
        
        // 地形效果
        char current_tile = map[player_row][player_col];
        switch(current_tile) {
            case TILE_WATER:
                printf("你在水中，小心溺水！\n");
                health -= 5;
                break;
            case TILE_SAND:
                printf("你在沙滩上行走\n");
                water -= 2;
                food -= 1;
                break;
            case TILE_GRASS:
                printf("你在草地上行走\n");
                water -= 1;
                food -= 1;
                break;
            case TILE_FOREST:
                printf("你在森林中，可以找到食物和水源\n");
                water += 5;
                food += 3;
                if (water > 100) water = 100;
                if (food > 100) food = 100;
                break;
            case TILE_MOUNTAIN:
                printf("你在爬山，消耗更多体力\n");
                water -= 3;
                food -= 3;
                health -= 1;
                break;
        }
        
        // 检查生存状态
        if (health <= 0 || water <= 0 || food <= 0) {
            printf("\n！！！游戏结束 ！！！\n");
            if (health <= 0) printf("你的生命值耗尽\n");
            else if (water <= 0) printf("你脱水而亡\n");
            else printf("你饿死了\n");
            break;
        }
        
        // 获取玩家输入
        printf("\n行动: ");
        scanf(" %c", &input);
        
        // 处理特殊命令
        if (input == 'q') {
            printf("游戏结束！\n");
            break;
        } else if (input == 'i') {
            printf("=== 生存状态 ===\n");
            printf("生命值: %d/100\n", health);
            printf("饮水: %d/100\n", water);
            printf("食物: %d/100\n", food);
            printf("步数: %d\n", steps);
            continue;
        }
        
        // 保存旧位置
        int old_row = player_row;
        int old_col = player_col;
        
        // 根据输入移动玩家
        switch (input) {
            case 'w': player_row--; break;
            case 's': player_row++; break;
            case 'a': player_col--; break;
            case 'd': player_col++; break;
            default: 
                printf("无效输入! 使用 w, a, s, d 移动\n");
                continue;
        }
        
        // 边界检查
        if (player_row < 0) player_row = 0;
        if (player_row >= MAP_SIZE) player_row = MAP_SIZE - 1;
        if (player_col < 0) player_col = 0;
        if (player_col >= MAP_SIZE) player_col = MAP_SIZE - 1;
        
        // 如果位置发生变化，更新步数和资源
        if (player_row != old_row || player_col != old_col) {
            steps++;
            water -= 1;
            food -= 1;
        }
    }
    
    printf("\n感谢游玩荒岛求生！\n");
    printf("你生存了 %d 步\n", steps);
    
    return 0;
}