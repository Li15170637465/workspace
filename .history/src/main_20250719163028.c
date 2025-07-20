#include<stdio.h>
#include<windows.h>
#include<time.h>
int main(){
    while(1){
        time_t currentTime;
        time(&currentTime);
        printf("current:%s ",c(time));
        printf("Enter a number:\n");
        int a;
        scanf("%d", &a);
        printf("a=%d\n", a);
        sleep("3000");
        return 0;
    }
}