//
// Created by XX on 2025/2/2.
//

#include <stdio.h>
#include <string.h>

void print_string_sort(char *str_one, char *str_two, char *str_three);

int main()
{
    char input_one[100], input_two[100], input_three[100];
    scanf("%s", input_one);
    scanf("%s", input_two);
    scanf("%s", input_three);
    print_string_sort(input_one, input_two, input_three);
    return 0;
}

// strcmp用于比较两个字符串，如果str1 < str2，返回负数；如果str1 > str2，返回正数；如果str1 = str2，返回0
void print_string_sort(char *str_one, char *str_two, char *str_three)
{
    char *temp;
    if (strcmp(str_one, str_two) > 0)
    {
        temp = str_one;
        str_one = str_two;
        str_two = temp;
    }
    if (strcmp(str_one, str_three) > 0)
    {
        temp = str_one;
        str_one = str_three;
        str_three = temp;
    }
    if (strcmp(str_two, str_three) > 0)
    {
        temp = str_two;
        str_two = str_three;
        str_three = temp;
    }
    printf("%s\n", str_one);
    printf("%s\n", str_two);
    printf("%s\n", str_three);
}

// Another solution
// #include <stdio.h>
// #include <string.h>
//
// #define COUNT 3
// #define MAX_LEN 100
//
// int main() {
//     char strs[COUNT][MAX_LEN];
//     char temp[MAX_LEN];
//
//     // 输入多个字符串
//     printf("输入%d个字符串：\n", COUNT);
//     for (int i = 0; i < COUNT; i++) {
//         fgets(strs[i], MAX_LEN, stdin);
//         strs[i][strcspn(strs[i], "\n")] = '\0';
//     }
//
//     // 冒泡排序
//     for (int i = 0; i < COUNT-1; i++) {
//         for (int j = 0; j < COUNT-1-i; j++) {
//             if (strcmp(strs[j], strs[j+1]) > 0) {
//                 strcpy(temp, strs[j]);
//                 strcpy(strs[j], strs[j+1]);
//                 strcpy(strs[j+1], temp);
//             }
//         }
//     }
//
//     // 输出结果
//     printf("\n排序结果：\n");
//     for (int i = 0; i < COUNT; i++) {
//         printf("%s\n", strs[i]);
//     }
//
//     return 0;
// }