#include <stdio.h>
/***********************************************************************
*  do-while的使用场景:  先做 然后对结果进行判断
***********************************************************************/
int main()
{
    // （1）输出10次 "我第n天吃了n个韭菜馅的包子"
    /*    int day = 100;
       do
       {
           printf("我第%d天吃了%d个韭菜馅的包子\n", day, day);
           day++;
       } while (day <= 10); */

    // 10(包括10)以内数字求和

    // int num = 1;
    // int sum = 0;
    // do
    // {
    //     sum += num;
    //     num++;
    // } while (num <= 10);
    // printf("%d\n", sum);
    // printf("%d", num);

    // 打印10以内的偶数
    //  int num=0;
    //  do
    //  {
    //      printf("%d ",num);
    //      num+=2;
    //  } while (num<=10);

    // 密码比较(密码匹配失败继续循环比较)
    int pwd = 123456;
    int inputPwd;
    do
    {
        printf("请输入密码:");
        scanf("%d", &inputPwd);

    } while (pwd != inputPwd);

    return 0;
}