#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int main()
{
    while (1)
    {
        time_t current;
        time(&current);
        int now;
        printf("%s\n", current);
    }
    return 0;
}