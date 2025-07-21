#include <stdio.h>
/***********************************************************************
*   数据变量:  num,num2 的数据类型:  num：int    num2:double

    指针变量: numPtr,num2Ptr 的数据类型:  numPtr: int *   num2Ptr: double *
***********************************************************************/

void f1()
{
  // 声明int类型的变量
  int num = 10;
  // 声明double类型的变量
  double num2 = 20.1;

  // 给num创建指针(指针变量保存int类型变量的地址)
  int *numPtr = &num;

  // 给num2创建指针(指针变量保存double类型变量的地址)

  double *num2Ptr = &num2;

  // 使用取值运算符,获取指针指向的数据
  /*
     *numPtr:   获取指针变量保存的地址所指向的数据
       分解: 1. 根据指针变量的名字获取到存储的地址
             2. 通过取值符* 获取地址指向的数据
  */
  printf("%p,%d\n", numPtr, *numPtr);
  printf("%p,%.2lf", num2Ptr, *num2Ptr);
}

// 测试指针加减整数: （加:向后移动指针指向的地址,减:指针指向的地址向前移动）
// 注意: 目标数据在内存中的位置要连续,指针保存的地址不会变
void f2()
{
  int nums[] = {10, 20, 30, 40, 50};

  /***********************************************************************
   *  第一种访问数组数据的方式: 还是通过数组名字+下标的方式
   ***********************************************************************/
  // printf("%d\n", nums[0]);
  // printf("%d\n", nums[1]);

  /***********************************************************************
   *  第二种访问数组数据的方式: 通过指针运算
   ***********************************************************************/
  // 是指向数组第一个数据的指针
  //  int *ptr1=&nums[0];
  //  printf("%p,%d\n", ptr1,*ptr1);
  //  printf("%d,%p,%p\n",*(ptr1+1),ptr1+1,ptr1);
  //  printf("%d\n",*(ptr1+2));

  // 使用指针指向数组任意数据的地址
  //   int *ptr1=&nums[3];
  //   printf("%d\n",*ptr1);
  //   printf("%d\n",*(ptr1+1));
  //   printf("%d\n",*(ptr1-3));

  // 使用指针的移动结合for循环实现对数组元素的遍历
  //   int *ptr1=&nums[0];//第一个元素的指针
  //  for (int i = 0; i < 5; i++)
  //  {
  //      printf("%d\n",*(ptr1+i));
  //      printf("%d\n",nums[i]);

  // }

  int *ptr1 = &nums[4]; // 最后一个元素的指针
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", *(ptr1 - i));
  }
}

// 指针自增,自减: 向前(自减)或者向后(自增)移动一次指针
//  注意:  指针保存的地址会发生变化
void f3()
{
  int nums[] = {10, 20, 30, 40, 50};

  // int *ptr3 = &nums[2]; // 指向数组第三个元素的地址

  // // ptr3++; //ptr3=ptr3+1
  // printf("%d\n", *(++ptr3));
  // printf("%d\n", *(--ptr3));

  // ptr3 += 2; // 指针保存的地址向后移动两个位置

  // printf("%d\n", *ptr3);
  // ptr3 -= 2;

  // printf("%d\n", *ptr3);

  // 通过指针遍历数据
  int *ptr1 = &nums[0];

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", *(ptr1++));
  }

  printf("\n");

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", *(--ptr1));
  }
}

// 计算元素之间的距离: 两个元素相差多少个内容
//  注意: 1.类型一致  2. 根据指针保存的地址的差 3. 先声明的变量的地址在高位
void f4()
{
  double nums[] = {1.1, 2.1, 3.1, 4.1, 5.1};
  double *ptr1 = &nums[0];
  double *ptr4 = &nums[4];

  ptrdiff_t size = ptr4 - ptr1;
  ptrdiff_t size2 = ptr1 - ptr4;

  printf("%td,%td\n", size, size2);

  printf("%p,%p\n", ptr4, ptr1);

  double a = 1;
  double b = 1;

  double *aPtr = &a;
  double *bPtr = &b;
  printf("%td", aPtr - bPtr);
}

// 指针比较: 比较的是多个指针保存的地址大小(高位和低位)
void f5()
{
  int a = 1;
  int b = 2;

  int *aptr = &a;
  int *bptr = &b;

  printf("%d\n", aptr > bptr);
  printf("%d\n", aptr < bptr);
  printf("%d\n", aptr == bptr);
}

// 数组名字作为第一个元素的指针(数组名字保存了第一个元素的地址)
// 注意:  1.数组名字作为指针不能改变指向的地址
//        2. 不能使用数组名字和sizeof结合使用计算指针的长度
//        3. 数组名字也可以进行加减计算(移动指针)
void f6()
{
  int nums[] = {10, 20, 30, 40, 50};
  int *ptr1 = &nums[0];
  printf("%p,%p,%p\n", nums, &nums[0], ptr1);

  // 数组名字也可以进行加减计算(移动指针)
  printf("%d\n", *(ptr1 + 1));
  printf("%d\n", *(nums + 1));

  // ptr1++;
  // nums++;  不能++,--

  // printf("%zu\n",sizeof(nums));
  // printf("%zu\n",sizeof(ptr1));

  // 使用数组名字作为第一个元素的指针,遍历数组元素

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", *(nums + i));
    // printf("%d ",nums[i]);
  }
}

/*
  2. 数组求和
描述：递归计算整型数组所有元素之和。
示例：输入数组 {1, 2, 3, 4}，输出 10
 1+{2,3,4}    3

 1+2+{3,4}    2

 1+2+3+{4}   1

1+2+3+4      0
1+2+3+4+0

*/
int getSum(int nums[], int size)
{
  if (size == 0)
  {
    return 0;
  }
  return nums[0] + getSum(nums + 1, size - 1);
}

int main()
{
  // f6();
  int nums[] = {1, 2, 3, 4};

  printf("%d", getSum(nums, 4));
  return 0;
}