//
// Created by XX on 2025/2/2.
//

#include <stdio.h>

void print_sort(int a, int b, int c);

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    print_sort(a, b, c);
    return 0;
}

void print_sort(int a, int b, int c)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a > c)
    {
        int temp = a;
        a = c;
        c = temp;
    }
    if (b > c)
    {
        int temp = b;
        b = c;
        c = temp;
    }
    printf("%d %d %d\n", a, b, c);
}