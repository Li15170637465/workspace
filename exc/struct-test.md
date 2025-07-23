# 结构体、结构体指针与typedef详解

## 一、结构体（struct）基础

### 1. 什么是结构体？

结构体是C语言中一种自定义的复合数据类型，允许将多个不同类型的数据项组合成一个单一实体。

```c
// 结构体定义
struct Student {
    char name[50];    // 字符数组
    int id;           // 整型
    float gpa;        // 浮点型
    char major[30];   // 字符数组
};
```

### 2. 结构体特点：

- **成员集合**：可以包含不同类型的数据
- **内存布局**：成员在内存中连续存储（可能有填充字节）
- **大小计算**：`sizeof(struct Student)` 返回总字节数
- **访问方式**：使用点运算符 `.`访问成员

### 3. 结构体使用示例：

```c
int main() {
    // 声明并初始化结构体变量
    struct Student s1 = {"Alice", 1001, 3.8, "Computer Science"};
  
    // 访问结构体成员
    printf("Name: %s\n", s1.name);
    printf("GPA: %.2f\n", s1.gpa);
  
    // 修改结构体成员
    s1.gpa = 3.9;
    strcpy(s1.major, "Data Science");
  
    return 0;
}
```

## 二、结构体指针

### 1. 什么是结构体指针？

指向结构体变量的指针，用于高效操作结构体。

```c
struct Student *ptr = &s1;
```

### 2. 结构体指针特点：

- **高效传递**：避免复制整个结构体
- **动态分配**：用于创建动态数据结构
- **访问方式**：使用箭头运算符 `->`访问成员

### 3. 结构体指针使用示例：

```c
void printStudent(struct Student *s) {
    printf("ID: %d\n", s->id);
    printf("Major: %s\n", s->major);
}

int main() {
    struct Student s1 = {"Bob", 1002, 3.7, "Mathematics"};
  
    // 使用结构体指针
    struct Student *ptr = &s1;
  
    // 通过指针访问成员
    printf("Name: %s\n", ptr->name);
  
    // 通过指针修改成员
    ptr->gpa = 3.75;
  
    // 传递指针给函数
    printStudent(ptr);
  
    return 0;
}
```

## 三、typedef原理与应用

### 1. typedef是什么？

`typedef`用于为已有类型创建别名，简化复杂类型声明。

```c
// 为struct Student创建别名Student
typedef struct Student Student;

// 更常见的写法（定义和typedef合并）
typedef struct {
    char name[50];
    int age;
} Person;
```

### 2. typedef工作原理：

- 编译时处理，不创建新类型
- 仅为现有类型创建新名称
- 作用域遵循变量作用域规则

### 3. typedef优势：

1. **简化复杂声明**：

   ```c
   typedef int (*Comparator)(int, int); // 函数指针类型
   ```
2. **提高可读性**：

   ```c
   typedef unsigned long ulong;
   ```
3. **平台无关性**：

   ```c
   typedef int int32; // 确保32位整数
   ```
4. **简化结构体使用**：

   ```c
   Person p1; // 代替 struct Person p1;
   ```

### 4. typedef使用示例：

```c
// 定义结构体并创建别名
typedef struct {
    char title[100];
    char author[50];
    int pages;
} Book;

// 使用别名
void printBook(Book b) {
    printf("%s by %s (%d pages)\n", b.title, b.author, b.pages);
}

int main() {
    Book book1 = {"The C Programming Language", "K&R", 274};
    printBook(book1);
    return 0;
}
```

## 四、基础练习题

### 1. 结构体基础

定义一个表示点的结构体 `Point`，包含x和y坐标（float类型）。编写程序：

- 创建两个点 (1.0, 2.0) 和 (3.5, 4.2)
- 计算并输出两点之间的距离

```c
#include <stdio.h>
#include <math.h>

// 定义结构体
typedef struct {
    float x;
    float y;
} Point;

int main() {
    Point p1 = {1.0, 2.0};
    Point p2 = {3.5, 4.2};
  
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float distance = sqrt(dx*dx + dy*dy);
  
    printf("Distance: %.2f\n", distance);
    return 0;
}
```

### 2. 结构体指针

修改上题，使用结构体指针操作点坐标：

- 通过函数修改点的坐标
- 通过函数计算距离

```c
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

// 使用指针修改点
void movePoint(Point *p, float dx, float dy) {
    p->x += dx;
    p->y += dy;
}

// 使用指针计算距离
float distance(Point *p1, Point *p2) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    Point p1 = {1.0, 2.0};
    Point p2 = {3.5, 4.2};
  
    movePoint(&p1, 0.5, -0.2);
    printf("New distance: %.2f\n", distance(&p1, &p2));
  
    return 0;
}
```

