// 1) ָ����ϰ
//  �����ά����
//     int nums[3][4] = {
//         {10, 20, 30, 40},
//         {100, 200, 300, 400},
//         {1000, 2000, 3000, 400}};
//  ʵ����������
//    �� ����ָ�룬�� nums ��ֵ����ָ��
//    �� ����ָ�룬�� &nums ��ֵ����ָ��
//    �� ����ָ�룬�� nums[1] ��ֵ����ָ��
//    �� ����ָ�룬�� &nums[1] ��ֵ����ָ��
//    �� ����ָ�룬�� &nums[1][1] ��ֵ����ָ��
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
// nums ���������еĵ�ַ������Ϊ"ָ�����4��int�������ָ��"

// int (*p2)[3][4] = &nums
// &nums ��������ά����ĵ�ַ������Ϊ"ָ��3x4��ά�����ָ��"

// int *p3 = nums[1]
// nums[1] �ǵڶ�����Ԫ�صĵ�ַ������Ϊint*

// int (*p4)[4] = &nums[1]
// &nums[1] �ǵڶ��еĵ�ַ��������p1��ͬ

// int *p5 = &nums[1][1]
// ֱ�ӻ�ȡ�ڶ��еڶ���Ԫ�صĵ�ַ

// ע�⣺ԭ�������һ������Ԫ��ӦΪ4000����ȫλ�����������Խ�����δ�����ڴ档

// ����������⣺
// ��Ҫ����int*��int (*)[4]����

// &nums��nums��ֵ��ͬ�����Ͳ�ͬ

// �����±��0��ʼ��nums[1]��ʾ�ڶ���

// ��ά�������ڴ��������洢����ͨ��*(*(nums+i)+j)����Ԫ��

// �˷���ֱ��������Ŀ����Ҫ�󣬲�������֤���������չʾ�˶�ά����ָ��Ĳ�ͬ��ʾ��ʽ��

// 2��С������
// ��1����дһ��Dog�ṹ�壬����name(char *)��age(int)��weight(double)���ԡ�
// ��2����дһ��say�����������ַ���������������Ϣ�а������г�Աֵ��
// ��3����main�����У�����Dog�ṹ�����������say�����������ý����ӡ�����

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