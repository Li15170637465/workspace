#include <stdio.h>
#include <string.h>
// 1. 定义函数，实现交换两个变量的值； 函数原型 void exchange(int *, int *)

// 2. 定义一个函数，接收数组名或首元素指针 和 数组长度 作为参数，计算数组的平均数
//    函数原型： int get_avg(int *, int);

 double get_avg(int *arr, int size){
      int sum=0;
      for (int i = 0; i < size; i++)
      {
          //sum+=arr[i];
           sum+= (*(arr+i));
      }

    return  (double)sum/size;
      
 }

   
// 3. 定义函数，接收一个字符串和字符，统计字符在字符串中出现的次数
//    函数原型: int char_count(char *, char)
   int char_count(char *str, char c1){
      int count=0;
      for (int i = 0; i < strlen(str); i++)
      {
        //    if(str[i]==c1){
        //       count++;
        //    }

         if(*(str+i)==c1){
              count++;
           }
      }
      

      return count;
   }
// 4. 定义函数，返回某个字符在字符串中第一次出现的位置	   
//    函数原型: int firstIndex(char *, char)
   int firstIndex(char *str, char c1){
       int fIndex=-1;

      for (int i = 0; i < strlen(str); i++)
      {
           if(str[i]==c1){
               fIndex=i;
               break;
           }
      }
      return fIndex;

   }
// 5. 定义函数，返回某个字符在字符串中最后一次出现的位置  
//    函数原型: int lastIndex(char *, char)



   size_t lastIndex(char *str, char c1){
       size_t lIndex=-1;

      for (size_t i = strlen(str)-1; i >=0; i--)
      {
           if(str[i]==c1){
               lIndex=i;
               break;
           }
      }
      return lIndex;

   }

  
// 6. 定义函数 实现字符串中小写字母转大写字母； 	
//    函数原型: char *upperCase(char *)
   char *upperCase(char *str){

       for (int i = 0; i < strlen(str); i++)
       {
            str[i]-=32;
       }
       

   }

   char * upperCase2(){
        static  char str[]="hello";
       for (int i = 0; i < strlen(str); i++)
       {
            str[i]-=32;
       }
       
       return str;

   }


// 7. 定义函数 实现字符串中大写字母转小写字母；    
//    函数原型: char *lowerCase(char *)
  char *lowerCase(char *str){

       for (int i = 0; i < strlen(str); i++)
       {
            str[i]+=32;
       }
       

   }

int main(){
//   int nums[]={1,2,3,4,5};
//   printf("%.2lf",get_avg(nums,5));


    // printf("%d",char_count("hello",'l'));

     //printf("%lld",lastIndex("hello",'l'));



     char str[]="hello";
   //  upperCase(str);
   //  printf("%s",str);

    char *strPtr=  upperCase2();
    
     printf("%s",strPtr);


    return 0;
}