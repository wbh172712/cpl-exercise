//
// Created by wbh17 on 2023/10/29.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int a[11][11];
int n, x;
int dx[4] = {0, -1, 1, -1};
int dy[4] = {1, 1, 1, 0};

bool pd(int pl) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= 3; k++) {
                int flag = 1;
                for (int t = 0; t < x; t++) {
                    if (a[i + t * dx[k]][j + t * dy[k]] != pl || i + t * dx[k] < 1 || i + t * dx[k] > n ||
                        j + t * dy[k] < 1 || j + t * dy[k] > n)
                        flag = 0;
                }
                if (flag == 1) return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    int b[6];
    scanf("%d%d", &t, &x);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                scanf("%d", &a[j][k]);
            }
        }
        if (pd(1) == true) b[1]++;
        if (pd(2) == true) b[2]++;
        if (pd(4) == true) b[4]++;
        if (b[1] != 0 && b[2] == 0 && b[4] == 0) printf("%d\n", 1);
        else if (b[1] == 0 && b[2] != 0 && b[4] == 0) printf("%d\n", 2);
        else if (b[1] == 0 && b[2] == 0 && b[4] != 0) printf("%d\n", 4);
        else {
            printf("draw\n");
        }
    }
    return 0;
}