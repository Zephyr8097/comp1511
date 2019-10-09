#include <stdio.h>

int main(void) {
    int box;
    int row = 1, column = 1;
    
    printf("Enter boxes: ");
    scanf("%d", &box);
    
    
    while (row <= x ) {
        
        column = 1;        //reset column
        while (column <= x) {
            if ((column - y)  % 2 == 0 && (row - y) % 2 == 0) {// distance from center point is even
                printf(" ");   
            } else printf("#");
            column++;
        }
        printf("\n");   // new row
        row++;
    }

    return 0;
}
