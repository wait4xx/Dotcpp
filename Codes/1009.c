//
// Created by XX on 2024/12/21.
//

# include <stdio.h>
# include <math.h>

int countDigitsLog(int num) {
    if (num == 0) return 1; // 特殊情况处理
    num = abs(num); // 转换为正数，以便正确计数
    return (int)floor(log10(num)) + 1;
}

int main(){
    int number, number_contrary = 0;
    scanf("%d", &number);
    int number_len = countDigitsLog(number);
    printf("%d\n", number_len);
    for (int i = 0; i < number_len; i++){
        int remainder = number % (int)pow(10, number_len - i);
        int temp =  remainder / pow(10, number_len - i - 1);
        if (i == number_len - 1){
            printf("%d", temp);
        }
        else {
        printf("%d ", temp);
        }
        number_contrary += temp * (int)pow(10, i);
    }
    printf("\n%d", number_contrary);
    return 0;
}
