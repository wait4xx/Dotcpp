//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

int calculate_factor(int m, int n);
int calculate_multiple(int m, int n);

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n%d", calculate_factor(m, n), calculate_multiple(m, n));
    return 0;
}

int calculate_factor(int m, int n)
{
    return m % n == 0 ? n : calculate_factor(n, m % n);
}

int calculate_multiple(int m, int n)
{
    return m * n / calculate_factor(m, n);
}