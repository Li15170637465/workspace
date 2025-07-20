#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
int main(){
    while(1){
        time_t currentTime;
        time(&currentTime);
        printf("current:%s\n",ctime(&currentTime));
        printf("Enter a number:\n");

        Sleep("3000");
    }
    return 0;
}