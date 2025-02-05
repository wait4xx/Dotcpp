//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))

void swap_num(int *nums);

int main()
{
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &nums[i]);
    }
    swap_num(nums);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

void swap_num(int *nums)
{
    int min = ABS(nums[0]), min_index =0;
    for (int i = 1; i < 10; i++)
    {
        if (ABS(nums[i]) < min)
        {
            min = nums[i];
            min_index = i;
        }
    }
    nums[min_index] = nums[9];
    nums[9] = min;
}