//ZHOU ZIYU (z5212919)
//11-04-2019
//lab08 one_per_line

#include<stdio.h>

int main () {

    
    char ch = getchar ();
    printf("Enter a string: ");
    while (ch != EOF) {
        if (ch == 10) {
            break;
        } else {
            printf("%c\n",ch);
            ch = getchar ();
        }
    }
    
    return 0;
}
