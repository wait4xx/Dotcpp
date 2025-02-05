//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

struct statics {
    int count_alpha;
    int count_space;
    int count_number;
    int count_other;
};

struct statics count(char *str);

int main()
{
    char str[1000];
    struct statics result;
    gets(str);
    result = count(str);
    printf("%d\n%d\n%d\n%d\n", result.count_alpha, result.count_space, result.count_number, result.count_other);
    return 0;
}

struct statics count(char *str)
{
    struct statics result = {0, 0, 0, 0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') result.count_alpha++;
        else if (str[i] == ' ') result.count_space++;
        else if (str[i] >= '0' && str[i] <= '9') result.count_number++;
        else result.count_other++;
    }
    return result;
}