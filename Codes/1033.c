//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

void char_extract(char *str, char *c);

int main()
{
    char str[100], c[5] = {'a', 'e', 'i', 'o', 'u'};
    scanf("%s", str);
    char_extract(str, c);
    return 0;
}

void char_extract(char *str, char *c)
{
    if (*str == '\0')
    {
        return;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (*str == c[i])
            {
                printf("%c", *str);
                break;
            }
        }
        char_extract(str + 1, c);
    }
}