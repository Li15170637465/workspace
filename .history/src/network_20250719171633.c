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
        time_t current;
        time(&current);
        printf("%s\n", current);
    }
    return 0;
}