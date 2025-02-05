//
// Created by XX on 2025/2/5.
//

#include <stdio.h>
#include <stdlib.h>

struct max_point {
    int value;
    int x;
    int y;
};

struct max_point find_max(int **a, int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    int **a = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    }
    struct max_point max = find_max(a, n);
    printf("%d %d %d\n", max.value, max.x, max.y);
    return 0;
}

struct max_point find_max(int **a, int n)
{
    struct max_point max = {a[0][0], 0, 0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] > max.value)
            {
                max.value = a[i][j];
                max.x = i + 1;
                max.y = j + 1;
            }
    return max;
}