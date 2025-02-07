//
// Created by XX on 2025/02/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char *num);
void self_decreasing(char *num);

int main() {
    int count = 0;
    int nums[10];
    char temp[102];

    while (count < 10 && fgets(temp, sizeof(temp), stdin)) {
        temp[strcspn(temp, "\n")] = '\0'; // 移除换行符
        if (strcmp(temp, "0") == 0) break;
        nums[count++] = judge(temp);
    }

    for (int i = 0; i < count; i++) 
        printf("%d\n", nums[i]);
    return 0;
}

int judge(char *num) {
    if (strlen(num) < 1) return 0;

    // 处理大数
    char buffer[102];
    strcpy(buffer, num);
    self_decreasing(buffer);

    unsigned long long num_int = strtoull(buffer, NULL, 10);
    return (num_int % 17 == 0) ? 1 : 0;
}

void self_decreasing(char *num) {
    while (strlen(num) > 4) {
        int len = strlen(num);
        int last_digit = num[len - 1] - '0';
        num[--len] = '\0';  // 移除最后一位

        int carry = last_digit * 5;
        for (int i = len - 1; i >= 0 && carry > 0; i--) {
            int digit = num[i] - '0';
            digit -= carry % 10;
            carry /= 10;
            if (digit < 0) {
                digit += 10;
                carry++;
            }
            num[i] = digit + '0';
        }

        // 移除前导零
        char *start = num;
        while (*start == '0' && start[1] != '\0') start++;
        if (start != num) memmove(num, start, strlen(start) + 1);
    }
}