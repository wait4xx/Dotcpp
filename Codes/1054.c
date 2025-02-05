//
// Created by XX on 2025/2/5.
//

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);

int main()
{
    int m = 0, n = 0;
    long sum = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if (is_prime(i)) sum += i;
    }
    printf("%ld\n", sum);
    return 0;
}

bool is_prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}