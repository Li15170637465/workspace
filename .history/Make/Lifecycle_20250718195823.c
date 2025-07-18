#include<stdio.h>
#include<time.h>
#include<windows.h>

void eat(int foodPower){
    
}

void sleep(int bedTime){

}

void breath(int airtimes){

}

void drink(int watervolume){

}

void excretion(int toilet){

}

void warm(int clothing){

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
        int choice;
        scanf("%d", &choice);
        while(choice!=1||choice!=2){
            printf("DO\n");
        printf("1.sleep\n");
        printf("2.eat\n");
        scanf("%d", &choice);
        }
        if(choice==1){
            sleep()
        }
    }

    for (int i = 0; i < 100;i++){
        printf("")
    }
}