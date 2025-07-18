#include <stdio.h>
/***********************************************************************
 *  数组的长度: 必须使用通过sizeof动态计算出来的
 *  数组实际有效的元素个数:  要求程序员实时的记录数组中的有效元素个数  (作为循环的条件)
 *       好处: 避免无用的循环次数
 ***********************************************************************/
int main()
{
    int nums[] = {100, 200, 300, 400, 500};

    // 计算数组的长度
    size_t numsByte = sizeof(nums); // 数组总字节大小
    // int  length=numsByte/sizeof(nums[0]);// 总字节除以单个元素的字节长度
    int length = (int)numsByte / sizeof(int);
    // 遍历数组的元素(数组的长度动态获取)
    for (int i = 0; i < length; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    int nums2[5]; // 空数组
    int size = 0; //  实时的记录数组实际元素的个数

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &nums2[i]); // 向数组的第i个位置添加元素
        size++;
    }

    int len = sizeof(nums2) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums2[i]);
    }

    return 0;
}