//
// Created by XX on 2025/2/5.
//

#include <stdio.h>

int ctof(int c);

int main() {
    for (int c = -100; c <= 150; c += 5)
    printf("c=%d->f=%d\n", c, ctof(c));
    return 0;
}

int ctof(int c)
{
    return c * 9 / 5 + 32;
}