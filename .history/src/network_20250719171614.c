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
        printf("%s\n", current);
        { srand((unsigned int)time(NULL));
    
    return 0;
}