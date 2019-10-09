#include<stdio.h>

int main () {
    
    char ch = getchar ();
    while (ch != EOF) {
        int i = ch;
        printf ("%d\n", i);
        ch = getchar ();
    }
    return 0;
}
