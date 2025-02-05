//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

int ten2eight(int n);

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", ten2eight(n));
    return 0;
}

int ten2eight(int n)
{
    int result = 0;
    int base = 1;
    while (n)
    {
        result += n % 8 * base;
        n /= 8;
        base *= 10;
    }
    return result;
}