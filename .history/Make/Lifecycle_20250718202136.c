#include<stdio.h>
#include<time.h>
#include<windows.h>
int life;
int health;
int bedTime;
int foodEnergy;
int waterVolume;
int toiletPlace;
int airQuality;

void eat(int foodEnergy){
    return
}

void sleep(int bedTime){

}

void breath(int airQuality){

}

void drink(int waterVolume){

}

void excretion(int toiletPlace){

}

void warm(int warmEnvironment){

}
//第一天
//


int main(){
    while(1){
        time_t now;
        time(&now);
        printf("current time:%s\n", time(&now));
        Sleep(3000);
        printf("DO\n");
        printf("1.sleep\n");
        printf("2.eat\n");
        pintf("3.breath\n");
        printf("4.drink\n");
        printf("5.excretion\n");
        printf("6.warm\n");
        int choice;
        scanf("%d", &choice);
        while(choice!=1||choice!=2||choice!=3||choice!=4||choice!=5||choice!=6){
        printf("DO\n");
        printf("1.sleep\n");
        printf("2.eat\n");
        pintf("3.breath\n");
        printf("4.drink\n");
        printf("5.excretion\n");
        printf("6.warm\n");
        scanf("%d", &choice);
        }
        if(choice==1){
            sleep(bedTime)
        }
    }

    for (int i = 0; i < 100;i++){
        printf("")
    }
}