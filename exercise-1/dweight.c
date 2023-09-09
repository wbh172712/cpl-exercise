//
// Created by wbh17 on 2023/9/9.
//
#include <stdio.h>

int main(){
    int height , length , width , volume , weight;

    printf("Enter height of the box is : ");
    scanf("%d", &height);
    printf("Enter length of the box is : ");
    scanf("%d", &length);
    printf("Enter width of the box is : ");
    scanf("%d", &width);

    volume = height * length * width ;
    weight = (volume + 165) / 166;

    printf("volume : %d\n", &volume);
    printf("weight : %d\n", &weight);

    return 0;
}
