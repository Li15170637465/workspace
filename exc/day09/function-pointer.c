#include <stdio.h>

/***********************************************************************
*  函数指针:  保存函数地址的指针
    作用:  调用函数
***********************************************************************/

int max(int a, int b)
{
    return a > b ? a : b;
}



char * getCount(){
 static char  str[]="3";

 return  str;
}


int main()
{

   //创建getCount函数的指针
    char * (*charPtr)()=getCount;

    printf("%s\n",charPtr());


    printf("%p\n", max);  // 00007ff6a88a14a4 获取到了函数的首地址
    printf("%p\n", &max); // 00007ff6a88a14a4 获取到了函数的首地址

    // 创建函数指针: 保存函数的首地址
    int (*maxPtr)(int, int) = max;

    // 使用函数指针调用函数
    //    int result=(*maxPtr)();
    int result = maxPtr(10, 20);

    printf("%d", result);
    return 0;
}