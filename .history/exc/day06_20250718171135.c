#include <stdio.h>
vodi(double x, double y){
    int max = 0;
    if (x > y)
    {
        max = x;
    }else{
        max = y;
    }
}


int main(){
    printf("Enter two numbers:\n");
    double a, b;
    printf("Enter first number: \n");
    scanf("%lf", &a);
    printf("Enter second number: \n");
    scanf("%lf", &b);