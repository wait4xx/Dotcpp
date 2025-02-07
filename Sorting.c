//
// Created by Shanbaby on 2024/12/28.
//

#include <stdio.h>

// 冒泡排序
void sort(int a[],int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = 0;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// 冒泡排序
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped = 0;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // 如果没有发生交换，说明数组已经有序，提前退出
        if (!swapped)
            break;
    }
}

// 双向冒泡排序(鸡尾酒排序)
void cocktailShakerSort(int arr[], int n) {
    int swapped = 0;
    int start = 0;
    int end = n - 1;

    do {
        swapped = 0;

        // 从左到右冒泡，就像标准的冒泡排序
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break; // 如果没有发生交换，表示已经排好序了

        swapped = 0;
        end--; // 减少右侧的边界，因为最后的元素已经是最大值

        // 从右到左冒泡
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        start++; // 增加左侧的边界，因为第一个元素已经是最小值
    } while (swapped);
}

// 选择排序
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        // 假设当前索引是最小值的位置
        minIndex = i;
        // 查找实际的最小值位置
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 如果找到了更小的数，则交换
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// 排序算法的关键在于交换！
int main() {
    int num[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    sort(num,10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}
