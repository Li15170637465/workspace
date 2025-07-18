#include <stdio.h>
int main(){
    /***********************************************************************
    *   1. 从终端循环输入5个成绩，保存到double数组，并输出。
        2. 一个养鸡场有6只鸡，它们的体重分别是3kg，5kg，1kg，3.4kg，2kg，50kg。请问这六只鸡的总体重是多少?平均体重是多少?
        3. 创建一个char类型的26个元素的数组，分别放置'A'-'Z‘。使用for循环访问所有元素并打印出来。
        4. 请求出一个数组的最小值，并得到对应的索引。
        5. 请求出一个数组的最大值
        6. 尝试使用单层循环遍历二维数组
            int nums[3][4] = {
                {1, 2, 3, 4},
                {11, 12, 13, 14},
                {21, 22, 23, 24}
            };
        7. 创建数组，存入 "xiaoma"、"xiaolu", "xiaoqi" 三个元素，并使用循环遍历输出三个字符串

    ***********************************************************************/

    //1. 从终端循环输入5个成绩，保存到double数组，并输出。
    // double scores[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     scanf("%lf",&scores[i]);
    // }
    

    // for (int i = 0; i < 5; i++)
    // {
    //      printf("%.2lf\n",scores[i]);
    // }



    //一个养鸡场有6只鸡，它们的体重分别是3kg，5kg，1kg，3.4kg，2kg，50kg。请问这六只鸡的总体重是多少?平均体重是多少?

    // double weight[6]={3,5,1,3.4,2,50};

    // double total=0.0;
    // for (int i = 0; i < 6; i++)
    // {
    //     total+=weight[i];
    // }
    // printf("总体重:%.2lf\n",total);
    // printf("平均体重:%.2lf\n",total/6);

    

    //创建一个char类型的26个元素的数组，分别放置'A'-'Z‘。使用for循环访问所有元素并打印出来。
    // char str[27];// 不是创建数组并初始化程序不会自动添加结束符
    // for (int i = 0; i < 26; i++)
    // {
    //     str[i]= (char)('A'+i); 
    // }

    // str[26]='\0';
    // printf("%s",str);





   // 6. 尝试使用单层循环遍历二维数组
    //         int nums[3][4] = {
    //             {1, 2, 3, 4},
    //             {11, 12, 13, 14},
    //             {21, 22, 23, 24}
    //         };
    

    // int row=3;
    // int col=4;

    // for (int i = 0; i < row*col; i++)
    // {
    //      //行的下标
    //      int rowIndex=i / col;
    //      //列的下标
    //      int colIndex=i % col;
    //      printf("%d ",nums[rowIndex][colIndex]);
    //      if((i+1)%4==0){
    //        printf("\n");
    //      }
        

    // }



    //创建数组，存入 "xiaoma"、"xiaolu", "xiaoqi" 三个元素，并使用循环遍历输出三个字符串

    char str[3][7]={"xiaoma","xiaolu","xiaoqi"};

    for (int i = 0; i < 3; i++)
    {
          printf("%s\n",str[i]);
    }
    


    



    return 0;
}