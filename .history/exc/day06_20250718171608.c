#include <stdio.h>
void(double x, double y){
    int max = 0;
    if (x > y)
    {
        max = x;
    }else{
        max = y;
    }
    return max;
}

int main(){
    printf("Enter two numbers:\n");
    double a, b;
    printf("Enter first number: \n");
    scanf("%lf", &a);
    printf("Enter second number: \n");
    scanf("%lf", &b);
    double max=max(a,b);
    printf("The maximum of %.2lf and %.2lf is %.2lf\n", a, b, max);
    return 0;
    }