//1.1. 定义函数,实现求两个double数字的最大值,并返回。
// #include <stdio.h>
// void max(double x, double y){
//     int max = 0;
//     if (x > y)
//     {
//         max = x;
//     }else{
//         max = y;
//     }
//     printf("The maximum of %.2lf and %.2lf is %.2lf\n", x, y, max);
// }

// int main(){
//     printf("Enter two numbers:\n");
//     double a, b;
//     printf("Enter first number: \n");
//     scanf("%lf", &a);
//     printf("Enter second number: \n");
//     scanf("%lf", &b);
//     max(a,b);
//     return 0;
//     }
// 2. 定义函数,求出三个int 类型数的和,并返回。
#include <stdio.h>
int sum(int arr, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum+=arr
    }
}
int main(){
    printf("Enter array size:\n");
    int n;
    scanf("%d,&n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter integer %d: \n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n");


    // 3. 定义函数,判断一个数字是否是质数,返回bool类型。
    // 4. 定义函数,传入数组和数组长度,返回数组中所有元素之和
    // 5. 定义函数,传入一个年份,判断是否是闰年,返回bool类型
