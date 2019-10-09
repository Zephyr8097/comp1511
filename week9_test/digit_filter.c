//ZHOU ZIYU(z5212919)
//23-04-2019
//week9 test digit_filter

#include<stdio.h>

int main () {

    char ch = getchar();
    while (ch != EOF) {
        if ((ch < '0' || ch > '9') && ch != ' ' && ch != 10) {
            ch = '.';
        }
        putchar (ch);
        ch = getchar();
    }
    return 0;
}    
