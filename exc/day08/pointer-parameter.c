#include <stdio.h>

void exchange(int a,int b){//修改局部变量的数据
     a++;
     b++;
}

//函数的形参是指针
void exchange2(int *a,int *b){//修改主函数中的a,b数据
     (*a)++;
     (*b)++;
}


//函数的形参是数组
//  void printArray(int num[],int size){

//  }
//函数的形参是数组的名字(首元素地址)
 void printArray(int *arr,int size){
       for (int i = 0; i < size; i++)
       {
          //printf("%d ",arr[i]);//以首元素的地址作为起始位置,通过下标进行指针移动
          printf("%d ",*(arr+i));// 获取指针指向的数据 其中+i配合循环完成指针移动
           
       }
       
 }


// 函数的形参是数组指针
 void printArray2(int (*arr)[],int size){
       for (int i = 0; i < size; i++)
       {
                // printf("%d ",*((*arr)+i));
            printf("%d ",(*arr)[i]);
       }
       
 }


 //函数的形参是指针数组
 void printArray3(int *ptrArr[5],int size){
       for (int i = 0; i <size; i++)
       {
            printf("%p,%p,%d\n ",ptrArr,ptrArr[i],*ptrArr[i]);
       }
       
 }

//形参是字符类型的指针
void  printChar(char *ptr){
//    printf("%c",*ptr);
  // printf("%s",ptr);
   for (int i = 0; i < 5; i++)
   {
      printf("%c",*(ptr+i));
   }
   

}


int main()
{
     char c1='a';
    //  printChar(&c1);
     char str[]="hello";
     printChar(str);

      printChar("hello");
     

    return 0;
}

// int main()
// {
//     int nums[]={10,20,30,40,50};
//     int *ptrArr[5]={&nums[0],&nums[1],&nums[2],&nums[3],&nums[4]};
//      printArray3(ptrArr,5);

//     return 0;
// }



// int main()
// {
//     int nums[]={10,20,30,40,50};
//     //  printArray(&nums[0],5);
//     //  printArray(nums,5);

//     // &nums: 获取整个数组的地址
//      printArray2(&nums,5);

//     return 0;
// }



// int main()
// {
//     int a = 1, b = 20;

//     //  exchange(&a,&b);// 把a的值1和b的值20传递给 exChange函数的局部变量(a,b)
//     exchange2(&a,&b);// 把主函数中a和b的地址共享给函数exchange2的变量
//     printf("%d,%d",a,b);
//     return 0;
// }