#include <stdio.h>
#include <stdbool.h>

#define BOOL  int
#define TRUE   1
#define FALSE   0

/***********************************************************************
*  布尔类型(真true假false类型):
   使用场景: 在逻辑判断中使用


   c语言提供的bool类型有哪些?
    1. 在头文件中include <stdbool.h> 关键字 bool  注意: 类型的值只有两种(1 true  0 false)
    2. 不需要导入任何的头文件, 直接使用c提前准备的关键字_Bool表示布尔类型   注意: (0 false  非零的数字:  true )   
    3. 使用宏定义 自定义布尔类型

***********************************************************************/
int main(){
//   bool  flag=false;  
 //_Bool  flag=-2;  
  BOOL flag=FALSE;
 printf("%d\n",flag);
 if(flag){
    printf("flag=true");
 }else{
     printf("flag=false");
 }

    return 0;
}