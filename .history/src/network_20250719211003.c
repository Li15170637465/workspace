#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int main()
{
    while (1)
    {
        srand((unsigned int)time(NULL));
        int a = rand() % 10 + 1;
        printf("random number:%d\n", a);
        for (int i = 0; i < a; i++)
        {
            int sum=//f1(a);
            printf("sum=%d\n", sum);
        }
        // time_t current;
        // time(&current);
        // printf("%s\n", current);
    }
    return 0;
}