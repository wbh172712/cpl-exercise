//
// Created by wbh17 on 2023/10/11.
//
#include <stdio.h>

int main() {
    FILE *fp;
    char c;

    // 打开当前运行的源代码文件
    fp = fopen("E:\\codes\\cpl-exercise\\extra\\extra-1.c", "r");

    if (fp == NULL) {
        printf("Can not open c source dictionary.\n");
        return 1;
    }

    // 逐行读取文件内容并输出到屏幕上
    while ((c = fgetc(fp)) != EOF) {
        //putchar(c);亦可
        printf("%c", c);
    }

    // 关闭文件
    fclose(fp);
    fp = NULL;
    return 0;
}