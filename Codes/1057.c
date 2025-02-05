//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

float y(float x);

int main()
{
    float x = 0;
    scanf("%f", &x);
    printf("%.2f\n", y(x));
    return 0;
}

float y(float x)
{
    if (x < 1) return x;
    else if (x < 10) return 2 * x - 1;
    else return 3 * x - 11;
}