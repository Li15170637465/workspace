# 函数指针与指针函数练习题

下面我为你设计一些函数指针和指针函数的练习题，难度从基础到进阶，帮助你深入理解这些概念。

## 基础练习题

### 1. 指针函数基础

```c
#include <stdio.h>

// 定义一个返回指针的函数
int* create_array(int size, int init_value) {
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = init_value;
    }
    return arr;
}

int main() {
    int *my_array = create_array(5, 10);
  
    // 打印数组元素
    for (int i = 0; i < 5; i++) {
        printf("%d ", my_array[i]);
    }
  
    // 需要做什么来避免内存泄漏？
    return 0;
}
```

**问题：**

1. 解释指针函数 `create_array` 的工作原理  create_array的工作原理：将指定长度的整形数组初始化。
2. 程序输出是什么？ 程序输出1010101010
3. 如何修改程序避免内存泄漏？

### 2. 函数指针基础

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int main() {
    // 定义函数指针
    int (*operation)(int, int);
  
    operation = add;
    printf("5 + 3 = %d\n", operation(5, 3));
  
    operation = subtract;
    printf("5 - 3 = %d\n", operation(5, 3));
  
    return 0;
}
```

**问题：**

1. 解释函数指针 `operation` 的声明方式      将两个整形数据值传递到函数声明中
2. 函数指针与普通指针有何区别？		普通指针存储变量地址，函数指针存储函数地址
3. 如何修改代码添加乘法功能？在函数声明中添加int  multiply(int a,int b){return a*b;}

## 进阶练习题

### 3. 函数指针数组

```c
#include <stdio.h>

void greet_english() { printf("Hello!\n"); }
void greet_spanish() { printf("?Hola!\n"); }
void greet_french() { printf("Bonjour!\n"); }

int main() {
    // 创建函数指针数组
    void (*greetings[3])() = {greet_english, greet_spanish, greet_french};
  
    // 调用所有问候函数
    for (int i = 0; i < 3; i++) {
        greetings[i]();
    }
  
    return 0;
}
```

**问题：**

1. 解释函数指针数组的声明语法  空类型
2. 如何添加一个新的问候函数（如德语）？ 在函数声明中添加问候语，改变相应数据
3. 修改程序让用户可以选择要使用的问候语	将for循环改为

int n=0;
scanf("%d",&n);

char s[100]=greetings[n] ();

### 4. 回调函数应用

```c
#include <stdio.h>

// 回调函数类型定义
typedef void (*callback)(int);

void process_numbers(int *arr, int size, callback func) {
    for (int i = 0; i < size; i++) {
        func(arr[i]);
    }
}

void print_number(int num) {
    printf("%d ", num);
}

void print_square(int num) {
    printf("%d ", num * num);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
  
    printf("Original numbers: ");
    process_numbers(numbers, size, print_number);
    printf("\n");
  
    printf("Squares: ");
    process_numbers(numbers, size, print_square);
    printf("\n");
  
    return 0;
}
```

**问题：**

1. 解释 `callback` 类型定义的作用   提供参数传递类型和返回值类型
2. `process_numbers` 函数如何实现通用处理？
3. 添加一个新的回调函数，用于打印数字的立方 添加:void printf_cubic(int num){printf("%d",num * num * num);}

## 综合练习题

### 5. 函数指针与结构体

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    void (*introduce)(); // 函数指针
} Person;

void introduce_john() {
    printf("Hi, I'm John!\n");
}

void introduce_sarah() {
    printf("Hello, I'm Sarah!\n");
}

Person* create_person(const char *name, void (*introduce_func)()) {
    Person *p = (Person*)malloc(sizeof(Person));
    p->name = strdup(name);
    p->introduce = introduce_func;
    return p;
}

int main() {
    Person *john = create_person("John", introduce_john);
    Person *sarah = create_person("Sarah", introduce_sarah);
  
    john->introduce();
    sarah->introduce();
  
    // 需要添加什么代码来避免内存泄漏？
    return 0;
}
```

**问题：**

1. 解释 `Person` 结构体中的函数指针成员
2. 如何修改 `create_person` 函数使其更安全？
3. 添加必要的内存释放代码

### 6. 复杂回调系统

