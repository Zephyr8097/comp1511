//ZHOU ZIYU (z5212919)
//10-04-2019
//Lab07 caesar

#include<stdio.h>
#include<stdlib.h>
#define ROUND    26

int caesar (char ch, int shift);

int main(int argc, char *argv[]) {
    
    int shift;
    char ch = getchar ();
    while (ch != EOF) {
        shift = atoi(argv[1]);
        ch = caesar (ch, shift);
        putchar (ch);
        ch = getchar ();
    }
    return 0;
}



int caesar (char ch, int shift) {
    if (ch >= 'a' && ch <= 'z') {
        if (shift > ROUND) {
            shift = shift % ROUND;
            if ((ch + shift) > 'z') {
                shift = shift - ROUND;
            }    
        } else if (shift <= -ROUND) {
            shift = -shift % ROUND;
            shift = -shift;
            if ((ch + shift) < 'a') {
                shift = shift + ROUND;
            }
        } else if ((ch + shift) > 'z') {
            shift = shift - ROUND;    
        } else if ((ch + shift) < 'a') {
            shift = shift + ROUND;    
        }
        ch = ch + shift;
    } else if (ch >= 'A' && ch <= 'Z') {
        if (shift > ROUND) {
            shift = shift % ROUND;
            if ((ch + shift) > 'Z') {
                shift = shift - ROUND;
            }    
        } else if (shift <= -ROUND) {
            shift = -shift % ROUND;
            shift = -shift;
            if ((ch + shift) < 'A') {
                shift = shift + ROUND;
            }
        } else if ((ch + shift) > 'Z') {
            shift = shift - ROUND;    
        } else if ((ch + shift) < 'A') {
            shift = shift + ROUND;    
        }
        ch = ch + shift;    
    }
    return ch;
}
        








