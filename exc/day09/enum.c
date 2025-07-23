#include <stdio.h>
// 创建一个枚举类型
/*
   enum: 枚举类型关键字
   test: 枚举类型的名字
   注意: enum +枚举名字 作为枚举类型
   {}  : 枚举元素的代码块
   枚举元素:
     1.是一个常量且值是默认从0开始之后的常量值自动递增,唯一的
     2. 枚举的元素类型是int类型的整数
     3. 元素的名字一般大写

   注意: 枚举类型的变量保存的值 必须是枚举元素的值


  枚举的使用场景:  在有固定的值范围要求:  比如 季节,性别

*/
enum test
{
    a = 100,
    b = 110,
    c = 112
};

enum Season
{
    SPRING = 1,
    SUMMBER,
    AUTUMN,
    WINTER
};

//定义枚举类型: 约束性别
enum Gender{
     FEMALE, 
     MALE
     
};


//自定义枚举类型enum Test2 其中 t1是枚举类型变量的名字
enum Test2{
  a,b
}t1,t2,t3;


//自定义枚举类型 enum : 枚举类型的名字可以省略 
enum {
  a,b
}t11,t22,t33;



int main()
{
    
 

    // 声明枚举类型的变量 t(变量的名字)
    enum test t = b;
    printf("%d\n", t);

    // 声明变量保存季节的值
    //   enum Season season =SPRING;

    enum Season season;
    printf("请选择对应的季节:(1.春天  2.夏天  3.秋天  4.冬天)");
    scanf("%d", (int *)&season);

    // 1.整数 2.字符 3.枚举
    switch (season)
    {
    case SPRING:
       printf("春天!");
        break;
    case SUMMBER:
       printf("夏天!");
        break;

    case AUTUMN:
       printf("秋天!");
        break;
    case WINTER:
       printf("冬天!");
        break;                
    default:
       printf("季节不匹配");
        break;
    }


    //要求用户在控制台录入学生的性别
    //  printf("请选择性别1.男 2.女");
    //  int choose;
    //  scanf("%d",&choose);

    //  if(choose==1){
    //       printf("男");
    //  }else if(choose==2){
    //       printf("女");
         
    //  }



      printf("请选择性别1.男 2.女");
      enum Gender gender;
      scanf("%d",(int *)&gender);
      if(gender==MALE){
        printf("男");
      }else if(gender==FEMALE){
        printf("女");
      }


    return 0;
}