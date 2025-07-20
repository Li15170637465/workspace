#include <stdio.h>
#include <windows.h>

extern int a;
int f1(){
    return 1;
}
//gcc .\file1.c 


int main(){
    int n=f1();
    int m = 10;
    pirntf("Enter the numbers of file:");
    int b;
    for (int i = 0; i < m;i++){
        printf(".\file%d.c ", i);
    }
        printf("%d\n", n);
    printf("%d\n", a);
    scanf("%d", &b);
    // system("pause");
    return 0;
}