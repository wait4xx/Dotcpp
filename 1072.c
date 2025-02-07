//
// Created by XX on 2025/02/06.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int soda(int n);
int main()
{
    bool flag = true;
    int count = 0;
    int *nums = (int *)malloc(sizeof(int) * 1);
    while (flag)
    {
        int temp = 0;
        scanf("%d", &temp);
        if (temp == 0) flag = false;
        else
        {
            count++;
            if (count > 1) nums = (int *) realloc(nums, (count) * sizeof(int));
            nums[count - 1] = temp;
        }
    }
    
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", soda(nums[i]));
    }
    
    return 0;
}

int soda(int n)
{
    int sum = 0;
    while (n >= 3)
    {
        sum += n / 3;
        n = n / 3 + n % 3;
    }
    if (n == 2) sum++;
    return sum;
}
