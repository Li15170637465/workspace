#include <stdio.h>
#include <string.h> //引入字符串的头文件(使用定义好的函数)
/***********************************************************************
*  1.sizeof: 计算数组中所有字符(包括结束符)的字节长度
   2.使用string.h头文件中的函数(strlen)获取数组中有效的元素个数  (不包括结束符\0)
***********************************************************************/
int main()
{
    char str[] = "hello";

    // printf("%s",str);

    int len = sizeof(str) / sizeof(char);
    int size = strlen(str);
    printf("%d,%d\n", len, size);
    for (int i = 0; i < size; i++)
    {
        printf("%c ", str[i]);
    }

    return 0;
}