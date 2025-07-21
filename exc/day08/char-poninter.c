#include <stdio.h>
void f1(){
    char c1='a';
   char str[6]="hello";//字符串
   //给c1变量创建指针,保存该变量的地址
   char *c1Ptr=&c1;
   //给字符类型的数组创建指针（指针保存数组首元素的地址）
   char *strPtr1=str;
   //字符类型的数组指针
   char (*strPtr2)[6]=&str;


   *c1Ptr+=1;//字符的值+1
   printf("%c\n",*c1Ptr);

  //通过strPtr1修改首元素的值 (h--->H)

   *strPtr1-=32;
   printf("%c\n",*strPtr1);


   //根据c1Ptr指针把指向对应地址的数据获取到
   printf("%c\n",*c1Ptr);

   //根据strPtr1指针获取首元素
   printf("%c\n",*strPtr1);



   //根据strPtr1遍历所有的字符
   for (int i = 0; i < 5; i++)
   {
      // printf("%c\n",strPtr1[i]);
       printf("%c\n",*(strPtr1+i));

   }
   

   // 根据字符指针strPtr1 能不能使用 %s 获取字符串的数据
   printf("%s\n",str);
   printf("%s\n",strPtr1);

}
// 如果指针直接指向的是字面量常量的首字母地址:  数据不可修改
void f2(){
    /* 
    "hello": 字面量常量的字符串(字符数组)
    strPtr作为指针保存的是"hello"的首字符的地址 
    
    */
   char *strPtr="hello";

   // *strPtr-=32;//字面常量的值不能通过指针修改
    //strPtr[0]-=32;
   for (size_t i = 0; i < 5; i++)
   {
    //   printf("%c ",strPtr[i]);
    printf("%c ",*(strPtr+i));
   }
   

}


int main(){
    f2();


    return 0;
}