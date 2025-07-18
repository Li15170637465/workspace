#include <stdio.h>
/***********************************************************************
 *   嵌套循环的规则:  外层循环执行一次 内层循环执行一遍
 ***********************************************************************/
int main()
{
    // 如果输入的行数是4，列数是7，输出结果如下：

    int row = 4; // 行
    int col = 7; // 列

    /* for (int i = 0,j=0; i < 4; i++,j++)//外层循环控制行数
    {
       printf("[%d,%d]\n",i,j);

    }
     */

    /*   for (int i = 0; i < row; i++)
      {
          for (int j = 0; j <col; j++)
          {
              printf("[%d,%d] ",i,j);
          }
          printf("\n");

      } */

    // 一
    /*   for (int i = 1; i <= 9; i++)
      {
         for (int j = 1; j <=i; j++)
         {
           printf("%d*%d=%d ",j,i,j*i);
         }
         printf("\n");

      } */

    // 二
    /* for (int i =9 ; i >=1; i--)
    {
        for (int j = 1; j <=i; j++)
        {
              printf("%d*%d=%d\t",j,i,j*i);
        }
         printf("\n");
    }
     */

    // 三
    // for (int i = 1; i <= 9; i++)
    // {
    //      for (int space = 1; space <=9-i; space++)
    //      {
    //           printf("\t");
    //      }

    //     for (int j = 1; j <= i; j++)
    //     {
    //         printf("%d*%d=%d\t", j, i, j * i);
    //     }
    //     printf("\n");
    // }

//注释
    for (int i = 9; i >= 1; i--)
    {
        for (int space = 1; space <=9-i; space++)
        {
           printf("\t");
        }
        
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%d\t", j, i, j * i);
        }
        printf("\n");
    }

    return 0;
}