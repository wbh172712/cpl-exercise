//
// Created by wbh17 on 2023/10/28.
//
#include <stdio.h>
int main(void){
    int n, k;
    scanf("%d%d", &n, &k);

    int alive[505] = {0};
    for (int i = 1; i <= n; i++) {
        alive[i] = 1;
    }

    int pos = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= k; j++) {
            pos++;
            if (pos > n) pos = 1;
            while (alive[pos] == 0) {
                pos++;
                if (pos > n) pos = 1;
            }
        }
        alive[pos] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (alive[i] == 1) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}