//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

int sum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum(n));
    return 0;
}

int sum(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += i * 3 + 2;
    return sum;
}