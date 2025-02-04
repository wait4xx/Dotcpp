//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

int max_common_divisor(int a, int b);
int min_common_multiple(int a, int b);

int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", max_common_divisor(a, b), min_common_multiple(a, b));
    return 0;
}

// 欧几里得算法（Euclidean algorithm）
int max_common_divisor(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int min_common_multiple(int a, int b)
{
    return a * b / max_common_divisor(a, b);
}