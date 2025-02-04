//
// Created by XX on 2024/12/21.
//

# include <stdio.h>

unsigned long sn_temp(const int n);

int main() {
    int n;
    unsigned long sn = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sn += sn_temp(i);
    }
    printf("%lu", sn);
    return 0;
}

unsigned long sn_temp(const int n) {
    unsigned long sn_n = 1;
    for (int i = 1; i <= n ;i++) {
        sn_n *= i;
    }
    return sn_n;
}