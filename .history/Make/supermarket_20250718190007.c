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
        float itemTotal = supermarket->cart[i].product.price * supermarket->cart[i].quantity;
        total += itemTotal;
        printf("%s - %.2f元 (数量: %d) - 小计: %.2f元\n", supermarket->cart[i].product.name, supermarket->cart[i].product.price, supermarket->cart[i].quantity, itemTotal);
    }
    printf("总计: %.2f元\n", total);
    //清空购物车            
    clearCart(supermarket);
}
void clearCart(struct Supermarket *supermarket) {
    supermarket->cartCount = 0;
    printf("购物车已清空。\n");
}   


int main(){
    struct Supermarket supermarket;
    supermarket.productCount = 0;
    supermarket.cartCount = 0;
    //添加一些商品到超市
    strcpy(supermarket.products[supermarket.productCount].name, "苹果");
    supermarket.products[supermarket.productCount].price = 3.5;
    supermarket.products[supermarket.productCount].quantity = 100;
    supermarket.productCount++; 
    strcpy(supermarket.products[supermarket.productCount].name, "香蕉");
    supermarket.products[supermarket.productCount].price = 2.0;
    supermarket.products[supermarket.productCount].quantity = 150;
    supermarket.productCount++;
    strcpy(supermarket.products[supermarket.productCount].name, "橙子");
    supermarket.products[supermarket.productCount].price = 4.0;
    supermarket.products[supermarket.productCount].quantity = 80;
    supermarket.productCount++;
    strcpy(supermarket.products[supermarket.productCount].name, "牛奶");
    supermarket.products[supermarket.productCount].price = 5.0;
    supermarket.products[supermarket.productCount].quantity = 50;
    supermarket.productCount++;         
    strcpy(supermarket.products[supermarket.productCount].name, "面包");
    supermarket.products[supermarket.productCount].price = 2.5;
    supermarket.products[supermarket.productCount].quantity = 200;
    supermarket.productCount++; 
    int choice;
    while (1) {
        printf("\n欢迎来到超市系统！\n");
        printf("1. 查看商品\n");
        printf("2. 添加商品到购物车\n");
        printf("3. 查看购物车\n");
        printf("4. 结账\n");
        printf("5. 清空购物车\n");
        printf("6. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayProducts(&supermarket);
                break;
            case 2: {
                int productIndex, quantity;
                displayProducts(&supermarket);
                printf("请输入要添加到购物车的商品编号: ");
                scanf("%d", &productIndex);
                printf("请输入购买数量: ");
                scanf("%d", &quantity);
                addToCart(&supermarket, productIndex - 1, quantity);
                break;
            }
            case 3:
                viewCart(&supermarket);
                break;                  
            case 4:
                checkout(&supermarket);
                break;      
            case 5:
                clearCart(&supermarket);        
                break;
            case 6:
                printf("感谢使用超市系统，再见！\n");
                exit(0);
            default:
                printf("无效的选择，请重新输入。\n");
        }
    }   
    
    return 0;
}