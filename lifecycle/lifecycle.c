#include "lifecycle.h"

// 生成Windows环境下的随机数
int win_time_rand(int min, int max) {
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    srand((unsigned int)(counter.QuadPart & 0xFFFFFFFF));
    return min + rand() % (max - min + 1);
}

// 基础生命计数
void life(LifeState* state) {
    if (state) state->cycleTimes++;
}

// 健康状态维护
void maintain(LifeState* state) {
    if (state) state->healthStatus++;
}

// 进食行为
void eat(LifeState* state) {
    if (state) state->foodEnergy++;
}

// 睡眠行为
void sleep(LifeState* state) {
    if (state) state->bedTime++;
}

// 呼吸行为
void breath(LifeState* state) {
    if (state) state->airQuality++;
}

// 饮水行为
void drink(LifeState* state) {
    if (state) state->waterVolume++;
}

// 排泄行为
void excretion(LifeState* state) {
    if (state) state->toiletPlace++;
}

// 保暖行为
void warm(LifeState* state) {
    if (state) state->clothingEnvironment++;
}

// 打印当前状态
void print_state(const LifeState* state) {
    if (!state) return;
    
    printf("\n=== 当前状态 ===\n");
    printf("生命周期计数: %d\n", state->cycleTimes);
    printf("健康状态: %d\n", state->healthStatus);
    printf("进食能量: %d\n", state->foodEnergy);
    printf("睡眠时长: %d\n", state->bedTime);
    printf("空气质量: %d\n", state->airQuality);
    printf("饮水量: %d\n", state->waterVolume);
    printf("卫生状况: %d\n", state->toiletPlace);
    printf("保暖指数: %d\n\n", state->clothingEnvironment);
}

// 打印菜单选项
void print_menu(void) {
    printf("\n今日活动选项:\n");
    printf("1. 睡眠\n");
    printf("2. 进食\n");
    printf("3. 呼吸\n");
    printf("4. 饮水\n");
    printf("5. 排泄\n");
    printf("6. 保暖\n");
    printf(">>> 请选择(1-6): ");
}