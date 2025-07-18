#include <stdio.h>
/***********************************************************************
*  编写一个程序，该程序可以接收一个字符，
   比如：a、b、c、d其中a表示星期一，b表示星期二…，根据用户的输入显示相应的信息，要求使用switch语句。
***********************************************************************/
int main()
{

    char week = 'a';
    if (week == 'a')
    {
        printf("星期一");
    }
    else if (week == 'b')
    {
        printf("星期二");
    }
    else if (week == 'c')
    {
        printf("星期三");
    }
    else if (week == 'd')
    {
        printf("星期四");
    }
    else
    {
        printf("没有可以匹配的信息!!");
    }

    switch (week)
    {
    case 'a':
        printf("星期一");
        break;
    case 'b':
        printf("星期二");
        break;
    case 'c':
        printf("星期三");
        break;
    case 'd':
        printf("星期四");
        break;
    default:
        printf("没有匹配的信息！！");
        break;
    }

    printf("\n");

    /***********************************************************************
     *  编写程序，输入月份，输出该月份有多少天。说明：1月、3月、5月、7月、8月、10月、12月有31天，4月、6月、9月、11月有30天，2月有28 天或 29天。
     ***********************************************************************/
    int month;
    scanf("%d", &month);
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("%d月份是31天", month);
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        printf("%d月份是30天", month);
        break;

    case 2:
        printf("%d月份是28或29天", month);
        break;

    default:
        break;
    }

    /***********************************************************************
    *  输入油号（92或95）和油量，
       计算需要支付的金额。
       92号汽油每升4元，如果油量大于等于40升，每升3.5元；
       95号汽油每升5元，如果油量大于等于40升，每升4.5元。
    ***********************************************************************/
    int oilN, oilL;
    double price; // 单价
    printf("请输入油号:");
    scanf("%d", &oilN);
    printf("请输入油量:");
    scanf("%d", &oilL);

    /*     if (oilN == 92)
        {
            price = 4;
            if (oilL >= 40)
            {
                price = 3.5;
            }
            printf("需要支付的金额:%.2lf\n", oilL * price);
        }

        else if (oilN == 95)
        {
            price = 5;
            if (oilL >= 40)
            {
                price = 4.5;
            }
            printf("需要支付的金额:%.2lf\n", oilL * price);
        }
        else
        {
             printf("没有对应的油号！！");
        }
     */

    switch (oilN)
    {
    case 92:
        price = 4;
        if (oilL >= 40)
        {
            price = 3.5;
        }
        printf("需要支付的金额:%.2lf\n", oilL * price);
        break;
    case 95:
        price = 5;
        if (oilL >= 40)
        {
            price = 4.5;
        }
        printf("需要支付的金额:%.2lf\n", oilL * price);
        break;
    default:
        break;
    }

    return 0;
}