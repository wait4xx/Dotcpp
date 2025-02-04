//
// Created by XX on 2024/12/24.
//

# include <stdio.h>

int main()
{
    int M = 0, N = 0;
    scanf("%d %d", &M, &N);
    double height = M, distance = 0;
    for (int i = 1; i <= N; i++)
    {
        double height_b = height;
        height -= height / 2;
        distance += (height_b + height);
    }
    distance -= height;
    printf("%.2f %.2f", height, distance);
    return 0;
}