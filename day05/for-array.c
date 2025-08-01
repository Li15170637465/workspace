#include <stdio.h>
/***********************************************************************
*   如何获取数组的元素:
       1.随机获取(灵活的使用下标进行数据的获取)
       2.遍历获取(从最小下标到最大下标)   结合循环控制下标
***********************************************************************/
int main()
{
    int nums[] = {10, 20, 30, 40, 50};

    // printf("%d", nums[2]);//根据下标获取一个元素

    // 获取所有的元素: 使用循环控制数组的下标
    //  i数组的下标默认从0开始
    for (int i = 0; i < 5; i++)
    {
        printf("%d,%d\n", i, nums[i]);
    }

    // 获取前三个元素
    for (int i = 0; i <= 2; i++)
    {
        printf("%d,%d\n", i, nums[i]);
    }
    // 获取中间三个元素

    for (int i = 1; i <= 3; i++)
    {
        printf("%d,%d\n", i, nums[i]);
    }

    // 获取后三个元素

    for (int i = 2; i <=4; i++)
    {
       printf("%d,%d\n", i, nums[i]);
    }
    


    //倒序打印数组的所有数据

    for (int i = 4; i >=0; i--)
    {
       printf("%d,%d\n", i, nums[i]);
    }
    

    // int i=0;
    // while (i<5)
    // {
    //      printf("%d,%d\n", i, nums[i]);
    //     i++;
    // }
    

    return 0;
}