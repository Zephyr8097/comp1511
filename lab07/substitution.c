//ZHOU ZIYU (z5212919)
//10-04-2019
//Lab07 substitution

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    
    int i = 0;
    int j = 0;
    int ch;
    ch = getchar();
    while (ch != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            i = ch - 'a';
            ch = argv[1][i];
            printf ("%c", ch);
        } else if (ch >= 'A' && ch <= 'Z') {
            i = ch - 'A';
            ch = argv[1][i];
            j = argv[1][i] - 'a';
            ch = 'A' + j;
            printf ("%c",ch);
        } else {
            printf ("%c",ch);
        }    
        ch = getchar();
    }
    
    return 0;
}        
