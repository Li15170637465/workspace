#include<stdio.h>
//函数参数
// int add(int a, int b) {
//     return a + b;
// }
// void printcharArray(char arr[], int size){
//     for (int i =0; i < size; i++){
//         printf("%c ", arr[i]);
//     }
// }
// void printcharArray(char arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%c ", arr[i]);
//     }
//     printf("%p", arr);
//     printf("\n");
// }
// This function adds two integers and returns the result.

// int main() {

//     // int x = 5, y = 10;
//     // int result = add(x, y);
//     // printf("The sum of %d and %d is %d\n", x, y, result);
//     // return 0;

//     char arr[] = "Hello";
//     int size = sizeof(arr) / sizeof(arr[0]);
//     printf("The characters in the array are:\n");
//     printf("Size of the array: %d\n", size);
//     printcharArray(arr, size);
//     printf("%p", arr);

//     return 0;

// }
// This code defines a simple function to add two integers and prints the result.
    
#include <stdio.h>

void printcharArray(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}

int main(int argc, char const *argv[])
{   
    int nums=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &nums);
    int arr[nums];
    if(nums <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }
    printf("Choose enter way:\n");
    printf("1. Enter elements one by one\n");
    printf("2. Enter elements in a single line\n");
    int choice;
    scanf("%d", &choice);
    if(choice == 1) {
        printf("Enter %d integers separated by spaces: ", nums);
    for(int i=0; i<nums; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Enter %d integers:\n", nums);
    printcharArray(arr, nums);
    
    return 0;
}