### 3. typedef应用

创建一个表示分数的结构体 `Fraction`（分子和分母），使用typedef简化：

- 实现分数加法函数
- 实现分数简化函数

```c
#include <stdio.h>

typedef struct {
    int numerator;   // 分子
    int denominator; // 分母
} Fraction;

// 最大公约数（辅助函数）
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 简化分数
void simplify(Fraction *f) {
    int divisor = gcd(f->numerator, f->denominator);
    f->numerator /= divisor;
    f->denominator /= divisor;
}

// 分数加法
Fraction addFractions(Fraction f1, Fraction f2) {
    Fraction result = {
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    };
    simplify(&result);
    return result;
}

int main() {
    Fraction a = {1, 2}; // 1/2
    Fraction b = {1, 3}; // 1/3
  
    Fraction sum = addFractions(a, b);
    printf("Sum: %d/%d\n", sum.numerator, sum.denominator);
  
    return 0;
}
```

## 五、强化理解题

### 1. 嵌套结构体

创建以下结构体：

- `Address`：街道、城市、邮编
- `Person`：姓名、年龄、地址
  实现函数：
- 打印个人信息（包含地址）
- 修改个人地址

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char street[50];
    char city[30];
    char zip[10];
} Address;

typedef struct {
    char name[50];
    int age;
    Address address;
} Person;

void printPerson(Person p) {
    printf("Name: %s\nAge: %d\nAddress: %s, %s %s\n",
           p.name, p.age, p.address.street, p.address.city, p.address.zip);
}

void updateAddress(Person *p, const char *street, const char *city, const char *zip) {
    strncpy(p->address.street, street, sizeof(p->address.street)-1);
    strncpy(p->address.city, city, sizeof(p->address.city)-1);
    strncpy(p->address.zip, zip, sizeof(p->address.zip)-1);
}

int main() {
    Person alice = {"Alice", 30, {"123 Main St", "Springfield", "12345"}};
    printPerson(alice);
  
    updateAddress(&alice, "456 Oak Ave", "Metropolis", "67890");
    printPerson(alice);
  
    return 0;
}
```

### 2. 结构体数组与指针

创建学生结构体数组（姓名、分数），实现：

- 计算平均分
- 查找最高分学生
- 使用指针遍历数组

```c
#include <stdio.h>

typedef struct {
    char name[50];
    float score;
} Student;

float averageScore(Student *students, int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].score;
    }
    return sum / count;
}

Student* findTopStudent(Student *students, int count) {
    Student *top = students;
    for (int i = 1; i < count; i++) {
        if (students[i].score > top->score) {
            top = &students[i];
        }
    }
    return top;
}

int main() {
    Student class[5] = {
        {"Alice", 85.5},
        {"Bob", 92.0},
        {"Charlie", 76.5},
        {"Diana", 88.0},
        {"Evan", 95.5}
    };
  
    int size = sizeof(class)/sizeof(class[0]);
  
    printf("Average score: %.2f\n", averageScore(class, size));
  
    Student *top = findTopStudent(class, size);
    printf("Top student: %s (%.2f)\n", top->name, top->score);
  
    return 0;
}
```

### 3. 动态结构体链表

实现简单的单向链表：

- 链表节点结构体（数据+指针）
- 添加节点函数
- 遍历链表函数
- 释放链表内存

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 添加新节点到链表头部
void addNode(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// 遍历并打印链表
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head = NULL; // 链表头指针
  
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
  
    printList(head);
  
    freeList(head);
    return 0;
}
```

## 六、总结与要点

1. **结构体要点**：

   - 使用 `struct`定义复合数据类型
   - 成员通过 `.`运算符访问
   - 内存连续但有填充（对齐要求）
2. **结构体指针要点**：

   - 使用 `->`运算符访问成员
   - 避免大结构体复制开销
   - 用于动态内存分配和数据结构
3. **typedef要点**：

   - 创建类型别名，不创建新类型
   - 简化复杂类型声明
   - 提高代码可读性和可移植性
4. **最佳实践**：

   ```c
   // 推荐写法：结构体定义与typedef合并
   typedef struct {
       // 成员
   } TypeName;

   // 使用指针传递大结构体
   void processStruct(TypeName *ptr);

   // 动态分配后检查NULL
   TypeName *obj = malloc(sizeof(TypeName));
   if (!obj) { /* 处理错误 */ }
   ```
5. **常见错误**：

   - 忘记结构体指针的 `->`而误用 `.`
   - 未初始化结构体指针就访问成员
   - 动态分配后忘记释放内存
   - 结构体复制导致性能问题（大结构体）

通过练习这些题目，你将掌握结构体和指针的核心概念，为学习更复杂的数据结构（如链表、树、图）打下坚实基础。
