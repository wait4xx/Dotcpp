//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

void str_connect(char *str1, char *str2, char *str3);

int main()
{
    char str1[100], str2[100], str3[200];
    scanf("%s", str1);
    scanf("%s", str2);
    str_connect(str1, str2, str3);
    printf("%s", str3);
    return 0;
}

// 连接两个字符串
// 指针先指向字符串1末尾，然后递归调用，每次调用指针向前移动一位，直到指针指向字符串1首位
// 然后指针指向字符串2首位，递归调用，每次调用指针向后移动一位，直到指针指向字符串2末尾
void str_connect(char *str1, char *str2, char *str3)
{
    if (*str1 == '\0')
    {
        if (*str2 == '\0')
        {
            return;
        }
        *str3 = *str2;
        str_connect(str1, str2 + 1, str3 + 1);
    }
    else
    {
        *str3 = *str1;
        str_connect(str1 + 1, str2, str3 + 1);
    }
}
