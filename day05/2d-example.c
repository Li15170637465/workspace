#include <stdio.h>
/***********************************************************************
 *  现在有三个班，每个班五名同学，用二维数组保存他们的成绩，并求出每个班级平均分、以及所有班级平均分，数据要求从控制台输入。
 ***********************************************************************/
int main()
{

    double scores[3][5];

    int row = sizeof(scores) / sizeof(scores[0]); // 行的个数
    int col = sizeof(scores[0]) / sizeof(double); // 列的个数

    // 控制台录入学生的成绩
    for (int i = 0; i < row; i++) // 控制行的下标
    {
        for (int j = 0; j < col; j++) // 控制列的下标
        {
            printf("请输入第%d个班级第%d个学生的成绩:", (i + 1), (j + 1));
            scanf("%lf", &scores[i][j]);
        }
    }

    double class_sum = 0.0; // 每个班级的总分数
    double total_sum = 0.0; // 所有班级的总分数
    // 循环计算分数
    for (int i = 0; i < row; i++)
    {
        // 对班级的总分数进行清零
        class_sum = 0.0;
        for (int j = 0; j < col; j++)
        {
            class_sum += scores[i][j];
        }
        printf("第%d个班级的平均分%.2lf:\n", (i + 1), class_sum / col);
        // 累加每个班级的总分数
        total_sum += class_sum;
    }

    // 计算所有班级的平局分
    printf("所有班级的平局分:%.2lf", total_sum / (row * col));

    // 遍历二维数组
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.2lf ", scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}