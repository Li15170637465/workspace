#include <stdio.h>
#include <stdlib.h>
//使用回调函数的方式，给一个整型数组int arr[10] 赋10个随机数。

// 在自定义函数random的形参位置有一个函数指针，必须通过函数指针调用目标函数完成回调
int * random( int (*randPtr)() ){
    static int arr[10];
    for (int i = 0; i < 10; i++)
    {
         arr[i]=randPtr();
    }
    
    return arr;
}



int main(){
  // 给rand()函数设置一个函数指针,保存该函数的首地址
   int (*randPtr)()=rand;

   int *ptr=random(randPtr); 


   for (int i = 0; i < 10; i++)
   {
      printf("%d ",ptr[i]);
   }
   
    return 0;
}