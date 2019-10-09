//Written by Zephyr Zhou(z5212919@unsw.edu.au)
//Written 13-03-2019
//This is for lab04 Danish_flag
#include<stdio.h>
int main() {
    int size, line = 1, column = 1;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    while(line <= 4 * size) {
        while(column <= 9 * size) {
            if(column == 3 * size || column == (3 * size) + 1) {
                printf(" ");
            } else if(line == 2 * size || line == 2 * size + 1) {
                printf(" ");
                column++;
            } else printf("#");
            column++;
        } printf("\n");       
        line++;
        column = 1;
        }
    return 0;
}        
