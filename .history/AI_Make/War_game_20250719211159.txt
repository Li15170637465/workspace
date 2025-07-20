#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_UNITS 10
#define MAX_SAVES 3

typedef enum {
    INFANTRY, // 步兵
    ARCHER,   // 弓箭手
    CAVALRY,  // 骑兵
    ARTILLERY // 炮兵
} UnitType;

typedef struct {
    int x, y;
    int health;
    int attack;
    int defense;
    int range;
    int mobility;
    UnitType type;
    int player; // 0:玩家, 1:电脑
} Unit;

typedef struct {
    Unit units[MAX_UNITS];
    int unitCount;
    int currentPlayer;
    int turn;
    char playerName[20];
} GameState;

// 游戏地图
char map[MAP_HEIGHT][MAP_WIDTH];

// 全局游戏状态
GameState game;

// 存档系统
GameState saves[MAX_SAVES];
int saveCount = 0;

// 初始化地图
void initMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            // 创建一些地形变化
            if ((x + y) % 7 == 0) {
                map[y][x] = '^'; // 山
            } else if ((x * y) % 11 == 0) {
                map[y][x] = '~'; // 水
            } else {
                map[y][x] = '.'; // 平地
            }
        }
    }
}

// 初始化游戏
void initGame() {
    game.unitCount = 0;
    game.currentPlayer = 0; // 玩家先手
    game.turn = 1;
    strcpy(game.playerName, "Commander");
    
    // 添加玩家单位
    game.units[game.unitCount++] = (Unit){2, 2, 100, 20, 5, 1, 3, INFANTRY, 0};
    game.units[game.unitCount++] = (Unit){5, 3, 70, 30, 3, 4, 2, ARCHER, 0};
    game.units[game.unitCount++] = (Unit){3, 5, 120, 25, 8, 1, 4, CAVALRY, 0};
    
    // 添加电脑单位
    game.units[game.unitCount++] = (Unit){15, 2, 100, 20, 5, 1, 3, INFANTRY, 1};
    game.units[game.unitCount++] = (Unit){12, 3, 70, 30, 3, 4, 2, ARCHER, 1};
    game.units[game.unitCount++] = (Unit){14, 5, 120, 25, 8, 1, 4, CAVALRY, 1};
    
    initMap();
}

// 绘制游戏地图
void drawMap() {
    system("cls"); // 清屏
    
    printf("===== 回合制战争模拟游戏 =====\n");
    printf("玩家: %s  回合: %d\n\n", game.playerName, game.turn);
    
    // 绘制地图顶部坐标
    printf("   ");
    for (int x = 0; x < MAP_WIDTH; x++) {
        printf("%2d", x);
    }
    printf("\n");
    
    for (int y = 0; y < MAP_HEIGHT; y++) {
        // 绘制左侧坐标
        printf("%2d ", y);
        
        for (int x = 0; x < MAP_WIDTH; x++) {
            char tile = map[y][x];
            char unitChar = ' ';
            
            // 检查当前位置是否有单位
            for (int i = 0; i < game.unitCount; i++) {
                Unit u = game.units[i];
                if (u.x == x && u.y == y && u.health > 0) {
                    switch (u.type) {
                        case INFANTRY: unitChar = (u.player == 0) ? 'I' : 'i'; break;
                        case ARCHER: unitChar = (u.player == 0) ? 'A' : 'a'; break;
                        case CAVALRY: unitChar = (u.player == 0) ? 'C' : 'c'; break;
                        case ARTILLERY: unitChar = (u.player == 0) ? 'R' : 'r'; break;
                    }
                    break;
                }
            }
            
            if (unitChar != ' ') {
                printf("%c ", unitChar);
            } else {
                printf("%c ", tile);
            }
        }
        printf("\n");
    }
    
    printf("\n图例: I-步兵  A-弓箭手  C-骑兵  R-炮兵\n");
    printf("大写: 玩家单位  小写: 电脑单位\n");
    printf("地形: .-平地  ^-山地  ~-水域\n");
}

