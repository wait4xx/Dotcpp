//
// Created by XX on 2025/2/2.
//

#include <stdio.h>

#define SWAP(a, b) do { int t = a; a = b; b = t; } while(0)

int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    SWAP(a, b);
    printf("%d %d\n", a, b);
    return 0;
}