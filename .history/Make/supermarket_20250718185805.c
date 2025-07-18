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
void addToCart(struct Supermarket *supermarket, int productIndex, int quantity) {
    if (productIndex < 0 || productIndex >= supermarket->productCount) {
        printf("无效的商品编号。\n");
        return;
    }
    if (quantity <= 0 || quantity > supermarket->products[productIndex].quantity) {
        printf("无效的购买数量。\n");
        return;
    }
    //检查购物车是否已满
    if (supermarket->cartCount >= 100) {
        printf("购物车已满，无法添加更多商品。\n");
        return;
    }
    //添加商品到购物车
    supermarket->cart[supermarket->cartCount].product = supermarket->products[productIndex];
    supermarket->cart[supermarket->cartCount].quantity = quantity;
    supermarket->cartCount++;
    //更新库存
    supermarket->products[productIndex].quantity -= quantity;
    printf("已将 %d 个 %s 添加到购物车。\n", quantity, supermarket->products[productIndex].name);
}
void viewCart(struct Supermarket *supermarket) {
    if (supermarket->cartCount == 0) {
        printf("购物车为空。\n");
        return;
    }
    printf("购物车内容:\n");
    for (int i = 0; i < supermarket->cartCount; i++) {
        printf("%d. %s - %.2f元 (数量: %d)\n", i + 1, supermarket->cart[i].product.name, supermarket->cart[i].product.price, supermarket->cart[i].quantity);
    }   
}
void checkout(struct Supermarket *supermarket) {
    if (supermarket->cartCount == 0) {
        printf("购物车为空，无法结账。\n");
        return;
    }
    float total = 0.0;
    printf("结账信息:\n");
    for (int i = 0; i < supermarket->cartCount; i++) {
int main(){
    return 0;
}