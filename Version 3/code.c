#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "ExeCodeEngine.h"

#pragma warning(disable : 4996)

int main()
{
    char _prompt[32];
    T = "Lorem ipsum dolor it samet.";
    printf("\n");
    while (true)
    {
        printf("\n Enter command (only string) : ");
        if (fgets(_prompt, sizeof(_prompt), stdin) != NULL)
        {
            size_t len = strlen(_prompt);
            if (len > 0 && _prompt[len - 1] == '\n')
                _prompt[len - 1] = '\0';
            Executive(_prompt);
        }
    }
}
