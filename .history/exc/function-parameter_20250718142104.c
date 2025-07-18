#include<stdio.h>
//函数参数
// int add(int a, int b) {
//     return a + b;
// }

void printcharArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
// This function adds two integers and returns the result.

int main() {

    // int x = 5, y = 10;
    // int result = add(x, y);
    // printf("The sum of %d and %d is %d\n", x, y, result);
    // return 0;

    char arr[] = "{'H', 'e', 'l', 'l', 'o'}";
    int size = sizeof(arr) / sizeof(arr[0]);
    printcharArray(arr, size);
    return 0;

}
// This code defines a simple function to add two integers and prints the result.
    
