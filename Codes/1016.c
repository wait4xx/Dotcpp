//
// Created by XX on 2024/12/23.
//

# include <stdio.h>
# include <math.h>

int main()
{
    for (int i = 100; i < 1000; i++)
    {
        int Units = i % 10;
        int Tens = (i % 100) / 10;
        int Hundreds = i / 100;
        int sum = pow(Units, 3) + pow(Tens, 3) + pow(Hundreds, 3);
        if (sum == i)
        {
            printf("%d\n", sum);
        }
    }
    return 0;
}