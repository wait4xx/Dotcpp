//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

int is_prime(int n)
{
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (is_prime(n))
    {
        printf("prime\n");
    }
    else
    {
        printf("not prime\n");
    }
    return 0;
}