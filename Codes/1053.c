//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

int main()
{
    int n[10], sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &n[i]);
        sum += n[i];
    }

    float avg = sum / 10.;
    int avg_exceed = 0;
    for (int i = 0; i < 10; i++)
    {
        if (n[i] > avg) avg_exceed++;
    }
    printf("%d\n", avg_exceed);
    return 0;
}