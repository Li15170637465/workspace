#include <stdio.h>
int main(){
    /***********************************************************************
    *  1. 课堂案例(课件中的案例)
      成绩判断 生肖计算 月份天数 加油案例

    2. 实现判断一个整数，属于哪个范围：大于0；小于0；等于0。（获取用户输入的整数）
    3. 判断一个年份是否为闰年。（获取用户输入的年份） (能被4整除且不能被100整除  或者能被400整除的数)
    4. 判断一个整数是否是水仙花数，所谓水仙花数是指一个3位数，其各个位上数字立方和等于其本身，例如：153 = 1*1*1 + 5*5*5 + 3*3*3。
    ***********************************************************************/



// int num=10;
// scanf("%d",&num);
//  if(num>0){

//  }else if(num<0){

//  }else{
     
//  }

/* int year;
scanf("%d",&year);

if((year%4==0 && year %100!=0) || year % 400==0){
    printf("是闰年!");
} */


int num; //1 5 3
scanf("%d",&num);
int n1=num / 100; //百位
int n2=num /10 % 10; //十位
int n3=num % 10; //个位

 if(n1*n1*n1+n2*n2*n2+n3*n3*n3==num){
     printf("是!");
 }
    return 0;
}