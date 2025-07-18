#include <stdio.h>
int main(){
  int nums[5];

  for (int i = 0; i <5; i++)
  {
     printf("请输入第%d个数据:",(i+1));
     scanf("%d",&nums[i]);
  }
  
  //查找数组中的最大值 穷举
  int max=nums[0];//保存数组中最大的元素
  for (int i = 1; i < 5; i++)
  {
      if(max<nums[i]){
          max=nums[i];
      }
  }
  

  printf("%d\n",max);


  //查找数组中的最小值
  int min=nums[0];

 for (int i = 1; i < 5; i++)
 {
     if(min>nums[i]){
       min=nums[i];
     }
 }

  printf("%d",min);

 
  
    return 0;
}