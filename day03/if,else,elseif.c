#include <stdio.h>
/***********************************************************************
*  if(){}// 单向分支
      if: 关键字(如果)
      (): 条件表达式(结果:布尔类型(1 true, 0 false))
      {}: 分支语句(代码块) 代码块中的程序执行完毕之后自动退出
   if(){}else{}  双向分支

    else: 关键字(否则：是对if的兜底操作)

   if(){}else if(){} ....  else{} 多向分支
   else if: 关键字(否则如果： 上一个判断不成立 否则指向当前的if判断)
***********************************************************************/

int main()
{
    double scores = -10;
    // if (scores < 60)
    // {
    //     printf("不及格\n");
    // }else if(scores<70){
    //    printf("等级:D\n");
    // }else if(scores<80){
    //    printf("等级:C\n");
    // }else if(scores<90){
    //    printf("等级:B\n");
    // }else if(scores<=100){
    //    printf("等级:A\n");
    // }
    // else{
    //    printf("双向分支:成绩不合理!\n");
    // }

    if (scores >= 0 && scores < 60)
    {
        printf("不及格\n");
    }
    else if (scores >= 60 && scores <= 70)
    {
        printf("等级:D\n");
    }
    else if (scores > 70 && scores <= 80)
    {
        printf("等级:C\n");
    }
    else if (scores > 80 && scores <= 90)
    {
        printf("等级:B\n");
    }
    else if (scores > 90 && scores <= 100)
    {
        printf("等级:A\n");
    }
    else
    {
        printf("多向分支:成绩不合理!\n");
    }

    printf("主函数结束!(应用程序退出)\n");

    int a = 20, b = 20; // 求最大值
    int max=a;            // a或者b中的最大值
    //   if(a>b){
    //       max=a;
    //   }else{
    //      max=b;
    //   }

    if (a > b)
    {
        max = a;
    }
    else if (a < b)
    {
        max = b;
    }/* else{
        //  max=a;
         max=b;

    } */

    printf("%d\n", max);
    return 0;
}