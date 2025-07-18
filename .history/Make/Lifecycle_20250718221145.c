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
    // printf("cycleTimes:\n");
    // return cycleTimes;
}
void maintain(int healthStatus)
{
    healthStatus++;
    // printf("healthStatus:\n");
    // return healthStatus;
}
void eat(int foodEnergy)
{
    foodEnergy++;
    // printf("foodEnergy:%d\n");
    // return foodEnergy;
}
void sleep(int bedTime)
{
    bedTime++;
    // printf("bedTime:%d\n");
    // return bedTime;
}
void breath(int airQuality)
{
    airQuality++;
    // printf("airQuality:%d\n");
    // return airQuality;
}
void drink(int waterVolume)
{
    waterVolume++;
    // printf("waterVolume:%d\n");
    // return waterVolume;
}
void excretion(int toiletPlace)
{
    toiletPlace++;
    // printf("toiletPlace:%d\n");
    // return toiletPlace;
}
void warm(int clothingEnvironment)
{
    clothingEnvironment++;
    // printf("warEnvironment:%d\n");
    // return clothingEnvironment;
}

int main()
{
    while (1)
    {
        time_t now;
        time(&now);
        printf("current time:%s\n", ctime(&now));
        Sleep(3000);

        printf("Today Plan\n");
        printf("1.sleep\n");
        printf("2.eat\n");
        printf("3.breath\n");
        printf("4.drink\n");
        printf("5.excretion\n");
        printf("6.warm\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            sleep(bedTime);
        }
        else if (choice == 2)
        {
            eat(foodEnergy);
        }
        else if (choice == 3)
        {
            breath(airQuality);
        }
        else if (choice == 4)
        {
            drink(waterVolume);
        }
        else if (choice == 5)
        {
            excretion(toiletPlace);
        }
        else if (choice == 6)
        {
            warm(clothingEnvironment);
        }
        else
        {
            while (choice != 1 || choice != 2 || choice != 3 || choice != 4 || choice != 5 || choice != 6)
            {
                printf("Today Plan\n");
                printf("1.sleep\n");
                printf("2.eat\n");
                printf("3.breath\n");
                printf("4.drink\n");
                printf("5.excretion\n");
                printf("6.warm\n");
                scanf("%d", &choice);
            }
        }
    }
    
    printf("cycleTimes%d:\n",cycleTimes);
    printf("healthStatus%d:\n",healthStatus);
    printf("foodEnergy:%d\n",foodEnergy);
    printf("bedTime:%d\n");
    printf("airQuality:%d\n");
    printf("waterVolume:%d\n");
    printf("toiletPlace:%d\n");
    printf("warEnvironment:%d\n");


    // for (int i = 0; i < 100; i++)
    // {
    //     printf("")
    // }
}
