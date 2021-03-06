//ZHOU ZIYU (z5212919)
//24-04-2019
// week9 test word_count
#include<stdio.h>

int main() {
    int ch = getchar();
    int line = 0;
    int character = 0;
    int word = 0;
    
    int previousCharacter = '\n';
   
    int wordAlreadyCounted = 0;
    int currentCharIsLetter = 0;
    while (ch != EOF) {
        currentCharIsLetter = 0;
        if (ch == '\n') {
            character++;
            line++;
        } else if (ch == ' ') {
            character++;
        } else {
            character++;
            currentCharIsLetter = 1;
        }
        if ((wordAlreadyCounted == 0) && (currentCharIsLetter) && (previousCharacter == '\n' ||             
             previousCharacter == ' ')) {
            word++;
            wordAlreadyCounted = 1;    
        } else {
            wordAlreadyCounted = 0;
        }
        previousCharacter = ch;
        ch = getchar();
    } 
    printf("%d lines %d words %d characters\n", line, word, character);
    return 0;
}    
