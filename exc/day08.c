// // 1. ���庯����ʵ�ֽ�������������ֵ�� ����ԭ�� void exchange(int *, int *)
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
// 2. ����һ����������������������Ԫ��ָ�� �� ���鳤�� ��Ϊ���������������ƽ����
//    ����ԭ�ͣ� int get_avg(int *, int);
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
// 3. ���庯��������һ���ַ������ַ���ͳ���ַ����ַ����г��ֵĴ���
//    ����ԭ��: int char_count(char *, char)
   
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

// 4. ���庯��������ĳ���ַ����ַ����е�һ�γ��ֵ�λ��	   
//    ����ԭ��: int firstIndex(char *, char)
//    #include<stdio.h>

//    int firstIndex(char *str, char ch){
//        int count=1;
//        while (*str != '\0')
//        {
//            if (*str != ch)
//            {
//                count++;
//            }else{

//                return count;
//            }
//            str++;
//        }
// }

//    int main(){
//        char text[100];
//        char target;
//        printf("Enter a string\n");
//        scanf("%99s", text);
//        printf("Enter the letter\n");
//        scanf(" %c", &target);
//        int count = firstIndex(text, target);
//        printf("Letter %c is place %d in the string \n", target, count);
//        return 0;
//    }
// 5. ���庯��������ĳ���ַ����ַ��������һ�γ��ֵ�λ��  
//    ����ԭ��: int lastIndex(char *, char)
// #include<stdio.h>
// int lastIndex(char *str, char ch){
//     int len = strlen(str);
//     for (int i = len - 1; i >= 0;i--){
//         if(ch==str[i]){
//             return i;
//         }
//     }
//     return -1;
// }
// int main(){
//     char text[100];
//     char target;
//     printf("Enter a string\n");
//     scanf("%99s", text);
//     printf("Enter the letter\n");
//     scanf(" %c", &target);
//     int pos = lastIndex(text, target);
//     printf("the letter %c appears of the string is %dth position \n", target, pos+1);
//     return 0;
// }
// 6. ���庯�� ʵ���ַ�����Сд��ĸת��д��ĸ�� 	
//    ����ԭ��: char *upperCase(char *)
//    #include<stdio.h>
//    char *upperCase(char *str){
//        char *original = str;
//        while(*str!='\0'){
//         if(*str>='a'&& *str<='z'){
//             *str = *str - 32;
//         }
//         str++;
//        }
//        return original;
//    }
//    int main(){
//        char input[100];
//        printf("Enter a string\n");
//        fgets(input, sizeof(input), stdin);
//        for (char *p = input; *p != '\0'; p++)
//        {
//            if (*p == '\n')
//            {
//                *p = '\0';
//                break;
//            }
//        }
//        printf("original characters\n%s\n", input);
//        char *result = upperCase(input);
//        printf("the converted string\n%s\n ", result);
//        return 0;
//    }
// 7. ���庯�� ʵ���ַ����д�д��ĸתСд��ĸ��    
//    ����ԭ��: char *lowerCase(char *)

//     #include<stdio.h>
//    char *lowerCase(char *str){
//        char *original = str;
//        while(*str!='\0'){
//         if(*str>='A'&& *str<='Z'){
//             *str = *str + 32;
//         }
//         str++;
//        }
//        return original;
//    }
//    int main(){
//        char input[100];
//        printf("Enter a string\n");
//        fgets(input, sizeof(input), stdin);
//        for (char *p = input; *p != '\0'; p++)
//        {
//            if (*p == '\n')
//            {
//                *p = '\0';
//                break;
//            }
//        }
//        printf("original characters\n%s\n", input);
//        char *result = lowerCase(input);
//        printf("the converted string\n%s\n ", result);
//        return 0;
//    }