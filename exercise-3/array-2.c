//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
int main(void){
    int array[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            array[i][j] = i * 10 + j;
            printf("%d ", array[i][j]);
        }
    }


    return 0;
}