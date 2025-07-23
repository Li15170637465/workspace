// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// typedef struct{
//     char name[100];
//     int age;
//     double price;
// } Visitor;

// void calculatorPrice(struct Visitor *visitor){
//     if(visitor.age>18){
//         visitor->price=20;
//     }else{
//         visitor->price = 0;
//     }
// }

// int main(){
//     Visitor visitor;
//     while(1){
//         printf("Enter your name:\n");
//         scanf("%s", visitor.name);
//         if(!strcmp(visitor.name,"n")){
//             break;
//         }
//         printf("Enter your age:\n");
//         scanf("%d", &visitor.age);
        // if(visitor.age>18){
        //     visitor.price = 20;
        // }else{
        //     visitor.price = 0;
        // }
//         printf("%svisitor your price of ticket is %.2lf\n ", visitor.name, visitor.price);
//     }
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[100];
    int num;
    char gender;
    

} Person;
