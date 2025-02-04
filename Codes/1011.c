//
// Created by XX on 2024/12/21.
//

# include <stdio.h>
int min(int m, int n);

int main(){
    int m, n, common_divisor;
    scanf("%d %d", &m, &n);
    for (int i = min(m, n); ; i--){
        if (m % i == 0 && n % i == 0){
            printf("%d ", i);
            common_divisor = i;
            break;
        }
    }
    printf("%d", m * n / common_divisor);
    return 0;
}

int min(int m, int n) {
    if (m < n){
        return m;
    }
    else {
        return n;
    }
}