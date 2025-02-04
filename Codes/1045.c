//
// Created by XX on 2025/2/2.
//

#include <stdio.h>

void input_nems(int nums[10]);
void sort_nums(int nums[10]);
void print_nums(int nums[10]);

int main()
{
    int nums[10];
    input_nems(nums);
    sort_nums(nums);
    print_nums(nums);
    return 0;
}

void input_nems(int nums[10])
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &nums[i]);
    }
}

void sort_nums(int nums[10])
{
    int index_max = 9, index_min = 0;
    int temp_zero = nums[0], temp_nine = nums[9];
    for (int i = 1; i < 10; i++)
    {
        if (nums[i] < nums[0])
        {
            nums[0] = nums[i];
            index_min = i;
        }
    }
    nums[index_min] = temp_zero;
    for (int i = 0; i < 9; i++)
    {
        if (nums[i] > nums[9])
        {
            nums[9] = nums[i];
            index_max = i;
        }
    }
    nums[index_max] = temp_nine;
}

void print_nums(int nums[10])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}