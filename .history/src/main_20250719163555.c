#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
int main(){
    
    int a;
    scanf("%d", &a);
    printf("a=%d\n", a);
    while(1){
        time_t currentTime;
        time(&currentTime);
        printf("current:%s\n",ctime(&currentTime));
        Sleep("3000");
    }
    return 0;
}