#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

// 生存核心指标
int vitality = 100;      // 生命值 (0-100)
int hunger = 30;         // 饥饿度 (0-100)
int fatigue = 20;        // 疲劳度 (0-100)
int hydration = 70;      // 水分 (0-100)
int sanitation = 90;     // 清洁度 (0-100)

// 环境状态
int ambientTemp = 25;    // 环境温度 (℃)
int weather = 1;         // 天气 (1:晴 2:雨 3:雪)

// 玩家资源
int foodSupplies = 3;    // 食物存量
int waterSupplies = 5;   // 饮水存量
int firewood = 2;        // 木柴存量

// 游戏进度
int dayCycle = 1;        // 天数
int hour = 8;            // 当前时间 (0-23)
int actions = 0;         // 当日行动次数

// 函数声明
int win_time_rand(int min, int max);
void updateEnvironment();
void hourlyUpdate();
void triggerEvent();
void renderDashboard();
void executeAction(int choice);
void printActions();
void showGameOver();

int main() {
    srand((unsigned int)time(NULL)); // 初始化随机种子
    
    while (vitality > 0) {  // 主游戏循环
        system("cls");  // 清屏
        
        // 更新环境状态
        if (actions % 3 == 0) {
            updateEnvironment();
        }
        
        // 显示游戏状态
        renderDashboard();
        
        // 显示行动菜单
        printActions();
        
        // 获取玩家选择
        int choice;
        printf("\n选择行动: ");
        scanf("%d", &choice);
        
        // 执行行动
        executeAction(choice);
        actions++;
        
        // 时间推进 (每次行动消耗2小时)
        hour = (hour + 2) % 24;
        if (hour < 2) dayCycle++; // 新的一天
        
        // 每小时状态更新
        hourlyUpdate();
        hourlyUpdate(); // 两小时更新两次
        
        // 随机事件触发
        if (rand() % 4 == 0) {
            triggerEvent();
        }
    }
    
    showGameOver();
    return 0;
}

// 高精度随机数生成
int win_time_rand(int min, int max) {
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    srand((unsigned int)(counter.QuadPart & 0xFFFFFFFF));
    return min + rand() % (max - min + 1);
}

// 更新环境状态
void updateEnvironment() {
    // 随机温度变化 (10-35℃)
    ambientTemp = 10 + rand() % 26;
    
    // 随机天气 (30%概率变化)
    if (rand() % 100 < 30) {
        weather = 1 + rand() % 3;
    }
}

// 每小时状态更新
void hourlyUpdate() {
    // 自然消耗
    hunger += 5;
    fatigue += (hour > 22 || hour < 6) ? 3 : 8; // 夜间更易疲劳
    hydration -= 3;
    sanitation -= 2;
    
    // 环境影响
    if (ambientTemp < 10) vitality -= 2;
    if (ambientTemp > 30) hydration -= 5;
    if (weather == 2) ambientTemp -= 5;   // 雨天气温降低
    if (weather == 3) hunger += 3;        // 雪天增加饥饿
    
    // 危险阈值检测
    if (hunger > 90) vitality -= 10;
    if (fatigue > 85) vitality -= 15;
    if (hydration < 20) vitality -= 8;
    if (sanitation < 30) vitality -= 5;
    
    // 确保数值在合理范围
    vitality = vitality > 100 ? 100 : vitality < 0 ? 0 : vitality;
    hunger = hunger > 100 ? 100 : hunger < 0 ? 0 : hunger;
    fatigue = fatigue > 100 ? 100 : fatigue < 0 ? 0 : fatigue;
    hydration = hydration > 100 ? 100 : hydration < 0 ? 0 : hydration;
    sanitation = sanitation > 100 ? 100 : sanitation < 0 ? 0 : sanitation;
}

// 随机事件触发
void triggerEvent() {
    int eventId = rand() % 10;
    printf("\n>>>> 随机事件发生! <<<<\n");
    
    switch (eventId) {
        case 0:
            printf("发现野果丛! 食物+2\n");
            foodSupplies += 2;
            break;
        case 1:
            printf("遭遇暴雨! 体温下降\n");
            ambientTemp -= 8;
            break;
        case 2:
            printf("水源污染! 饮水-1\n");
            waterSupplies = waterSupplies > 0 ? waterSupplies - 1 : 0;
            break;
        case 3:
            printf("野兽袭击! 生命-20\n");
            vitality -= 20;
            break;
        case 4:
            printf("找到干净水源! 水分+30\n");
            hydration += 30;
            break;
        case 5:
            printf("发现废弃小屋! 获得木柴+3\n");
            firewood += 3;
            break;
        case 6:
            printf("食物变质! 食物-1\n");
            foodSupplies = foodSupplies > 0 ? foodSupplies - 1 : 0;
            break;
        case 7:
            printf("温暖阳光! 疲劳-15\n");
            fatigue -= 15;
            break;
        case 8:
            printf("蚊虫叮咬! 健康-10\n");
            vitality -= 10;
            sanitation -= 10;
            break;
        case 9:
            printf("幸运日! 所有资源+1\n");
            foodSupplies++;
            waterSupplies++;
            firewood++;
            break;
    }
    printf(">>>> 事件结束 <<<<\n\n");
    Sleep(2000);
}

