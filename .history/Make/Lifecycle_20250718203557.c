#include<stdio.h>
#include<time.h>
#include<windows.h>

int life=100;
int health=100;
int bedTime=0;
int foodEnergy=0;
int waterVolume=0;
int toiletPlace=0;
int airQuality=0;

void eat(int foodEnergy){
    foodEnergy++;
    printf("foodEnergy:%d\n");
    return foodEnergy;
}
void sleep(int bedTime){
    bedTime++;
    printf("bedTime:%d\n");
    return bedTime;
}
void breath(int airQuality){
    airQuality++;
    printf("airQuality:%d\n");
    return airQuality;
}
void drink(int waterVolume){
    waterVolume++;
    printf("waterVolume:%d\n");
    return waterVolume;
}
void excretion(int toiletPlace){
    toiletPlace++;
    printf("toiletPlace:%d\n");
    return toiletPlace;
}
void warm(int warmEnvironment){
    warmEnvironment++;
    printf("warEnvironment:%d\n");
    return warmEnvironment;
}

int main(){
    while(1){
        time_t now;
        time(&now);
        printf("current time:%s\n", time(&now));
        Sleep(3000);
        printf("Today Plan\n");
        printf("1.sleep\n");
        printf("2.eat\n");
        pintf("3.breath\n");
        printf("4.drink\n");
        printf("5.excretion\n");
        printf("6.warm\n");
        int choice;
        scanf("%d", &choice);

        while(choice!=1||choice!=2||choice!=3||choice!=4||choice!=5||choice!=6)
        {
        printf("Today Plan\n");
        printf("1.sleep\n");
        printf("2.eat\n");
        pintf("3.breath\n");
        printf("4.drink\n");
        printf("5.excretion\n");
        printf("6.warm\n");
        scanf("%d", &choice);
        }

        if(choice==1){
            sleep(bedTime);
        }else if(choice==2){
            eat(foodEnergy);
        }else if(choice==3){
            breath(airQuality);
        }else if(choice==4){
            drink(waterVolume);
        }else if(choice==5){
            excretion(toiletPlace)
        }
    }

    for (int i = 0; i < 100;i++){
        printf("")
    }
}