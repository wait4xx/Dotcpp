//
// Created by XX on 2025/2/5.
//

#include <stdio.h>
#include <stdlib.h>

int sum(int *nums, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *nums = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("%d", sum(nums, n));
    return 0;
}

int sum(int *nums, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0) sum += nums[i];
    }
    return sum;
}