// 显示单位信息
void showUnitInfo(int unitIndex) {
    if (unitIndex < 0 || unitIndex >= game.unitCount) return;
    
    Unit u = game.units[unitIndex];
    const char* typeName;
    
    switch (u.type) {
        case INFANTRY: typeName = "步兵"; break;
        case ARCHER: typeName = "弓箭手"; break;
        case CAVALRY: typeName = "骑兵"; break;
        case ARTILLERY: typeName = "炮兵"; break;
    }
    
    printf("\n=== 单位信息 ===\n");
    printf("类型: %s\n", typeName);
    printf("位置: (%d, %d)\n", u.x, u.y);
    printf("生命值: %d\n", u.health);
    printf("攻击力: %d\n", u.attack);
    printf("防御力: %d\n", u.defense);
    printf("攻击范围: %d\n", u.range);
    printf("移动力: %d\n", u.mobility);
    printf("所属: %s\n", u.player == 0 ? "玩家" : "电脑");
}

// 显示所有单位状态
void showAllUnits() {
    printf("\n=== 单位状态 ===\n");
    for (int i = 0; i < game.unitCount; i++) {
        Unit u = game.units[i];
        if (u.health <= 0) continue;
        
        const char* typeName;
        switch (u.type) {
            case INFANTRY: typeName = "步兵"; break;
            case ARCHER: typeName = "弓箭手"; break;
            case CAVALRY: typeName = "骑兵"; break;
            case ARTILLERY: typeName = "炮兵"; break;
        }
        
        printf("%s%d: %s(%d,%d) HP:%d/%d\n", 
               u.player == 0 ? "友方" : "敌方",
               i, typeName, u.x, u.y, u.health, 
               (u.type == INFANTRY) ? 100 : 
               (u.type == ARCHER) ? 70 : 
               (u.type == CAVALRY) ? 120 : 90);
    }
}

// 移动单位
void moveUnit(int unitIndex, int newX, int newY) {
    if (unitIndex < 0 || unitIndex >= game.unitCount) return;
    
    Unit* u = &game.units[unitIndex];
    
    // 检查位置是否有效
    if (newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT) {
        printf("无效的位置!\n");
        return;
    }
    
    // 检查地形是否可通行
    char tile = map[newY][newX];
    if (tile == '~') {
        printf("无法移动到水域!\n");
        return;
    }
    
    // 检查目标位置是否已被占用
    for (int i = 0; i < game.unitCount; i++) {
        Unit other = game.units[i];
        if (other.x == newX && other.y == newY && other.health > 0) {
            printf("目标位置已被占用!\n");
            return;
        }
    }
    
    // 计算移动距离
    int distance = abs(u->x - newX) + abs(u->y - newY);
    
    if (distance <= u->mobility) {
        u->x = newX;
        u->y = newY;
        printf("单位已移动到 (%d, %d)\n", newX, newY);
    } else {
        printf("超出移动范围! 最大移动距离: %d\n", u->mobility);
    }
}

// 攻击单位
void attackUnit(int attackerIndex, int targetIndex) {
    if (attackerIndex < 0 || attackerIndex >= game.unitCount || 
        targetIndex < 0 || targetIndex >= game.unitCount) {
        return;
    }
    
    Unit* attacker = &game.units[attackerIndex];
    Unit* target = &game.units[targetIndex];
    
    // 检查是否可以对目标进行攻击
    if (attacker->player == target->player) {
        printf("不能攻击友方单位!\n");
        return;
    }
    
    // 检查攻击距离
    int distance = abs(attacker->x - target->x) + abs(attacker->y - target->y);
    if (distance > attacker->range) {
        printf("超出攻击范围! 需要距离: %d, 实际距离: %d\n", attacker->range, distance);
        return;
    }
    
    // 计算伤害
    int damage = attacker->attack - target->defense;
    if (damage < 5) damage = 5; // 最小伤害
    
    // 地形影响
    char tile = map[target->y][target->x];
    if (tile == '^') {
        damage = (int)(damage * 0.7); // 山地减少30%伤害
    } else if (tile == '~') {
        damage = (int)(damage * 1.2); // 水域增加20%伤害
    }
    
    target->health -= damage;
    
    printf("%s单位对%s单位造成 %d 点伤害!\n",
           attacker->player == 0 ? "玩家" : "电脑",
           target->player == 0 ? "玩家" : "电脑",
           damage);
    
    if (target->health <= 0) {
        printf("%s单位被消灭!\n", target->player == 0 ? "玩家" : "电脑");
    }
}

