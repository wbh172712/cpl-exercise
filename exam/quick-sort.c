//
// Created by wbh17 on 2023/10/28.
//
#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int nums[1000] = {0};
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int k = 1; k <= n; k++) {
        int l = 0;
        int r = n - 1;
        int pivot = nums[k - 1];

        while (l < r) {
            while (l < r && nums[l] < pivot) l++;
            while (l < r && nums[r] >= pivot) r--;
            if (l < r) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
            }
        }

        if (nums[l] > pivot){
            for (int i = 0; i < n; i++) {
                if (nums[i] == pivot) {
                    int temp = nums[l];
                    nums[l] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}