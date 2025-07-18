#include <stdio.h>
/***********************************************************************
*   自动类型转换(隐式类型转换)
             计算过程中
                1. 在计算的过程中出现了不同大小的类型,自动实现小转大(窄转宽)
                2. 在计算过程中出现了不同大小的类型(整数,浮点数) (自动转为浮点数类型)
                3. 在计算过程有符号和无符号计算 （有符号自动转成无符号的数）

             赋值过程中（自动类型转换）:  有问题         在开发中要不要进行转换必须要让程序员
                宽 转 窄          (可能保存不下(溢出))
                浮点数 转 整数    (丢失精度)


    显示的强制类型转换 (类型)数据   比如:   (int)1.1

***********************************************************************/
int main(){
//   int a=10;
//   short b=11;
//   long long c=12;
//   printf("%zu",sizeof(a+b+c));
/* 
  int num1=10;
  float num2=2.1;
  int num3=  num1+num2;
   printf("%d\n",num3);
   printf("%zu\n",sizeof(num1+num2)); */


/*  int a=-2;
 int c=2;  */
//unsigned int b=10;

// printf("%zu",sizeof(a+b));
/* if(c>a){
    printf("c更大");
}else{
      printf("a更大");
} */


/* short s1=100000;
int i1=(int)1.1;
unsigned int ui=10;
printf("%hd\n",s1);
printf("%d\n",i1); */




/* // 动态的录入两个同学的成绩(整数) 并求平均分
  int score1,score2;
  scanf("%d,%d",&score1,&score2);
  //求和
  int sum=  score1+score2;

  double avg=(double)sum/2;

  printf("%.2lf",avg);
 */
 int a=10;
 printf("%d",a);
    return 0;
}