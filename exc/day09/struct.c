#include <stdio.h>
#include <string.h>
/***********************************************************************
*  struct: C语言中的自定义类型(结构体类型)
   结构体类型: 可以对多种类型的数据进行统一分类
   结构体的成员: 由各种类型的变量组成




   创建结构体类型的变量: struct Student 变量的名字(stu)
   使用结构体中的成员:  结构体变量调用成员(stu.xxx)



   //初始化数据:  1.   struct Student stu1={1001,"张三",'f',10};  要求: 值的顺序必须和结构体中成员的顺序一致
                 2.   struct Student stu3={.age=30,.id=1003,.gender='f',.name="王五"};  使用 .   通过指定成员的名字给他们赋值


   //控制台录入:  1. 录入数组的数据不要使用 &        原因: 数组的名字就是地址
                 2. 录入字符前先使用getchar()函数 读取缓冲区中的换行符       
***********************************************************************/
/*
  struct Student: 结构体类型
*/
struct Student
{
    int id;        // 学号
    char name[50]; // 姓名
    // char *name;//姓名的指针
    char gender; // 性别
    int age;     // 年龄
};

// int main()
// {
//     // 2个学生的信息
//     struct Student stu1;
//     stu1.id = 1001;
//     strcpy(stu1.name, "tom");
//     stu1.gender = 'm';
//     stu1.age = 20;

//     struct Student stu2;

//     stu2.id = 1002;
//     strcpy(stu2.name, "jack");
//     stu2.gender = 'm';
//     stu2.age = 21;
//     printf("%d,%d",stu1.id,stu2.id);
//     return 0;
// }


// int main(){
//     //声明结构体变量的同时并赋值(初始化)
//   struct Student stu1={1001,"张三",'f',10};
//   struct Student stu2={1002,"李四",'m',20};
//   struct Student stu3={.age=30,.id=1003,.gender='f',.name="王五"};

//   printf("%s,%s,%d,%s",stu1.name,stu2.name,stu3.id,stu3.name);

//     return  0;
// }


int main(){
   struct Student stu1;
   printf("请输入学生的学号");
   scanf("%d",&stu1.id);

   printf("请输入学生的姓名");
   scanf("%s",stu1.name);

   printf("请输入学生的性别");
   //手动删除缓冲区中的换行符\n
   getchar();//读取缓冲区中的字符
   scanf("%c",&stu1.gender);   

   printf("请输入学生的年龄");
   scanf("%d",&stu1.age); 
   
   

   printf("%s,%d",stu1.name,stu1.age);
    return  0;
}