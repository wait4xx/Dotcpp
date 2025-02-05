//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

double fact(int k);

int main()
{
    int n = 0;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 1; i <= n; i++) sum += 1.0 / fact(i);
    printf("sum=%.5lf\n", sum);
    return 0;
}

double fact(int k)
{
    double result = 1;
    for (int i = 1; i <= k; i++) result *= i;
    return result;
}