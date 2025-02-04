//
// Created by XX on 2025/2/2.
//

# include <stdio.h>

void string_statistics(char *str_one);

int main()
{
    char str_zero[200];
    fgets(str_zero, sizeof(str_zero), stdin);
    string_statistics(str_zero);
    return 0;
}

// 字符串统计
void string_statistics(char *str_one)
{
    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
    if (*str_one == '\0')
    {
        return;
    }
    while (*str_one != '\0' && *str_one != '\n')
    {
        if (*str_one >= 'a' && *str_one <= 'z' || *str_one >= 'A' && *str_one <= 'Z')
        {
            count_1++;
        }
        else if (*str_one >= '0' && *str_one <= '9')
        {
            count_2++;
        }
        else if (*str_one == ' ')
        {
            count_3++;
        }
        else
        {
            count_4++;
        }
        str_one++;
    }
    printf("%d %d %d %d\n", count_1, count_2, count_3, count_4);
}