#include <stdio.h>
#include <stdbool.h>
/***********************************************************************
*   计算内存占用的大小(以字节为单位): 
    sizeof 关键字
    作用:  按照计算 1.类型 2.标识符名字 3.字面量   字节大小

    size_t:  表示字节大小的类型  占位符 %zu
     
    注意:   字面量('a',true 以上两个字面量默认都是int类型)
            bool类型 大小是1个字节
***********************************************************************/
int main(){
    int a=10;
    char c1='\n';
    bool  flag=true;
   printf("%zu\n",sizeof(int));
   printf("%zu\n",sizeof(char));
   printf("%zu\n",sizeof(a));
   printf("%zu\n",sizeof(100));
   printf("%zu\n",sizeof(1.1));
   printf("%zu\n",sizeof('\n'));
   printf("%zu\n",sizeof(c1));
   printf("%zu\n",sizeof(true));
   printf("%zu\n",sizeof(flag));


/*  size_t len=  sizeof(int);

 printf("%zu\n",len);
 printf("%llu\n",len); */
/*  printf("%d\n",len); */



 1;
 'a';

    return 0;
}