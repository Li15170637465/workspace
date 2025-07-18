#include <stdio.h>
#include <stdbool.h>
/***********************************************************************
*     switch 开关
            作用: 控制数据的流入
            可以接收的类型: 1.整数 2.字符类型 3.枚举
      case 常量:  可以理解为是if判断(把外部传入的数据和每一个case后的常量进行比较)
      break:关键字    控制开关是否结束  1. 有break(跳出switch) 2. 没有break (继续执行当前case 之后的case  (后续的case就不会判断了))
      default: 关键字  相当于 else （如果没有匹配到的条件,default是兜底方案）

      注意:  switch 只执行一遍

***********************************************************************/
int main()
{

    int num = 100;

    switch (num)
    {

    case 1:
        printf("传入的数据是1");
        break;

    case 2:
        printf("传入的数据是2");
        break;

    case 30:
        printf("传入的数据是30");
        break;
    default:
        printf("滚!");
        break;
    }

    printf("程序结束!!");
    return 0;
}