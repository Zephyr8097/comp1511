//ZHOU ZIYU (z5212919)
//04-04-2019
//Lab07 swap_case

#include<stdio.h>

int swap_it (char ch);

int main() {
    char ch = getchar();
    
    while (ch != EOF) {
        ch = swap_it(ch);
        putchar(ch);
        ch = getchar();
    }
    return 0;
}        
        



int swap_it (char ch) {
    int result;
    if (ch >= 'a' && ch <= 'z') {
        int swap_upper = ch - 'a' + 'A';
        result = swap_upper;
    } else if (ch >= 'A' && ch <= 'Z') {
        int swap_lower = ch - 'A' + 'a';
        result = swap_lower;
    } else {
        result = ch;
    }    
    return result;
}               
