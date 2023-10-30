//
// Created by wbh17 on 2023/10/24.
//
#include <stdio.h>
int main(void){
    int number;
    scanf("%d", &number);

    long long int num1 = 1, result = 0;
    for (int i = 1; i <= number; i++) {
        num1 = (num1 * i) % 1000000007;
        result = (result + num1) % 1000000007;
    }

    printf("%lld", result);
    return 0;
}