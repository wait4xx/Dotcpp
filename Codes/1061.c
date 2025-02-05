//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

struct output
{
    int count;
    float avg;
};

struct output statistic(int *nums);

int main()
{
    int nums[20], n = 0;
    while (n < 20)
    {
        int temp;
        scanf("%d", &temp);
        nums[n] = temp;
        n++;
    }
    struct output result = statistic(nums);
    printf("%d\n%.2f", result.count, result.avg);
    return 0;
}

struct output statistic(int *nums)
{
    struct output result;
    int count = 0;
    result.count = 0;
    result.avg = 0;
    for (int i = 0; i < 20; i++)
    {
        if (nums[i] > 0)
        {
            count++;
            result.avg += nums[i];
        }
        else if (nums[i] < 0) result.count++;
    }
    result.avg = (float) result.avg / count;
    return result;
}
