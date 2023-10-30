//
// Created by wbh17 on 2023/10/28.
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void) {
    int NUM = 0;
    scanf("%d", &NUM);
    char sentence[100000] = "";

    for (int i = 0; i < NUM; i++) {
        scanf("%s", sentence);

        int len = strlen(sentence);


        for (int j = 0; j < len; j++) {
            if ((sentence[j] != '-') && ((sentence[j] < '0') || (sentence[j] > '9'))) {
                printf("Radix Error\n");
                goto end;
            }
        }

        int num = atoi(sentence);
        int number = abs(num);

        int k = 0;
        char three[100];
        if (number == 0) {
            printf("0\n");
            goto end;
        }
        while (number > 0) {
            if (number % 3 == 1) {
                three[k] = '1';
                number /= 3;
                k++;
            } else if (number % 3 == 2) {
                three[k] = 'Z';
                number = number / 3 + 1;
                k++;
            } else {
                three[k] = '0';
                number /= 3;
                k++;
            }
        }
        int l = k;
        if (sentence[0] == '-') {
            for (; l >= 0; l--) {
                if (three[l] == '1') {
                    three[l] = 'Z';
                } else if (three[l] == 'Z') {
                    three[l] = '1';
                }
            }
        }

        for (int j = k - 1; j >= 0; j--) {
            printf("%c", three[j]);
        }
        printf("\n");
        end:
        continue;
    }
    return 0;
}