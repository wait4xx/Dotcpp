//
// Created by XX on 2025/2/5.
//

#include <stdio.h>
#include <math.h>

double func(double x);

int main()
{
    double x;
    scanf("%lf", &x);
    double result = func(x);
    printf("%.2lf\n", result);
    return 0;
}

double func(double x)
{
    if (x < 0) return fabs(x);
    else if (x < 2) return sqrt(x + 1);
    else if (x < 4) return pow(x + 2, 5);
    else return 2 * x + 5;
}