//
// Created by XX on 2024/12/24.
//

# include <stdio.h>

unsigned long peach_num(int n);

int main()
{
    int N;
    scanf("%d", &N);
    unsigned long peaches = peach_num(N);
    printf("%lu", peaches);
    return 0;
}

unsigned long peach_num(int n)
{
    unsigned long sum = 0;
    if (n == 1)
    {
        sum = 1;
    }
    else
    {
        sum = (peach_num(n - 1) + 1) * 2;
    }
    return sum;
}