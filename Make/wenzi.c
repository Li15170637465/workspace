#include <stdio.h>
int main(){
    printf("密码是0\n");
    int pwd=0;
    int inputpwd;
    printf("*********************请输入密码*********************\n");
    scanf("%d",&inputpwd);
    for(;inputpwd!=pwd;){
    printf("*********************密码错误，请重新输入密码*********************\n");
    scanf("%d",&inputpwd);
    }
    printf("*********************密码正确*********************\n");
    printf("*********************欢迎来到文字游戏*********************\n");
    start:
    int forward=3;
    int backward=1;
    // int upward=5;//tag
    // int downward=2;//
    int inputact;
    printf("输入3键向前移动,输入1向后移动\n");
    scanf("%d",&inputact);
    if(forward==inputact){
        printf("获得一张藏宝图");
        printf("是否打开藏宝图：\n");
        printf("1.打开藏宝图\n");
        printf("2.关上藏宝图，继续前进\n");
        int tresusemap;
        scanf("%d",&tresusemap);
        if(tresusemap==1){
            for(int i=0;i<=10;i++){
                for(int j=0;j<=20;j++){
                    if(i==j&&i==6){
                        printf(" 你");
                    }else if(j==i&&i==2){
                        printf(" ⭐");
                    }
                    // if((i==2&&(j==19||j==20)||(i==6&&(j==19||j==20)))){
                    //     printf(" ");
                    // }
                    else{
                    printf(" * ");

                    }
                }
                printf("\n");
            }
        }else{
            printf("宝藏图被风吹走了\n");
            printf("是否重新开始游戏\n");
            printf("1.重新开始\n");
            printf("2.到此结束\n");
            int choose6;
            scanf("%d",&choose6);
            if(choose6==1){
                goto start;
            }else{
            goto endend;

            }
        }
        printf("是否立即出发寻找宝藏\n");
        printf("1.立即出发\n");
        printf("2.犹豫一会儿\n");
        int choose1;
        scanf("%d",&choose1);
        if(choose1==1){
            printf("选择前进路线\n");
            printf("1.向上4米，向左4米\n");
            printf("2.向左4米，向上4米\n");
            int choose2;
            scanf("%d",&choose2);
            if(choose2==1||choose2==2){
                printf("恭喜找到宝藏⭐\n");
            }
            printf("是否进行新的周目\n");
            printf("1.当然，想看看其他可能\n");
            printf("2.不用了");
            int choose3;
            scanf("%d",&choose3);
            if(choose3==1){
                goto start;
            }else{
            goto endend;

            }
        }else{
            printf("在犹豫的时候宝藏图偷偷溜走了\n");
            printf("是否重新开始游戏\n");
            printf("1.重新开始\n");
            printf("2.到此结束\n");
            int choose5;
            scanf("%d",&choose5);
            if(choose5==1){
                goto start;
            }else{
            goto endend;

            }
        }
        
    }else if(backward==inputact){
        printf("获得一张假的藏宝图\n");
    }
        printf("是否打开藏宝图：\n");
        printf("1.打开藏宝图\n");
        printf("2.关上藏宝图，继续前进\n");
        int tresusemap;
        scanf("%d",&tresusemap);
        if(tresusemap==1){
     for(int i=0;i<=10;i++){
                for(int j=0;j<=20;j++){
                    if(i==j&&i==6){
                        printf(" 你");
                    }else if(j==i&&i==8){
                        printf(" ⭐");
                    }
                    // if((i==8&&(j==19||j==20)||(i==6&&(j==19||j==20)))){
                    //     printf(" ");
                    // }
                    else{
                    printf(" * ");

                    }
                }
                printf("\n");
            }
             printf("是否立即出发寻找宝藏\n");
             printf("1.立即出发\n");
             printf("2.犹豫一会儿\n");
             int choose8;
             scanf("%d",&choose8);
        if(choose8==1){
            printf("选择前进路线\n");
            printf("1.向下2米，向右2米\n");
            printf("2.向右2米，向下2米\n");
            int choose9;
            scanf("%d",&choose9);
            if(choose9==1||choose9==2){
                printf("恭喜找到假的宝藏 ⭐\n");
            }
            printf("是否进行新的周目\n");
            printf("1.当然，想看看其他可能\n");
            printf("2.不用了");
            int choose10;
            scanf("%d",&choose10);
            if(choose10==1){
                goto start;
            }else{
            goto endend;

            }
        }else{
            printf("宝藏图被风吹走了\n");
            printf("是否重新开始游戏\n");
            printf("1.重新开始\n");
            printf("2.到此结束\n");
            int choose7;
            scanf("%d",&choose7);
            if(choose7==1){
                goto start;
            }else{
            goto endend;

            }
        }
        printf("游戏到此结束，感谢游玩\n");
        printf("是否重新开始游戏\n");
        printf("1.重新开始\n");
        printf("2.到此结束\n");
        int choose4;
        scanf("%d",&choose4);
        if(choose4==1){
            goto start;
        }else{
            goto endend;
        }
    }else{
         printf("宝藏图被风吹走了\n");
            printf("是否重新开始游戏\n");
            printf("1.重新开始\n");
            printf("2.到此结束\n");
            int choose11;
            scanf("%d",&choose11);
            if(choose11==1){
                goto start;
            }else{
            goto endend;

            }
    }
        endend:
    return 0;
}