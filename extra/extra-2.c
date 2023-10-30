//
// Created by wbh17 on 2023/10/11.
//
#include <stdio.h>
int main(void){
    int number;
    scanf("%d", &number);

    long int num1 = 1, result = 0;
    long int a = 1000000007;
    for (int i = 1; i <= number; i++) {
        num1 = (num1 * i) % a;
        result = (result + num1) % a;
    }

    printf("%ld", result);
    return 0;
}