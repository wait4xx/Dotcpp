//
// Created by XX on 2025/2/2.
//

#include <stdio.h>


void move_nums(int nums[], int n, int m);

int main()
{
    int n = 0;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int m = 0;
    scanf("%d", &m);
    move_nums(nums, n ,m);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void move_nums(int nums[], int n, int m) {
    if (m == 0 || n == 0) return;
    m = m % n; // 确保m在0到n-1范围内
    if (m == 0) return;

    int temp[m];
    // 保存最后m个元素
    for (int i = 0; i < m; i++) {
        temp[i] = nums[n - m + i];
    }
    // 前n-m个元素右移m位
    for (int i = n - m - 1; i >= 0; i--) {
        nums[i + m] = nums[i];
    }
    // 将临时数组元素复制到前面
    for (int i = 0; i < m; i++) {
        nums[i] = temp[i];
    }
}

// Correct solution
// #include <stdio.h>
// #include <stdlib.h>
//
// // 反转法（即先反转整个数组，然后分别反转前m个元素和剩余元素）
// void reverse(int nums[], int start, int end) {
//     while (start < end) {
//         int temp = nums[start];
//         nums[start] = nums[end];
//         nums[end] = temp;
//         start++;
//         end--;
//     }
// }
//
// void move_nums(int nums[], int n, int m) {
//     if (m == 0 || m == n || n <= 1) return;
//     m = m % n; // 处理m大于n的情况
//     reverse(nums, 0, n - 1);
//     reverse(nums, 0, m - 1);
//     reverse(nums, m, n - 1);
// }
//
// int main() {
//     int n = 0;
//     scanf("%d", &n);
//     int *nums = (int *)malloc(n * sizeof(int));
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &nums[i]);
//     }
//     int m = 0;
//     scanf("%d", &m);
//     move_nums(nums, n ,m);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", nums[i]);
//     }
//     free(nums); // 记得释放动态分配的内存
//     printf("\n");
// }