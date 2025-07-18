#include <stdio.h>
/***********************************************************************
*  (): 函数的形参列表
   形参: 在函数中声明好了变量,用于接收外部传递过来的数据(int n1=100)
   实参: 调用函数时,传递给形参的数据

   传递参数时注意事项:
       1.类型要兼容(一致)
       2.参数个数一致
       3.顺序一致



    如果形参是数组: 传递的是地址(共享内存空间)   (引用(地址)传递)
    如果形参是普通的类型： 传递的是值（不共享内存空间）(值传递)
***********************************************************************/
int getMax(int n1,int n2){
   return n1>n2?n1:n2;
}


void printChar(char c1){
  printf("%c",c1);
}

void printCharArr(char c2[],int size){
  for (int i = 0; i <size; i++)
  {
      printf("\n%c ",c2[i]);
  }
  c2[0]='H';
}

//修改传递过来的数据
void updateNum(int num){
  num=0;//修改数据
  printf("修改完成:%d\n",num);
}


int main(){
 int a=100,b=200;
 // 调用函数, 获取a,b最大值 
 int result= getMax(a,b);
 printf("%d\n",result);

//字符
 char c1='a';
 printChar(c1);


 //传递字符数组到函数中,打印数组中的内容
  char str[]="hello";
  printCharArr(str,5);


  printf("\n%s\n",str);


  int num=666;
  updateNum(num);

  printf("num=%d",num);
    return 0;
}