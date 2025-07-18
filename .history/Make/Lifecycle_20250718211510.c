#include <stdio.h>
#include <time.h>
#include <windows.h>

int cycleTimes = 0;
int healthStatus = 0;
int bedTime = 0;
int foodEnergy = 0;
int waterVolume = 0;
int toiletPlace = 0;
int airQuality = 0;
int clothingEnvironment = 0;

void life(int cycleTimes)
{
    cycleTimes++;
    printf("cycleTimes:\n");
    // return cycleTimes;
}
void maintain(int healthStatus)
{
    healthStatus++;
    printf("healthStatus:\n");
    // return healthStatus;
}
void eat(int foodEnergy)
{
    foodEnergy++;
    printf("foodEnergy:%d\n");
    // return foodEnergy;
}
void sleep(int bedTime)
{
    bedTime++;
    printf("bedTime:%d\n");
    // return bedTime;
}
void breath(int airQuality)
{
    airQuality++;
    printf("airQuality:%d\n");
    // return airQuality;
}
void drink(int waterVolume)
{
    waterVolume++;
    printf("waterVolume:%d\n");
    // return waterVolume;
}
void excretion(int toiletPlace)
{
    toiletPlace++;
    printf("toiletPlace:%d\n");
    // return toiletPlace;
}
void warm(int clothingEnvironment)
{
    clothingEnvironment++;
    printf("warEnvironment:%d\n");
    // return clothingEnvironment;
}



