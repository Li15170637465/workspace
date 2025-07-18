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
    int choice = 0;

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




    while (1)
    {
        time_t now;
        time(&now);
        printf("current time:%s\n", ctime(&now));
        Sleep(1000);

        printf("Today Plan\n");
        printf("1.sleep\n");
        printf("2.eat\n");
        printf("3.breath\n");
        printf("4.drink\n");
        printf("5.excretion\n");
        printf("6.warm\n");

        scanf("%d", &choice);

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
            while (choice != 1  choice != 2 || choice != 3 || choice != 4 || choice != 5 || choice != 6)
            {
                printf("Today Plan\n");
                printf("1.sleep\n");
                printf("2.eat\n");
                printf("3.breath\n");
                printf("4.drink\n");
                printf("5.excretion\n");
                printf("6.warm\n");
                scanf("%d", &choice);
                if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
            }
        }

        printf("cycleTimes%d:\n", cycleTimes);
        printf("healthStatus%d:\n", healthStatus);
        printf("foodEnergy:%d\n", foodEnergy);
        printf("bedTime:%d\n", bedTime);
        printf("airQuality:%d\n", airQuality);
        printf("waterVolume:%d\n", waterVolume);
        printf("toiletPlace:%d\n", toiletPlace);
        printf("clothingEnvironment:%d\n", clothingEnvironment);

}
return 0;
}