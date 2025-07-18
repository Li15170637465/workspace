#include <stdio.h>

/***********************************************************************
 *  return: 函数给调用者返回的数据，必须对应函数的返回值类型
 *
 * 注意: 1. 如果函数有返回值类型，但是没有写return的数据  ,调用者拿到一个垃圾值
 *       2. return相当于函数的结束语句
 *
 *
 *
 * void: 1.不会给调用者返回数据, 不使用return返回"数据"
 *       2.可以使用return结束函数
 *
 ***********************************************************************/
int function1()
{
    return 100;
}

// 返回最大值的函数
int returnMax()
{
    int a = 10, b = 20;

    return a > b ? a : b;
}

int function3()
{

    printf("函数3\n");
    return 3;
}

void printMax()
{
    int a = 101, b = 20;
    if (a > 100 || b > 100)
    {
        return;
    }

    printf("%d", a > b ? a : b);
}

int main()
{

    // 调用一个函数,返回一个int类型的数据
    // int result1 = function1();

    // 调用一个函数,获取多个整数数据的最大值并返回值
    //    int result2= returnMax();
    //    printf("最大值:%d",result2);

    // printf("最大值:%d", returnMax());

    // 调用一个返回值位int类型的函数,但是没有进行return
    //  int result3= function3();
    //  printf("%d",result3);

    // 调用一个函数,让把最大值打印出来
    printMax();

    return 0;
}