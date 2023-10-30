//
// Created by wbh17 on 2023/10/24.
//
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int max = 0;
    int count = 0;
    scanf("%d", &max);

    // TODO: print primes between 1 and max
    for (int number = 2; number <= max; number++){
        bool is_prime = true;

        for (int factor = 2; factor * factor <= number; factor++){
            if (number % factor == 0){
                is_prime = false;
                break;
            }
        }//判断是否为素数

        if (is_prime) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}