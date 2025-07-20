#include<stdio.h>
#include<windows.h>

int main(){
    printf("Enter a number:\n");
    int a;
    scanf("%d", &a);
    printf("a=%d\n", a);
    delay("3000");
    return 0;
}