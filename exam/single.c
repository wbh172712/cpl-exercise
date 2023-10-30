//
// Created by wbh17 on 2023/10/28.
//
#include <stdio.h>
int main(void) {
    int n = 0;
    scanf("%d", &n);

    int nums[10005] = {0};
    int count[100005] = {0};
    for (int i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &nums[i]);
        count[nums[i]]++;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        if (count[nums[i]] == 1) {
            printf("%d", nums[i]);
        }
    }
    return 0;
}