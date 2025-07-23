#include <stdio.h>
int main(){
 int nums[]={1,2,3,4};

 //数组的指针: 该指针中保存整个数组的地址(虽然和第一个元素的地址一致)
 // 理解:  有一个指针保存数组的地址:相当于一层包装
 //        数组的地址: 相当于是每一个数据的一层包装    


  int (*ptr)[4]=&nums;


  //根据指针解析获取到具体的数据
 // printf("%p,%p,%d",ptr,*ptr,**ptr);


  for (int i = 0; i < 4; i++)
  {
      printf("%d ",(*ptr)[i]);
      // printf("%d ",*((*ptr)+i));
  }
  

    return 0;
}