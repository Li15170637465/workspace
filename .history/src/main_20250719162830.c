#include<stdio.h>
#include<windows.h>
#include<time.h>
int main(){
    while(1){
    printf("Enter a number:\n");
    int a;
    scanf("%d", &a);
    printf("a=%d\n", a);
    delay("3000");
    return 0;
    }
}