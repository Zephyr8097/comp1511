//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 15-03-2019
//week4 test hollow_triangle
#include<stdio.h>
int main() {
    int size, row = 1, column = 1;
    printf("Enter size: ");
    scanf("%d",&size);
    while(row <= size) {
        while(column <= size) {
            if(column == 1) {
                printf("*");
            } else if(row == size) {
                printf("*");
            } else if(row == column) {
                printf("*");
            } else printf(" ");
            column++;
        }
        column = 1;
        printf("\n");       
        row++;
    }
    return 0;
}         
