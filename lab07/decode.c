//ZHOU ZIYU (z5212919)
//10-04-2019
//Lab07 decode

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    
    int i = 0;
    int j = 0;
    int t = 0;
    int ch;
    int ch2;
    ch = getchar();
    while (ch != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            while (t < 26) {
                if (ch == argv[1][t]) {
                    break;
                }
                t++;
            }
            
            ch = 'a' + t;
            t = 0;
            printf ("%c", ch);
        } else if (ch >= 'A' && ch <= 'Z') {
            while (t < 26) {
                ch2 = ch - 'A' + 'a';
                if (ch2 == argv[1][t]) {
                    break;
                }
                t++;
            }
            
            ch = 'A' +t;
            t = 0;
            printf ("%c", ch);
        } else {
            printf ("%c", ch);
        } 
        ch = getchar();
    }
    
    return 0;
}    
