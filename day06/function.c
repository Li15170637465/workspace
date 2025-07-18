#include <stdio.h>
/***********************************************************************
*   void: 无返回值类型的函数
    func1: 自定义的函数名字(是函数的标识符)
    ():   形参列表
    {}:   函数体(代码块)

    int: 函数中的代码执行完毕之后必须返回一个int类型的数据(int返回值类型的函数)

    通过函数的名字调用函数:  每调用一次会执行函数中所有的代码一次

    return: 把函数中的数据返回给调用者
***********************************************************************/
//自定义函数
void func1(){
  printf("函数1\n");
}


int func2(){

    return 1;
}


double func3(){

    return 1.1;
}


int main(){
    func1();//调用函数:
    func1();//调用函数:

   int result=  func2();
   printf("%d\n",result);

   double result2= func3();
   printf("%.2lf\n",result2);



  

    return 0;
}