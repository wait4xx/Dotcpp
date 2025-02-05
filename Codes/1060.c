//
// Created by XX on 2025/2/5.
//

#include <stdio.h>
#include <stdbool.h>

bool find_num(int n);

int main()
{
    for (int i = 10; i <= 1000; i++)
    {
        if (find_num(i)) printf("%d\n", i);
    }
    return 0;
}

bool find_num(int n)
{
    if (n % 2 == 0)
    {
        if (n % 3 == 0)
        {
            if (n % 7 == 0) return true;
        }
    }
    return false;
}