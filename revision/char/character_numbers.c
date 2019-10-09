#include<stdio.h>

int main () {
    
    int i = 32;
    char ch = i;
    while (i <= 126) {
        printf ("%d 0x%x %c\n", i, ch, ch);
        i++;
        ch = i;
    }
    return 0;
}
