# �ṹ�塢�ṹ��ָ����typedef���

## һ���ṹ�壨struct������

### 1. ʲô�ǽṹ�壿

�ṹ����C������һ���Զ���ĸ����������ͣ����������ͬ���͵���������ϳ�һ����һʵ�塣

```c
// �ṹ�嶨��
struct Student {
    char name[50];    // �ַ�����
    int id;           // ����
    float gpa;        // ������
    char major[30];   // �ַ�����
};
```

### 2. �ṹ���ص㣺

- **��Ա����**�����԰�����ͬ���͵�����
- **�ڴ沼��**����Ա���ڴ��������洢������������ֽڣ�
- **��С����**��`sizeof(struct Student)` �������ֽ���
- **���ʷ�ʽ**��ʹ�õ������ `.`���ʳ�Ա

### 3. �ṹ��ʹ��ʾ����

```c
int main() {
    // ��������ʼ���ṹ�����
    struct Student s1 = {"Alice", 1001, 3.8, "Computer Science"};
  
    // ���ʽṹ���Ա
    printf("Name: %s\n", s1.name);
    printf("GPA: %.2f\n", s1.gpa);
  
    // �޸Ľṹ���Ա
    s1.gpa = 3.9;
    strcpy(s1.major, "Data Science");
  
    return 0;
}
```

## �����ṹ��ָ��

### 1. ʲô�ǽṹ��ָ�룿

ָ��ṹ�������ָ�룬���ڸ�Ч�����ṹ�塣

```c
struct Student *ptr = &s1;
```

### 2. �ṹ��ָ���ص㣺

- **��Ч����**�����⸴�������ṹ��
- **��̬����**�����ڴ�����̬���ݽṹ
- **���ʷ�ʽ**��ʹ�ü�ͷ����� `->`���ʳ�Ա

### 3. �ṹ��ָ��ʹ��ʾ����

```c
void printStudent(struct Student *s) {
    printf("ID: %d\n", s->id);
    printf("Major: %s\n", s->major);
}

int main() {
    struct Student s1 = {"Bob", 1002, 3.7, "Mathematics"};
  
    // ʹ�ýṹ��ָ��
    struct Student *ptr = &s1;
  
    // ͨ��ָ����ʳ�Ա
    printf("Name: %s\n", ptr->name);
  
    // ͨ��ָ���޸ĳ�Ա
    ptr->gpa = 3.75;
  
    // ����ָ�������
    printStudent(ptr);
  
    return 0;
}
```

## ����typedefԭ����Ӧ��

### 1. typedef��ʲô��

`typedef`����Ϊ�������ʹ����������򻯸�������������

```c
// Ϊstruct Student��������Student
typedef struct Student Student;

// ��������д���������typedef�ϲ���
typedef struct {
    char name[50];
    int age;
} Person;
```

### 2. typedef����ԭ��

- ����ʱ����������������
- ��Ϊ�������ʹ���������
- ��������ѭ�������������

### 3. typedef���ƣ�

1. **�򻯸�������**��

   ```c
   typedef int (*Comparator)(int, int); // ����ָ������
   ```
2. **��߿ɶ���**��

   ```c
   typedef unsigned long ulong;
   ```
3. **ƽ̨�޹���**��

   ```c
   typedef int int32; // ȷ��32λ����
   ```
4. **�򻯽ṹ��ʹ��**��

   ```c
   Person p1; // ���� struct Person p1;
   ```

### 4. typedefʹ��ʾ����

```c
// ����ṹ�岢��������
typedef struct {
    char title[100];
    char author[50];
    int pages;
} Book;

// ʹ�ñ���
void printBook(Book b) {
    printf("%s by %s (%d pages)\n", b.title, b.author, b.pages);
}

int main() {
    Book book1 = {"The C Programming Language", "K&R", 274};
    printBook(book1);
    return 0;
}
```

## �ġ�������ϰ��

### 1. �ṹ�����

����һ����ʾ��Ľṹ�� `Point`������x��y���꣨float���ͣ�����д����

- ���������� (1.0, 2.0) �� (3.5, 4.2)
- ���㲢�������֮��ľ���

```c
#include <stdio.h>
#include <math.h>

// ����ṹ��
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

### 2. �ṹ��ָ��

�޸����⣬ʹ�ýṹ��ָ����������꣺

- ͨ�������޸ĵ������
- ͨ�������������

```c
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

// ʹ��ָ���޸ĵ�
void movePoint(Point *p, float dx, float dy) {
    p->x += dx;
    p->y += dy;
}

// ʹ��ָ��������
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

### 3. typedefӦ��

����һ����ʾ�����Ľṹ�� `Fraction`�����Ӻͷ�ĸ����ʹ��typedef�򻯣�

- ʵ�ַ����ӷ�����
- ʵ�ַ����򻯺���

```c
#include <stdio.h>

typedef struct {
    int numerator;   // ����
    int denominator; // ��ĸ
} Fraction;

// ���Լ��������������
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// �򻯷���
void simplify(Fraction *f) {
    int divisor = gcd(f->numerator, f->denominator);
    f->numerator /= divisor;
    f->denominator /= divisor;
}

// �����ӷ�
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

## �塢ǿ�������

### 1. Ƕ�׽ṹ��

�������½ṹ�壺

- `Address`���ֵ������С��ʱ�
- `Person`�����������䡢��ַ
  ʵ�ֺ�����
- ��ӡ������Ϣ��������ַ��
- �޸ĸ��˵�ַ

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

### 2. �ṹ��������ָ��

����ѧ���ṹ�����飨��������������ʵ�֣�

- ����ƽ����
- ������߷�ѧ��
- ʹ��ָ���������

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

### 3. ��̬�ṹ������

ʵ�ּ򵥵ĵ�������

- ����ڵ�ṹ�壨����+ָ�룩
- ��ӽڵ㺯��
- ����������
- �ͷ������ڴ�

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// ����½ڵ㵽����ͷ��
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

// ��������ӡ����
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �ͷ������ڴ�
void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head = NULL; // ����ͷָ��
  
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
  
    printList(head);
  
    freeList(head);
    return 0;
}
```

## �����ܽ���Ҫ��

1. **�ṹ��Ҫ��**��

   - ʹ�� `struct`���帴����������
   - ��Աͨ�� `.`���������
   - �ڴ�����������䣨����Ҫ��
2. **�ṹ��ָ��Ҫ��**��

   - ʹ�� `->`��������ʳ�Ա
   - �����ṹ�帴�ƿ���
   - ���ڶ�̬�ڴ��������ݽṹ
3. **typedefҪ��**��

   - �������ͱ�����������������
   - �򻯸�����������
   - ��ߴ���ɶ��ԺͿ���ֲ��
4. **���ʵ��**��

   ```c
   // �Ƽ�д�����ṹ�嶨����typedef�ϲ�
   typedef struct {
       // ��Ա
   } TypeName;

   // ʹ��ָ�봫�ݴ�ṹ��
   void processStruct(TypeName *ptr);

   // ��̬�������NULL
   TypeName *obj = malloc(sizeof(TypeName));
   if (!obj) { /* ������� */ }
   ```
5. **��������**��

   - ���ǽṹ��ָ��� `->`������ `.`
   - δ��ʼ���ṹ��ָ��ͷ��ʳ�Ա
   - ��̬����������ͷ��ڴ�
   - �ṹ�帴�Ƶ����������⣨��ṹ�壩

ͨ����ϰ��Щ��Ŀ���㽫���սṹ���ָ��ĺ��ĸ��Ϊѧϰ�����ӵ����ݽṹ������������ͼ�����¼�ʵ������
