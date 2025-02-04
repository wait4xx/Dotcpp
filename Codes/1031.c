//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

void print_str(char *str);

int main()
{
    char str[100];
    scanf("%s", str);
    print_str(str);
    return 0;
}

// 倒叙输出字符串（递归）
// 指针先指向字符串末尾，然后递归调用，每次调用指针向前移动一位，直到指针指向字符串首位
void print_str(char *str)
{
    if (*str == '\0')
    {
        return;
    }
    print_str(str + 1);
    printf("%c", *str);
}