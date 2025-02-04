//
// Created by XX on 2025/2/2.
//

#include <stdio.h>

void alphabet_encryption(char *str);

int main()
{
    char input_str[100];
    fgets(input_str, sizeof(input_str), stdin);
    alphabet_encryption(input_str);
    printf("%s\n", input_str);
    return 0;
}

void alphabet_encryption(char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str < 'z')
        {
            *str += 1;
        }
        else if (*str >= 'z')
        {
            *str = 'a';
        }
        str++;
    }
}