//
// Created by XX on 2024/12/21.
//

# include <stdio.h>
# include <math.h>

unsigned long sn_temp(int n_zero, int index);

int main() {
    int n;
    unsigned long sn = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        sn += sn_temp(2, i);
    }
    printf("%lu", sn);
    return 0;
}

unsigned long sn_temp(const int n_zero, const int index) {
    unsigned long sn_n = 0;
    for (int i = 0; i <= index; i++) {
        sn_n += n_zero * (int)pow(10, i);
    }
    return sn_n;
}