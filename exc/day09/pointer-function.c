#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//请编写一个函数 strlong()，返回两个字符串中较长的一个字符串。

//返回值是指针类型: 指针函数
char *  strlong(char *str1,char *str2){
     
    return  strlen(str1)>strlen(str2)? str1:str2;
} 
 




char *  strlong2(){
     char *str1="a", *str2="abc";

    return  strlen(str1)>strlen(str2)? str1:str2;
} 
 

char *  strlong3(){
    static  char str[]="hello";

      return str;
} 
 








int * count(){
   static  int num=10; // 提升局部作用域数据的生命周期

    return &num; //函数结束局部变量的数据自动销毁
}




int * returnArr(){
  
   static int num[]={1,2,3,4};
   
    return num;
}


//编写一个函数，它会生成10个随机数，并使用数组名作为返回值。

int * random(){
    static int num[10];

     for (int i = 0; i < 10; i++)
     {
         num[i]=rand();
     }
     

    return num;
}




int main(){
 
     
    //   printf("%s\n",strlong("a","abc"));

    //   char *str=  strlong2();
    //   printf("%s\n",str);

    //   int *ptr=count();

    //   printf("%d",*ptr);


    // int *ptr=returnArr();
    // printf("%d",*ptr);


// int *ptr=random();

// for (int i = 0; i <10; i++)
// {
//      printf("%d ",ptr[i]);
// }


  printf("%s",strlong3());
    return 0;
}