//
// Created by XX on 2025/2/2.
//

#include <stdio.h>

void print_real_number(float num);

int main()
{
    float num;
    scanf("%f", &num);
    print_real_number(num);
    return 0;
}

void print_real_number(float num)
{
    printf("%6.2f\n", num);
    printf("%6.2f %6.2f\n", num, num);
    printf("%6.2f %6.2f %6.2f\n", num, num, num);
}

// 循环版本
// void print_real_number(float num) {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j <= i; j++) {
//             printf("%6.2f ", num);  // 统一用空格分隔
//         }
//         printf("\n");  // 每行末尾换行
//     }
// }
