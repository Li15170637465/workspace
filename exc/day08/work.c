#include <stdio.h>
/***********************************************************************
*  2. 数组求和
描述：递归计算整型数组所有元素之和。
示例：输入数组 {1, 2, 3, 4}，输出 10

3 定义函数，实现交换两个变量的值； 函数原型 void exchange(int *, int *)
***********************************************************************/





// int getSum(int nums[],int size){
//   int sum=0;
//   for (int i = 0; i < size; i++)
//   {
//      sum+=nums[i];
//   }
  
//   return sum;
// }



//{1, 2, 3, 4}
/* 
  4 + {1,2,3}      3

  4+3 + {1,2}      2

  4+3+2 +  {1}     1

  4+3+2+1  +{}     0

  4+3+2+1+0
*/
int getSum(int nums[],int size){
    if(size==0){
         return 0;
    }
  return  nums[size-1]+ getSum(nums,size-1) ;
}



// void exchange(int *a, int *b){
//    int temp=*a;
//    *a=*b;
//    *b=temp;
// }


void exchange(int *a, int *b){
    *a=*a ^ *b;
    *b=*a ^ *b;
    *a=*a ^ *b;
}





int main(){
     int nums[]={1,2,3,4,5};

     printf("%d",getSum(nums,5));
//   int  a=10,b=20;
//   exchange(&a,&b);//引用传递(地址传递)

//   printf("%d,%d",a,b);

    return 0;
}