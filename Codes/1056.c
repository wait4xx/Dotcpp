//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

float f2c(float f);

int main()
{
    float f = 0;
    scanf("%f", &f);
    printf("%.2f\n", f2c(f));
    return 0;
}

float f2c(float f)
{
    return (f - 32) * 5 / 9;
}