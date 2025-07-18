#include <stdio.h>
/***********************************************************************
*  goto： 是c语言程序中的关键字
   作用: 控制程序的执行顺序(位置)
***********************************************************************/
int main()
{

    //    printf("1\n");
    //    printf("2\n");
    //    goto position4;
    //    printf("3\n");
    //    //标记要跳转的位置
    //    position4:
    //    printf("4\n");

    // 打印 1-10的数字  使用goto关键字

    int num = 1;
    start:
    if (num <= 10)
    {
        printf("%d ", num);
        num++;

        goto start;
    }

    return 0;
}