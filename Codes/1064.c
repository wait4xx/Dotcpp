//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

double sum(int n);

int main()
{
    printf("%.2e", sum(30));
    return 0;
}

double sum(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        double temp = 1;
        for (int j = 1; j <= i; j++)
        {
            temp *= j;
        }
        sum += temp;
    }
    return sum;
}
