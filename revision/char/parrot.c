#include<stdio.h>

int main () {
    
    char ch = getchar ();
    while (ch != EOF) {
        /*if (ch >= 'A' && ch <= 'Z') {
            int i = 'A' - 'a';
            ch = ch - i;
        }*/
        putchar (ch);
        ch = getchar(); 
    }
    return 0;
}
