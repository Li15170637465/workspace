#include <stdio.h>
#include <stdbool.h>
/***********************************************************************
*   2. 循环，输出所有的水仙花数  (三位数  100 999)
    3. 循环输入5个数字，计算它们的平均数
    4. 输入一个数字，判断该数字是否是质数
    5. 输出100以内所有的质数
    6. 循环输出小写的a-z以及大写的Z—A。
    7. 求出1-1/2+1/3-1/4…..1/100的和
***********************************************************************/
int main(){


    // 2. 循环，输出所有的水仙花数  (三位数  100 999)
    //  for (int i = 100; i <=999; i++)
    //  {
    //       int n1=i/100;
    //       int n2=i/10%10;
    //       int n3=i%10;
    //       if(n1*n1*n1+n2*n2*n2+n3*n3*n3==i){
    //            printf("%d ",i);
    //       }
    //  }
     


    // 3. 循环输入5个数字，计算它们的平均数
    //  double sum=0.0;
    //  double num=0.0;
    //  for (int i = 0; i < 5; i++)
    //  {
    //       scanf("%lf",&num);
    //       sum+=num;
    //  }
    //  printf("平均数:%.2lf",sum/5);
     


    //  4. 输入一个数字，判断该数字是否是质数   （只能被1和自己整除的数是质数）
//     bool isPrime=true;//默认都是质数
//     int num;//输入的数字
//     scanf("%d",&num);
//     if(num<2){//不是质数
//          isPrime=false;
//     }
//     // 证明num不是质数
//    for (int i = 2; i <=num/2; i++)
//    {
//        if(num % i ==0){
//           isPrime=false;
//           break;
//        }
//    }
//    if(isPrime){
//         printf("%d是质数",num);
//    }else{
//         printf("%d不是质数",num);
//    }
   
    // 5. 输出100以内所有的质数
   /*  for (int num = 2; num < 100; num++)
    {
            bool isPrime=true;//默认都是质数

            // 证明num不是质数
        for (int i = 2; i <=num/2; i++)
        {
            if(num % i ==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime){
                printf("%d是质数\n",num);
        }
    } */
    



    //  6. 循环输出小写的a-z以及大写的Z—A。


//  for (char i = 'a'; i <='z' ; i++)
//  {
//      printf("%c ",i);
//  }
//  printf("\n");

//  for (char i = 'Z'; i >='A' ; i--)
//  {
//      printf("%c ",i);
//  }






//  7. 求出 1/1 - 1/2 + 1/3 - 1/4…..1/100的和
//   double sum=0.0;
//   for (int i = 1; i <=100; i++)
//   {
//      if(i%2==0){
//        // sum=sum-1.0/i;
//        sum-=(1.0/i);
//      }else{
//          sum+=(1.0/i);
//      }
//   }
//   printf("%.2lf",sum);
  


//   for (int i =1; i <=9; i++)
//   {
//     for (int  j = 1; j <=9; j++)
//     {
//          printf("%d%d ",i,j);
//     }
//     printf("\n");
    
//   }
  
/*   for (int i =1; i <=9; i++)
  {
    for (int  j = 1; j <=9; j++)
    {
         if(i==j){
             continue;
         }
         printf("%d%d ",i,j);
    }
    printf("\n");
    
  } */

 /* int row=6;

  for (int i = 1; i <=row ; i++)
  {

     for (int space = 1; space <=row-i ; space++)
     {
         printf(" ");
     }
     

      for (int j =1; j <=2*i-1 ; j++)
      {
          printf("*");
      }
      printf("\n");
  } */
  



  int row=16;

  for (int i = 1; i <=row ; i++)
  {

     for (int space = 1; space <=row-i ; space++)
     {
         printf(" ");
     }
     

      for (int j =1; j <=2*i-1 ; j++)
      {
         if(j==1 || j==2*i-1 || i==row ){
            printf("*");
         }else{
            printf(" ");
         }
         
      }
      printf("\n");
  }


    return 0;
}