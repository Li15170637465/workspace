#include <stdio.h>
int main(){
  double scores[2][3]={{1,2,3},{4,5,6}};
 
//   printf("%zu\n",sizeof(scores));//数组所有元素总字节长度

//   printf("%zu\n",sizeof(scores[0]));//数组第一行所有元素的字节长度


  int row=sizeof(scores)/sizeof(scores[0]);//行的个数
  int col=sizeof(scores[0])/sizeof(double);//列的个数 

  //控制台录入学生的成绩
  for (int i = 0; i < row; i++)//控制行的下标
  {
     for (int j = 0; j < col; j++)//控制列的下标
     {
         printf("请输入第%d个班级第%d个学生的成绩:",(i+1),(j+1));
         scanf("%lf",&scores[i][j]);
     }
     
  }
  

  //遍历二维数组

for (int i = 0; i < row; i++)
  {
     for (int j = 0; j < col; j++)
     {
          printf("%.2lf ",scores[i][j]);
     }
     printf("\n");
  }

    return 0;
}