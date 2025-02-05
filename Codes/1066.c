//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

double fact(int n);
double mypow(double x, int n);
double calculate_y(double x, int n);

int main() {
    unsigned int n;
    double x;
    scanf("%lf %ud", &x, &n);
    double result = calculate_y(x, n);
    printf("%.4lf\n", result);
    return 0;
}

double fact(int n)
{
    double result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

double mypow(double x, int n)
{
    double result = 1;
    for (int i = 0; i < n; i++) result *= x;
    return result;
}

double calculate_y(double x, int n)
{
    double result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0) result -= mypow(x, i) / fact(i);
        else result += mypow(x, i) / fact(i);
    }
    return result;
}