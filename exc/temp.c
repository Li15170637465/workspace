// 1) 指针练习
//  定义二维数组
//     int nums[3][4] = {
//         {10, 20, 30, 40},
//         {100, 200, 300, 400},
//         {1000, 2000, 3000, 400}};
//  实现如下需求：
//    ① 定义指针，将 nums 赋值给该指针
//    ② 定义指针，将 &nums 赋值给该指针
//    ③ 定义指针，将 nums[1] 赋值给该指针
//    ④ 定义指针，将 &nums[1] 赋值给该指针
//    ⑤ 定义指针，将 &nums[1][1] 赋值给该指针
// #include<stdio.h>
// int main()
// {
//     int nums[3][4] = {
//         {10, 20, 30, 40},
//         {100, 200, 300, 400},
//         {1000, 2000, 3000, 400}
//         };
//     int (*ptr1)[4] = nums;
//     int (*ptr2)[3][4] = &nums;
//     int *ptr3 = nums[1];
//     int (*ptr4)[4] = &nums[1];
//     int *ptr5 = &nums[1][1];

//     return 0;
// }

// int (*p1)[4] = nums
// nums 是数组首行的地址，类型为"指向包含4个int的数组的指针"

// int (*p2)[3][4] = &nums
// &nums 是整个二维数组的地址，类型为"指向3x4二维数组的指针"

// int *p3 = nums[1]
// nums[1] 是第二行首元素的地址，类型为int*

// int (*p4)[4] = &nums[1]
// &nums[1] 是第二行的地址，类型与p1相同

// int *p5 = &nums[1][1]
// 直接获取第二行第二列元素的地址

// 注意：原代码最后一行数组元素应为4000（补全位数），否则会越界访问未定义内存。

// 常见错误避免：
// 不要混淆int*和int (*)[4]类型

// &nums和nums数值相同但类型不同

// 数组下标从0开始：nums[1]表示第二行

// 二维数组在内存中连续存储，可通过*(*(nums+i)+j)访问元素

// 此方案直接满足题目所有要求，并包含验证输出，清晰展示了二维数组指针的不同表示方式。

// 2）小狗案例
// （1）编写一个Dog结构体，包含name(char *)、age(int)、weight(double)属性。
// （2）编写一个say函数，返回字符串，方法返回信息中包含所有成员值。
// （3）在main函数中，创建Dog结构体变量，调用say函数，将调用结果打印输出。

// #include<stdio.h>
// #include<string.h>

//     struct Dog
// {
//     char *name;
//     int age;
//     double weight;
// };

// char *say(struct Dog dog)
// {
//     static char info[50];
//     sprintf(info, "name=%s age=%d weight=%.2f", dog.name, dog.age, dog.weight);
//     return info;
// }

// int main()
// {
//     struct Dog dog;
//     char *info = NULL;
//     dog.name = "hua";
//     dog.age = 10;
//     dog.weight = 20;
//     info = say(dog);
//     printf("%s\n", info);
//     printf("%s\n", dog.name);
//     return 0;
// }



// int (*ptr1)[4] = nums;
// int (*ptr2)[3][4] = &nums;
// int *ptr3 = nums[1];
// int (*ptr4)[4] = &nums[1];
// int *ptr5 = nums[1][1];

// #include<stdio.h>
// #include<stdlib.h>

// struct Dog{
//     char name[10];
//     int age;
//     float weight;
// };

// char *say()
// {   
//     static char content[100];
//     struct Dog dog;
//     printf("Enter the name of dog:\n");
//     scanf("%s", dog.name);
//     printf("Enter the age of dog:\n");
//     scanf("%d", &dog.age);
//     printf("Enter the weight of dog:\n");
//     scanf("%f", &dog.weight);
//     struct Dog *dogptr = &dog;
//     dogptr->age = 1;
//     sprintf(content, "dog name:%s dog age:%d dog weight:%f", dog.name, dog.age, dog.weight);
//     printf("%d", dogptr->age);
//     return content;
// }

// int main(){
//     struct Dog dog;
//     // struct Dog *dogptr = &dog;

//     // dogptr->age = 1;
//     printf("%s", say());
//     return 0;
// }

// struct Student{
//     char name[100];
//     int age;
//     char gender;
//     int id;
// };

// int main(){
//     struct Student stu1 = {.id = 1, .name = "tom", .age = 20, .gender = 'm'};
//     struct Student stu2 = {.id = 1, .name = "tom", .age = 20, .gender = 'm'};
//     struct Student students[2] = {stu1, stu2};
//     for (int i = 1; i < 3;i++){
//         printf("students[%d] id:%d name:%s age:%d gender:%c\n", i,students[i].id, students[i].name, students[i].age, students[i].gender);
        
//     }
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>

// struct Student{
//     char name[100];
//     int age;
//     int id;
//     char gender;
// };

// int main(){
//     struct Student stu1 = {.name = "Wi", .age = 11, .id = 1001, .gender = 'f'};
//     struct Student stu2 = {.name = "Mi", .age = 11, .id = 1002, .gender = 'm'};
//     struct Student Students[2] = {stu1, stu2};
//     for (int i = 0; i < 2;i++){
//         printf("Student[%d],name:%s,age:%d,id:%d,gender:%c\n", i, Students[i].name, Students[i].age, Students[i].id, Students[i].gender);
        
//     }
//     return 0;
// }