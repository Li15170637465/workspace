// 1. 有一堆桃子,猴子第一天吃了其中的一半,并多吃一个。以后每天猴子都吃其中的一半,然后再多吃一个。当到第十天时,想再吃时（注意：此时还没吃）,发现只有1个桃子了。问最初共多少个桃子 递归
// #include <stdio.h>

// int peach(int day) {
//     if (day == 10)  
//         return 1;
//     else
//         return (peach(day + 1) + 1) * 2; // 根据后一天的桃子数计算当天的桃子数
// }

// int main() {
//     int total = peach(1); // 计算第1天吃之前的桃子总数
//     printf("最初的桃子总数为: %d\n", total);
//     return 0;
// }

// 2. 数组求和
// 描述：递归计算整型数组所有元素之和。
// // 示例：输入数组 {1, 2, 3, 4},输出 100.
// #include <stdio.h>

// // 递归计算数组元素之和
// int arraySum(int arr[], int start, int end) {
//     if (start > end) {  // 递归终止条件：处理完所有元素
//         return 0;
//     }
//     // 递归分解：当前元素 + 剩余元素之和
//     return arr[start] + arraySum(arr, start + 1, end);
// }

// int main() {
//     int arr[] = {1, 2, 3, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);  // 计算数组长度
    
//     int total = arraySum(arr, 0, n - 1);  // 从索引0开始求和
    
//     printf("数组元素之和: %d\n", total);  // 输出结果
//     return 0;
// }
 


// 3 定义函数,实现交换两个变量的值； 函数原型 void exchange(int *, int *)
