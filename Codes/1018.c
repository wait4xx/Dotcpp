//
// Created by XX on 2024/12/24.
//

# include <stdio.h>

double calculate_an(int n);

int main()
{
    int n = 0;
    scanf("%d", &n);
    double sn = 0;
    for (int i = 1; i<= n; i++)
    {
        sn += calculate_an(i + 1) / calculate_an(i);
    }
    printf("%.2f", sn);
    return 0;
}

double calculate_an(int n)
{
    double an = 0;
    if (n < 3)
    {
        an = n;
    }
    else
    {
        an = calculate_an(n - 1) + calculate_an(n - 2);
    }
    return an;
}