// 检查游戏是否结束
int checkGameOver() {
    int playerUnits = 0;
    int computerUnits = 0;
    
    for (int i = 0; i < game.unitCount; i++) {
        if (game.units[i].health > 0) {
            if (game.units[i].player == 0) {
                playerUnits++;
            } else {
                computerUnits++;
            }
        }
    }
    
    if (playerUnits == 0) {
        printf("所有单位被消灭! 电脑获胜!\n");
        return 1;
    }
    
    if (computerUnits == 0) {
        printf("所有敌方单位被消灭! %s获胜!\n", game.playerName);
        return 1;
    }
    
    return 0;
}

// 电脑AI
void computerTurn() {
    printf("\n=== 电脑回合 ===\n");
    
    // 简单的AI: 移动并攻击最近的玩家单位
    for (int i = 0; i < game.unitCount; i++) {
        Unit* computerUnit = &game.units[i];
        
        if (computerUnit->player != 1 || computerUnit->health <= 0) {
            continue;
        }
        
        // 寻找最近的玩家单位
        int closestDistance = 1000;
        int targetIndex = -1;
        
        for (int j = 0; j < game.unitCount; j++) {
            Unit* playerUnit = &game.units[j];
            
            if (playerUnit->player == 0 && playerUnit->health > 0) {
                int distance = abs(computerUnit->x - playerUnit->x) + 
                               abs(computerUnit->y - playerUnit->y);
                
                if (distance < closestDistance) {
                    closestDistance = distance;
                    targetIndex = j;
                }
            }
        }
        
        if (targetIndex == -1) continue;
        
        Unit* target = &game.units[targetIndex];
        
        // 尝试移动到目标附近
        int bestX = computerUnit->x;
        int bestY = computerUnit->y;
        int bestDistance = closestDistance;
        
        // 简单的移动逻辑: 尝试四个方向
        int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (int d = 0; d < 4; d++) {
            int newX = computerUnit->x + directions[d][0];
            int newY = computerUnit->y + directions[d][1];
            
            // 检查位置是否有效
            if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT) {
                // 检查位置是否空闲
                int positionFree = 1;
                for (int u = 0; u < game.unitCount; u++) {
                    if (game.units[u].x == newX && game.units[u].y == newY && 
                        game.units[u].health > 0) {
                        positionFree = 0;
                        break;
                    }
                }
                
                if (positionFree) {
                    int newDistance = abs(newX - target->x) + abs(newY - target->y);
                    if (newDistance < bestDistance) {
                        bestDistance = newDistance;
                        bestX = newX;
                        bestY = newY;
                    }
                }
            }
        }
        
        // 移动单位
        if (bestX != computerUnit->x || bestY != computerUnit->y) {
            computerUnit->x = bestX;
            computerUnit->y = bestY;
            printf("电脑单位移动到 (%d, %d)\n", bestX, bestY);
        }
        
        // 检查是否可以攻击
        int distance = abs(computerUnit->x - target->x) + 
                      abs(computerUnit->y - target->y);
        
        if (distance <= computerUnit->range) {
            attackUnit(i, targetIndex);
        }
    }
    
    game.currentPlayer = 0; // 切换回玩家
    game.turn++;
}

// 保存游戏
void saveGame() {
    if (saveCount >= MAX_SAVES) {
        printf("存档位已满!\n");
        return;
    }
    
    saves[saveCount] = game;
    saveCount++;
    printf("游戏已保存到存档位 %d\n", saveCount);
}

// 加载游戏
void loadGame(int slot) {
    if (slot < 1 || slot > saveCount) {
        printf("无效的存档位!\n");
        return;
    }
    
    game = saves[slot-1];
    printf("已加载存档 %d\n", slot);
}

