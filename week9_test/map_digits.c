//ZHOU ZIYU(Z5212919)
//24-04-2019
//week9 test map_digits

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    char ch = getchar ();
    int i = 0;
    
    while (ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            i = ch - '0';
            ch = argv[1][i];
            putchar (ch);   
        } else {
            putchar (ch);
        }
        ch = getchar ();
    }
    
    return 0 ;
}