```c
#include <stdio.h>
#include <stdlib.h>

// 定义数学操作函数指针类型
typedef int (*math_operation)(int, int);

// 简单计算器结构
typedef struct {
    math_operation add;
    math_operation subtract;
    math_operation multiply;
} Calculator;

int add_impl(int a, int b) { return a + b; }
int subtract_impl(int a, int b) { return a - b; }
int multiply_impl(int a, int b) { return a * b; }

Calculator* create_calculator() {
    Calculator *calc = (Calculator*)malloc(sizeof(Calculator));
    calc->add = add_impl;
    calc->subtract = subtract_impl;
    calc->multiply = multiply_impl;
    return calc;
}

int main() {
    Calculator *my_calc = create_calculator();
  
    printf("5 + 3 = %d\n", my_calc->add(5, 3));
    printf("5 - 3 = %d\n", my_calc->subtract(5, 3));
    printf("5 * 3 = %d\n", my_calc->multiply(5, 3));
  
    // 需要做什么来释放资源？
    return 0;
}
```

**问题：**

1. 解释 `math_operation` 类型的作用
2. `Calculator` 结构体如何封装不同的操作？
3. 添加除法操作并处理除零错误
4. 实现资源释放函数

## 高级挑战题

### 7. 函数指针与排序算法

```c
#include <stdio.h>

typedef int (*comparator)(int, int);

int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return b - a; }

void bubble_sort(int *arr, int size, comparator comp) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(arr[j], arr[j+1]) > 0) {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int numbers[] = {5, 2, 8, 1, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);
  
    printf("Original array: ");
    for (int i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n");
  
    bubble_sort(numbers, size, ascending);
    printf("Ascending order: ");
    for (int i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n");
  
    bubble_sort(numbers, size, descending);
    printf("Descending order: ");
    for (int i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n");
  
    return 0;
}
```

**挑战：**

1. 添加一个新的比较器，按绝对值大小排序
2. 修改排序算法使其更高效（如快速排序）
3. 使排序函数通用化，能处理任意数据类型

### 8. 命令模式实现

```c
#include <stdio.h>
#include <stdlib.h>

// 命令接口
typedef void (*command)();

// 具体命令
void command_help() { printf("Showing help information...\n"); }
void command_exit() { printf("Exiting program...\n"); exit(0); }
void command_version() { printf("Program version 1.0\n"); }

// 命令映射结构
typedef struct {
    const char *name;
    command cmd;
} CommandEntry;

int main() {
    CommandEntry commands[] = {
        {"help", command_help},
        {"exit", command_exit},
        {"version", command_version}
    };
    int num_commands = sizeof(commands) / sizeof(commands[0]);
  
    char input[20];
    while (1) {
        printf("> ");
        scanf("%s", input);
    
        int found = 0;
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].name) == 0) {
                commands[i].cmd();
                found = 1;
                break;
            }
        }
    
        if (!found) {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }
  
    return 0;
}
```

**挑战：**

1. 添加一个新的命令 "time"，显示当前时间
2. 修改程序支持带参数的命令
3. 实现命令历史记录功能

## 关键概念总结

1. **指针函数**：

   - 返回指针的函数
   - 语法：`返回类型 *函数名(参数列表)`
   - 常用于动态内存分配后返回
2. **函数指针**：

   - 指向函数的指针
   - 语法：`返回类型 (*指针名)(参数类型列表)`
   - 允许运行时选择函数
3. **函数指针数组**：

   - 存储多个函数指针的数组
   - 实现分派表或命令模式
4. **回调函数**：

   - 通过函数指针传递给其他函数的函数
   - 实现通用算法和框架
5. **typedef 简化**：

   - 使用 typedef 简化复杂函数指针声明
   - 提高代码可读性

这些练习题涵盖了函数指针和指针函数的核心概念和应用场景，从基础语法到实际设计模式的应用。通过解决这些问题，你将深入理解C语言中这些强大的特性及其实际应用价值。



* 解释指针函数 `create_array` 的工作原理  create_array的工作原理：将指定长度的整形数组初始化。
* 程序输出是什么？ 程序输出1010101010
* 如何修改程序避免内存泄漏？


* 解释函数指针 `operation` 的声明方式      将两个整形数据值传递到函数声明中
* 函数指针与普通指针有何区别？		普通指针存储变量地址，函数指针存储函数地址
* 如何修改代码添加乘法功能？在函数声明中添加int  multiply(int a,int b){return a*b;}



解释函数指针数组的声明语法  空类型如何添加一个新的问候函数（如德语）？ 在函数声明中添加问候语，改变相应数据修改程序让用户可以选择要使用的问候语	将for循环改为

int n=0;
scanf("%d",&n);

char s[100]=greetings[n] ();



* 解释 `callback` 类型定义的作用   提供参数传递类型和返回值类型
* `process_numbers` 函数如何实现通用处理？
* 添加一个新的回调函数，用于打印数字的立方 添加:void printf_cubic(int num){printf("%d",num * num * num);}
