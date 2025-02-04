//
// Created by XX on 2024/12/24.
//

# include <stdio.h>
# include <math.h>

double c_sqrt(int n, double x);

int main()
{
    double x = 0., x_sqrt =0.;
    scanf("%lf", &x);
    int i = 0;
    while (fabsl(c_sqrt(i + 1, x) - c_sqrt(i, x)) >= 0.00001)
    {
        x_sqrt = c_sqrt(i, x);
        i++;
    }
    double x1_sqrt = (x_sqrt + x / x_sqrt) / 2;
    printf("%.3lf", x1_sqrt);
    return 0;
}

double c_sqrt(int n, double x)
{
    double x_output = 0;
    if (n == 0)
    {
        x_output = 1;
    }
    else
    {
        x_output = (c_sqrt(n - 1, x) + x / c_sqrt(n - 1, x)) / 2;
    }
    return x_output;
}