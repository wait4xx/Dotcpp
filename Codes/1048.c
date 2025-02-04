//
// Created by XX on 2025/2/2.
//

#include <stdio.h>
#include <stdlib.h>

void move_str(char str[], int n, int m);

int main()
{
    int n = 0;
    scanf("%d", &n);
    char *input_str = (char *)malloc(n * sizeof(char));
    scanf("%s", input_str);
    int m = 0;
    scanf("%d", &m);
    move_str(input_str, n, m);
}

void move_str(char str[], int n, int m)
{
    for (int i = m - 1; i < n; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}