// 显示主菜单
void showMainMenu() {
    system("cls");
    printf("===== 回合制战争模拟游戏 =====\n");
    printf("1. 开始新游戏\n");
    printf("2. 加载游戏\n");
    printf("3. 退出游戏\n");
    printf("==============================\n");
    printf("请选择: ");
}

// 显示游戏菜单
void showGameMenu() {
    printf("\n=== 游戏菜单 ===\n");
    printf("1. 移动单位\n");
    printf("2. 攻击单位\n");
    printf("3. 查看单位信息\n");
    printf("4. 显示所有单位\n");
    printf("5. 结束回合\n");
    printf("6. 保存游戏\n");
    printf("7. 返回主菜单\n");
    printf("===============\n");
    printf("请选择: ");
}

// 主游戏循环
void playGame() {
    while (1) {
        drawMap();
        
        if (game.currentPlayer == 1) {
            computerTurn();
            if (checkGameOver()) {
                printf("按任意键返回主菜单...");
                getch();
                break;
            }
            continue;
        }
        
        showGameMenu();
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: { // 移动单位
                showAllUnits();
                printf("选择要移动的单位编号: ");
                int unitIndex;
                scanf("%d", &unitIndex);
                
                if (unitIndex < 0 || unitIndex >= game.unitCount || 
                    game.units[unitIndex].player != 0 || 
                    game.units[unitIndex].health <= 0) {
                    printf("无效的单位选择!\n");
                    break;
                }
                
                printf("输入目标坐标 (x y): ");
                int x, y;
                scanf("%d %d", &x, &y);
                
                moveUnit(unitIndex, x, y);
                break;
            }
            
            case 2: { // 攻击单位
                showAllUnits();
                printf("选择攻击单位编号: ");
                int attackerIndex;
                scanf("%d", &attackerIndex);
                
                if (attackerIndex < 0 || attackerIndex >= game.unitCount || 
                    game.units[attackerIndex].player != 0 || 
                    game.units[attackerIndex].health <= 0) {
                    printf("无效的攻击单位选择!\n");
                    break;
                }
                
                printf("选择目标单位编号: ");
                int targetIndex;
                scanf("%d", &targetIndex);
                
                if (targetIndex < 0 || targetIndex >= game.unitCount || 
                    game.units[targetIndex].health <= 0) {
                    printf("无效的目标单位选择!\n");
                    break;
                }
                
                attackUnit(attackerIndex, targetIndex);
                break;
            }
            
            case 3: { // 查看单位信息
                showAllUnits();
                printf("选择要查看的单位编号: ");
                int unitIndex;
                scanf("%d", &unitIndex);
                
                if (unitIndex < 0 || unitIndex >= game.unitCount || 
                    game.units[unitIndex].health <= 0) {
                    printf("无效的单位选择!\n");
                    break;
                }
                
                showUnitInfo(unitIndex);
                printf("按任意键继续...");
                getch();
                break;
            }
            
            case 4: // 显示所有单位
                showAllUnits();
                printf("按任意键继续...");
                getch();
                break;
                
            case 5: // 结束回合
                game.currentPlayer = 1; // 切换到电脑
                break;
                
            case 6: // 保存游戏
                saveGame();
                break;
                
            case 7: // 返回主菜单
                return;
                
            default:
                printf("无效的选择!\n");
        }
        
        // 检查游戏是否结束
        if (checkGameOver()) {
            printf("按任意键返回主菜单...");
            getch();
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    
    while (1) {
        showMainMenu();
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // 开始新游戏
                initGame();
                playGame();
                break;
                
            case 2: // 加载游戏
                if (saveCount == 0) {
                    printf("没有可用的存档!\n");
                    printf("按任意键继续...");
                    getch();
                    break;
                }
                
                printf("可用的存档位 (1-%d): ", saveCount);
                int slot;
                scanf("%d", &slot);
                loadGame(slot);
                printf("按任意键开始游戏...");
                getch();
                playGame();
                break;
                
            case 3: // 退出游戏
                return 0;
                
            default:
                printf("无效的选择!\n");
        }
    }
    
    return 0;
}