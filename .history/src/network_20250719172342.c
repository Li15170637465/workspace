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
        printf("random number:%d\n", rand % 10 + 1);
        for (int i = 0; i < rand % 10 + 1; i++)
        {
            f1(rand)
        }
        time_t current;
        time(&current);
        printf("%s\n", current);
    }
    return 0;
}