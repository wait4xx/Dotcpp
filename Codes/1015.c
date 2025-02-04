//
// Created by XX on 2024/12/23.
//

# include <stdio.h>
# include <math.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    unsigned long sum_a = 0, sum_b = 0;
    double sum_c = 0;
    for (int i = 1; i <= a; i++)
    {
        sum_a += i;
    }
    for (int i = 1; i <= b; i++)
    {
        sum_b += (unsigned long)pow(i, 2);
    }
    for (int i = 1; i <= c; i++)
    {
        sum_c += 1. / i;
    }
    double sum = sum_a + sum_b + sum_c;
    printf("%.2f", sum);
    return 0;
}