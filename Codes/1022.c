//
// Created by XX on 2024/12/28.
//

# include <stdio.h>

int is_prime(int n);

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
    {
        if (is_prime(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

int is_prime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!(n % i))
        {
            count++;
        }
    }
    if (count == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}