//超市系统
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
//定义一个结构体来存储商品信息
struct Product {
    char name[50];
    float price;
    int quantity;
};
//定义一个结构体来存储购物车信息
struct CartItem {
    struct Product product;
    int quantity;
}; 


int main(){
    return 0;
}