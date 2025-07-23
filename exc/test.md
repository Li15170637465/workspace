# ����ָ����ָ�뺯����ϰ��

������Ϊ�����һЩ����ָ���ָ�뺯������ϰ�⣬�Ѷȴӻ��������ף����������������Щ���

## ������ϰ��

### 1. ָ�뺯������

```c
#include <stdio.h>

// ����һ������ָ��ĺ���
int* create_array(int size, int init_value) {
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = init_value;
    }
    return arr;
}

int main() {
    int *my_array = create_array(5, 10);
  
    // ��ӡ����Ԫ��
    for (int i = 0; i < 5; i++) {
        printf("%d ", my_array[i]);
    }
  
    // ��Ҫ��ʲô�������ڴ�й©��
    return 0;
}
```

**���⣺**

1. ����ָ�뺯�� `create_array` �Ĺ���ԭ��  create_array�Ĺ���ԭ����ָ�����ȵ����������ʼ����
2. ���������ʲô�� �������1010101010
3. ����޸ĳ�������ڴ�й©��

### 2. ����ָ�����

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int main() {
    // ���庯��ָ��
    int (*operation)(int, int);
  
    operation = add;
    printf("5 + 3 = %d\n", operation(5, 3));
  
    operation = subtract;
    printf("5 - 3 = %d\n", operation(5, 3));
  
    return 0;
}
```

**���⣺**

1. ���ͺ���ָ�� `operation` ��������ʽ      ��������������ֵ���ݵ�����������
2. ����ָ������ָͨ���к�����		��ָͨ��洢������ַ������ָ��洢������ַ
3. ����޸Ĵ�����ӳ˷����ܣ��ں������������int  multiply(int a,int b){return a*b;}

## ������ϰ��

### 3. ����ָ������

```c
#include <stdio.h>

void greet_english() { printf("Hello!\n"); }
void greet_spanish() { printf("?Hola!\n"); }
void greet_french() { printf("Bonjour!\n"); }

int main() {
    // ��������ָ������
    void (*greetings[3])() = {greet_english, greet_spanish, greet_french};
  
    // ���������ʺ���
    for (int i = 0; i < 3; i++) {
        greetings[i]();
    }
  
    return 0;
}
```

**���⣺**

1. ���ͺ���ָ������������﷨  ������
2. ������һ���µ��ʺ����������� �ں�������������ʺ���ı���Ӧ����
3. �޸ĳ������û�����ѡ��Ҫʹ�õ��ʺ���	��forѭ����Ϊ

int n=0;
scanf("%d",&n);

char s[100]=greetings[n] ();

### 4. �ص�����Ӧ��

```c
#include <stdio.h>

// �ص��������Ͷ���
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

**���⣺**

1. ���� `callback` ���Ͷ��������   �ṩ�����������ͺͷ���ֵ����
2. `process_numbers` �������ʵ��ͨ�ô���
3. ���һ���µĻص����������ڴ�ӡ���ֵ����� ���:void printf_cubic(int num){printf("%d",num * num * num);}

## �ۺ���ϰ��

### 5. ����ָ����ṹ��

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    void (*introduce)(); // ����ָ��
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
  
    // ��Ҫ���ʲô�����������ڴ�й©��
    return 0;
}
```

**���⣺**

1. ���� `Person` �ṹ���еĺ���ָ���Ա
2. ����޸� `create_person` ����ʹ�����ȫ��
3. ��ӱ�Ҫ���ڴ��ͷŴ���

### 6. ���ӻص�ϵͳ

```c
#include <stdio.h>
#include <stdlib.h>

// ������ѧ��������ָ������
typedef int (*math_operation)(int, int);

// �򵥼������ṹ
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
  
    // ��Ҫ��ʲô���ͷ���Դ��
    return 0;
}
```

**���⣺**

1. ���� `math_operation` ���͵�����
2. `Calculator` �ṹ����η�װ��ͬ�Ĳ�����
3. ��ӳ�������������������
4. ʵ����Դ�ͷź���

## �߼���ս��

### 7. ����ָ���������㷨

```c
#include <stdio.h>

typedef int (*comparator)(int, int);

int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return b - a; }

void bubble_sort(int *arr, int size, comparator comp) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(arr[j], arr[j+1]) > 0) {
                // ����Ԫ��
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

**��ս��**

1. ���һ���µıȽ�����������ֵ��С����
2. �޸������㷨ʹ�����Ч�����������
3. ʹ������ͨ�û����ܴ���������������

### 8. ����ģʽʵ��

```c
#include <stdio.h>
#include <stdlib.h>

// ����ӿ�
typedef void (*command)();

// ��������
void command_help() { printf("Showing help information...\n"); }
void command_exit() { printf("Exiting program...\n"); exit(0); }
void command_version() { printf("Program version 1.0\n"); }

// ����ӳ��ṹ
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

**��ս��**

1. ���һ���µ����� "time"����ʾ��ǰʱ��
2. �޸ĳ���֧�ִ�����������
3. ʵ��������ʷ��¼����

## �ؼ������ܽ�

1. **ָ�뺯��**��

   - ����ָ��ĺ���
   - �﷨��`�������� *������(�����б�)`
   - �����ڶ�̬�ڴ����󷵻�
2. **����ָ��**��

   - ָ������ָ��
   - �﷨��`�������� (*ָ����)(���������б�)`
   - ��������ʱѡ����
3. **����ָ������**��

   - �洢�������ָ�������
   - ʵ�ַ��ɱ������ģʽ
4. **�ص�����**��

   - ͨ������ָ�봫�ݸ����������ĺ���
   - ʵ��ͨ���㷨�Ϳ��
5. **typedef ��**��

   - ʹ�� typedef �򻯸��Ӻ���ָ������
   - ��ߴ���ɶ���

��Щ��ϰ�⺭���˺���ָ���ָ�뺯���ĺ��ĸ����Ӧ�ó������ӻ����﷨��ʵ�����ģʽ��Ӧ�á�ͨ�������Щ���⣬�㽫�������C��������Щǿ������Լ���ʵ��Ӧ�ü�ֵ��



* ����ָ�뺯�� `create_array` �Ĺ���ԭ��  create_array�Ĺ���ԭ����ָ�����ȵ����������ʼ����
* ���������ʲô�� �������1010101010
* ����޸ĳ�������ڴ�й©��


* ���ͺ���ָ�� `operation` ��������ʽ      ��������������ֵ���ݵ�����������
* ����ָ������ָͨ���к�����		��ָͨ��洢������ַ������ָ��洢������ַ
* ����޸Ĵ�����ӳ˷����ܣ��ں������������int  multiply(int a,int b){return a*b;}



���ͺ���ָ������������﷨  ������������һ���µ��ʺ����������� �ں�������������ʺ���ı���Ӧ�����޸ĳ������û�����ѡ��Ҫʹ�õ��ʺ���	��forѭ����Ϊ

int n=0;
scanf("%d",&n);

char s[100]=greetings[n] ();



* ���� `callback` ���Ͷ��������   �ṩ�����������ͺͷ���ֵ����
* `process_numbers` �������ʵ��ͨ�ô���
* ���һ���µĻص����������ڴ�ӡ���ֵ����� ���:void printf_cubic(int num){printf("%d",num * num * num);}
