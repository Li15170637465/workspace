// // 1. 定义函数，实现交换两个变量的值； 函数原型 void exchange(int *, int *)
// #include<stdio.h>
// void exchange(int *ptr1,int *ptr2)
// {
//     int num1 = *ptr1;
//     int num2 = *ptr2;
//     printf("%d,%d", num2, num1);
// }

// int main(){
//     int nums[] = {0,1};
//     int *ptr1 = &nums[0];
//     int *ptr2 = &nums[1];
//     // int *ptrarr[2] = {ptr1, ptr2};
//     // exchange(ptrarr[0], ptrarr[1]);
//     exchange(ptr1, ptr2);
//     // printf("%p,%p", ptrarr[0], ptrarr[1]);
//     return 0;
// }
// 2. 定义一个函数，接收数组名或首元素指针 和 数组长度 作为参数，计算数组的平均数
//    函数原型： int get_avg(int *, int);
// #include<stdio.h>
// int get_avg(int *arr,int size){
//     int avg=0;
//     for (int i = 0; i < size; i++)
//     {
//         avg += arr[i];
//     }
//         printf("%d\n", avg);
// }

// int main(){
//     int arr[5] = {1, 2, 3, 4, 5};
//     get_avg(&arr[0], 5);
//     return 0;
// }
// 3. 定义函数，接收一个字符串和字符，统计字符在字符串中出现的次数
//    函数原型: int char_count(char *, char)
   
// #include<stdio.h>
// #include<string.h>
//  int char_count(char *str, char ch){
//      int count = 0;
//      while(*str!='\0'){
//         if(*str==ch){
//          count++;
//         }
//      str++;
//      }
//      return count;
//  }

//  int main(){
//      char text[100];
//      char target;
//      printf("Enter a words\n");
//      scanf("%99s", text);
//      printf("Enter a letter\n");
//      scanf(" %c", &target);
//      int count = char_count(text, target);
//      printf("the count of target letter %c is %d times", target, count);

//      return 0;
//  }

// 4. 定义函数，返回某个字符在字符串中第一次出现的位置	   
//    函数原型: int firstIndex(char *, char)
   #include<stdio.h>

   int firstIndex(char *str, char ch){
       int count;
       while (*str != '\0')
       {
           if (*str != ch)
           {
               count++;
           }else{
               str += count;
           }
       }
       return str;
   }

   int main(){
       char text[100];
       char target;
       printf("Enter a string\n");
       scanf("%99s", text);
       printf("Enter the letter\n");
       scanf("%c", &target);
       int =
   }
// 5. 定义函数，返回某个字符在字符串中最后一次出现的位置  
//    函数原型: int lastIndex(char *, char)
  
// 6. 定义函数 实现字符串中小写字母转大写字母； 	
//    函数原型: char *upperCase(char *)
   
// 7. 定义函数 实现字符串中大写字母转小写字母；    
//    函数原型: char *lowerCase(char *)
   
