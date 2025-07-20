#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

// 生命周期状态结构体
typedef struct {
    int cycleTimes;
    int healthStatus;
    int bedTime;
    int foodEnergy;
    int waterVolume;
    int toiletPlace;
    int airQuality;
    int clothingEnvironment;
} LifeState;

// 函数声明
int win_time_rand(int min, int max);
void life(LifeState* state);
void maintain(LifeState* state);
void eat(LifeState* state);
void sleep(LifeState* state);
void breath(LifeState* state);
void drink(LifeState* state);
void excretion(LifeState* state);
void warm(LifeState* state);
void print_state(const LifeState* state);
void print_menu(void);

#endif // LIFECYCLE_H