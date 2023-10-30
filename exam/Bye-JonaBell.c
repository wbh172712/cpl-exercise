//
// Created by wbh17 on 2023/10/29.
//
#include <stdio.h>

int main() {

    int n = 0;
    int k = 0;
    int b = 0;
    int l = 0;
    scanf("%d%d%d%d", &n, &k, &b, &l);

    int alive[1504] = {0};
    for (int i = 1; i <= n; i++) {
        alive[i] = l;
    }

    int pos = 0;
    int b_cnt = b;
    int time = 0;
    for (int i = 1; i <= n * l - 1 + time; i++) {
        for (int j = 1; j <= k; j++) {
            pos++;
            if (pos > n) pos = 1;
            while (alive[pos] == 0) {
                pos++;
                if (pos > n) pos = 1;
            }
        }
        if (b_cnt != 0) {
            alive[pos]--;
        }
        if (b_cnt == 0) {
            b_cnt = b;
            time++;
            continue;
        }
        b_cnt--;
    }

    for (int i = 1; i <= n; i++) {
        if (alive[i]) {
            printf("%d", i);
        }
    }

    return 0;
}