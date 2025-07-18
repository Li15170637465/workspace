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

//定义一个结构体来存储超市信息
struct Supermarket {
    struct Product products[100];
    int productCount;
    struct CartItem cart[100];
    int cartCount;
};
//函数声明
void displayProducts(struct Supermarket *supermarket);
void addToCart(struct Supermarket *supermarket, int productIndex, int quantity);
void viewCart(struct Supermarket *supermarket);
void checkout(struct Supermarket *supermarket);
void clearCart(struct Supermarket *supermarket);
void displayProducts(struct Supermarket *supermarket) {
    printf("超市商品列表:\n");
    for (int i = 0; i < supermarket->productCount; i++) {
        printf("%d. %s - %.2f元 (库存: %d)\n", i + 1, supermarket->products[i].name, supermarket->products[i].price, supermarket->products[i].quantity);
    }
}
int main(){
    return 0;
}