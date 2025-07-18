#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

    int cycleTimes = 0;
    int healthStatus = 0;
    int bedTime = 0;
    int foodEnergy = 0;
    int waterVolume = 0;
    int toiletPlace = 0;
    int airQuality = 0;
    int clothingEnvironment = 0;
    int choice = 0;

int win_time_rand(int min, int max) {
    LARGE_INTEGER counter;
    
    // 获取高精度性能计数器值
    QueryPerformanceCounter(&counter);
    
    // 使用计数器值作为随机种子
    srand((unsigned int)(counter.QuadPart & 0xFFFFFFFF));
    
    // 生成指定范围内的随机数
    return min + rand() % (max - min + 1);
}

int life(int cycleTimes)
{
    ++cycleTimes;
    // printf("cycleTimes:\n");
    return cycleTimes;
}
int maintain(int healthStatus)
{
    ++healthStatus;
    // printf("healthStatus:\n");
    return healthStatus;
}
int eat(int foodEnergy)
{
    ++foodEnergy;
    // printf("foodEnergy:%d\n");
    return foodEnergy;
}
int sleep(int bedTime)
{
    ++bedTime;
    // printf("bedTime:%d\n");
    return bedTime;
}
int breath(int airQuality)
{
    ++airQuality;
    // printf("airQuality:%d\n");
    return airQuality;
}
int drink(int waterVolume)
{
    ++waterVolume;
    // printf("waterVolume:%d\n");
    return waterVolume;
}
int excretion(int toiletPlace)
{
    ++toiletPlace;
    // printf("toiletPlace:%d\n");
    return toiletPlace;
}
int warm(int clothingEnvironment)
{
    ++clothingEnvironment;
    // printf("warEnvironment:%d\n");
    return clothingEnvironment;
}

int main()
{


        start:
            system("cls");

            time_t now;
            time(&now);
            printf("current time:%s\n", ctime(&now));
            int random_num = win_time_rand(1, 6);
            printf("random number: %d\n", random_num);
            Sleep(1000);

            printf("Today Plan\n");
            printf("1.sleep\n");
            printf("2.eat\n");
            printf("3.breath\n");
            printf("4.drink\n");
            printf("5.excretion\n");
            printf("6.warm\n\n\n");

            choice = random_num;

            // scanf("%d", &choice);

            if (choice == 1)
            {
                sleep(bedTime);
                bedTime = sleep(bedTime);
                cycleTimes = life(cycleTimes);
                healthStatus = maintain(healthStatus);
            }
        else if (choice == 2)
        {
            eat(foodEnergy);
            foodEnergy = eat(foodEnergy);
            cycleTimes = life(cycleTimes);
            healthStatus = maintain(healthStatus);
        }
        else if (choice == 3)
        {
            breath(airQuality);
            airQuality = breath(airQuality);
            cycleTimes = life(cycleTimes);
            healthStatus = maintain(healthStatus);
        }
        else if (choice == 4)
        {
            drink(waterVolume);
            waterVolume = drink(waterVolume);
            cycleTimes = life(cycleTimes);
            healthStatus = maintain(healthStatus);
        }
        else if (choice == 5)
        {
            excretion(toiletPlace);
            toiletPlace = excretion(toiletPlace);
            cycleTimes = life(cycleTimes);
            healthStatus = maintain(healthStatus);
        }
        else if (choice == 6)
        {
            warm(clothingEnvironment);
            clothingEnvironment = warm(clothingEnvironment);
            cycleTimes = life(cycleTimes);
            healthStatus = maintain(healthStatus);
        }
        else
        {
            
            while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
            {
                printf("Today Plan\n");
                printf("1.sleep\n");
                printf("2.eat\n");
                printf("3.breath\n");
                printf("4.drink\n");
                printf("5.excretion\n");
                printf("6.warm\n\n\n");
                scanf("%d", &choice);
                if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
                    break;
            }
        }
        system("cls");
        printf("cycleTimes:%d\n", cycleTimes);
        printf("healthStatus:%d\n", healthStatus);
        printf("foodEnergy:%d\n", foodEnergy);
        printf("bedTime:%d\n", bedTime);
        printf("airQuality:%d\n", airQuality);
        printf("waterVolume:%d\n", waterVolume);
        printf("toiletPlace:%d\n", toiletPlace);
        printf("clothingEnvironment:%d\n\n\n", clothingEnvironment);

        goto start;

        return 0;
}