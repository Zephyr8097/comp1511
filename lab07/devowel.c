//ZHOU ZIYU (z5212919)
//02-04-2019
//Lab07 devowel

#include<stdio.h>
#define TRUE     1
#define FALSE    0

int is_vowel(char character);

int main() {

    char ch = getchar();
    
    while (ch != EOF) {
        if (is_vowel(ch) == 0) {
            putchar(ch);
        }
        ch = getchar();
    }
    
    return 0;          
}

int is_vowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return 1;
    }
    return 0;
}           
