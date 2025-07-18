#include<stdio.h>
//函数参数
int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    int result = add(x, y);
    printf("The sum of %d and %d is %d\n", x, y, result);
    return 0;
}
// This code defines a simple function to add two integers and prints the result.
