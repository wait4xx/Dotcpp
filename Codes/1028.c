#include <stdio.h>
#include <math.h>

void seek_roots(int a, int b, int c, double *num1, double *num2, int *flag);

int main()
{
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    
    double number1, number2;
    int flag;
    
    // 调用函数并传递地址
    seek_roots(a, b, c, &number1, &number2, &flag);

    if (flag == 1)
    {
        printf("x1=%.3lf x2=%.3lf\n", number1 + number2, number1 - number2);
    }
    else if (flag == 0)
    {
        printf("x1=%.3lf x2=%.3lf\n", number1, number1);
    }
    else
    {
        printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi\n", number1, number2, number1, number2);
    }

    return 0;
}

void seek_roots(int a, int b, int c, double *num1, double *num2, int *flag)
{
    double delta = b * b - 4 * a * c;
    *num1 = -1. * b / (2 * a);
    *num2 = 0;

    if (delta < 0)
    {
        // 虚数解
        *num2 = sqrt(-delta) / (2 * a);
        *flag = -1;
    }
    else if (delta > 0)
    {
        // 实数解
        *num2 = sqrt(delta) / (2 * a);
        *flag = 1;
    }
    else
    {
        // 重根
        *flag = 0;
    }
}