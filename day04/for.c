#include <stdio.h>
/***********************************************************************
*       循环变量的初始化:  只初始化一次
        变量创建的位置: 1. for循环中的第一个表达式
                       2. for循环之前

        循环变量的变化位置:  1. for循环的第三个表达式  2.循环语句之后

        标准的写法:  for(循环变量初始化;循环条件;循环变量变化){
                          循环体(循环语句)
                    }
***********************************************************************/
int main()
{

    //  for (;;)
    //  {
    //     /* code */
    //  }

 /*    int i = 0;
    for (; i <= 10;)
    {
        printf("%d ", i);
        i++;
    }

    printf("%d", i); */


  /*  for (int day = 1; day <=10; day++)
   {
      printf("我第%d天吃了%d个韭菜馅的包子\n", day, day);
   }
    */


   //1-10求和
   //int num=1;//循环变量
//    int sum=0;//和
//    for (int num=1; num <=10; num++)
//    {
//       sum+=num;
//    }
   
//    printf("%d",sum);


// 1-10偶数
/*  for (int num = 0; num <=10; num+=2)
 {
     printf("%d ",num);
   
 } */
 

 //比较密码
//   int pwd1=123456;
 // int inputPwd;
 for ( int pwd1=123456,inputPwd; pwd1!=inputPwd ; )
 {
     printf("请输入密码:");
     scanf("%d",&inputPwd);//循环变量的变化(迭代)
 }
 printf("匹配成功!");

    return 0;
}