// 显示游戏状态
void renderDashboard() {
    char weatherStr[10];
    switch (weather) {
        case 1: strcpy(weatherStr, "晴"); break;
        case 2: strcpy(weatherStr, "雨"); break;
        case 3: strcpy(weatherStr, "雪"); break;
    }
    
    printf("==================== 生存模拟器 ====================\n");
    printf("天数: %d  时间: %02d:00  天气: %s  温度: %d℃\n", 
           dayCycle, hour, weatherStr, ambientTemp);
    printf("---------------------------------------------------\n");
    printf("生命值: %3d/100 ", vitality);
    for (int i = 0; i < vitality/5; i++) printf("♥");
    printf("\n");
    
    printf("饥饿度: %3d/100 ", hunger);
    for (int i = 0; i < hunger/5; i++) printf("=");
    printf("\n");
    
    printf("疲劳度: %3d/100 ", fatigue);
    for (int i = 0; i < fatigue/5; i++) printf("z");
    printf("\n");
    
    printf("水分值: %3d/100 ", hydration);
    for (int i = 0; i < hydration/5; i++) printf("~");
    printf("\n");
    
    printf("清洁度: %3d/100 ", sanitation);
    for (int i = 0; i < sanitation/5; i++) printf("☆");
    printf("\n");
    printf("---------------------------------------------------\n");
    printf("食物: %d  饮水: %d  木柴: %d\n", 
           foodSupplies, waterSupplies, firewood);
    printf("===================================================\n\n");
}

// 显示行动菜单
void printActions() {
    printf("可选择的行动:\n");
    printf(" 1. 进食 (饥饿-25, 食物-1)\n");
    printf(" 2. 饮水 (水分+30, 饮水-1)\n");
    printf(" 3. 休息 (疲劳-40, 时间+2)\n");
    printf(" 4. 收集水源 (饮水+2, 疲劳+15)\n");
    printf(" 5. 收集食物 (食物+1, 疲劳+20)\n");
    printf(" 6. 生火取暖 (体温+10, 木柴-1)\n");
    printf(" 7. 清洁身体 (清洁度+30, 水分-10)\n");
    printf(" 8. 建造庇护所 (需要3木柴, 疲劳+30)\n");
}

// 执行玩家选择的行动
void executeAction(int choice) {
    printf("\n");
    switch (choice) {
        case 1: // 进食
            if (foodSupplies > 0) {
                hunger -= 25;
                foodSupplies--;
                printf("你吃了一些食物，饥饿感减轻了\n");
            } else {
                printf("没有食物了！寻找食物吧\n");
            }
            break;
            
        case 2: // 饮水
            if (waterSupplies > 0) {
                hydration += 30;
                waterSupplies--;
                printf("你喝了些水，感觉好多了\n");
            } else {
                printf("没有饮用水了！寻找水源吧\n");
            }
            break;
            
        case 3: // 休息
            fatigue -= 40;
            printf("你休息了一会儿，精力恢复了\n");
            break;
            
        case 4: // 收集水源
            waterSupplies += 2;
            fatigue += 15;
            printf("你收集了一些饮用水\n");
            break;
            
        case 5: // 收集食物
            foodSupplies++;
            fatigue += 20;
            printf("你找到了一些食物\n");
            break;
            
        case 6: // 生火取暖
            if (firewood > 0) {
                ambientTemp += 10;
                firewood--;
                printf("你生起篝火，感觉温暖多了\n");
            } else {
                printf("没有木柴了！收集木柴吧\n");
            }
            break;
            
        case 7: // 清洁身体
            sanitation += 30;
            hydration -= 10;
            printf("你清洁了身体，感觉清爽多了\n");
            break;
            
        case 8: // 建造庇护所
            if (firewood >= 3) {
                firewood -= 3;
                vitality += 15;
                fatigue += 30;
                printf("你建造了简易庇护所，获得安全感\n");
            } else {
                printf("木柴不足！需要3个木柴\n");
            }
            break;
            
        default:
            printf("无效选择，时间流逝...\n");
            break;
    }
    Sleep(1500);
}

// 游戏结束画面
void showGameOver() {
    system("cls");
    printf("\n\n========================================\n");
    printf("            G A M E   O V E R\n");
    printf("========================================\n");
    printf("    你在荒野中生存了 %d 天\n", dayCycle);
    printf("========================================\n");
    
    if (dayCycle < 3) {
        printf("    生存新手，还需更多历练\n");
    } else if (dayCycle < 7) {
        printf("    不错的生存者！有潜力\n");
    } else if (dayCycle < 14) {
        printf("    生存专家！令人印象深刻\n");
    } else {
        printf("    荒野大师！真正的生存传奇\n");
    }
    
    printf("========================================\n\n");
    system("pause");
}