// ZHOU ZIYU (z5212919)
// 11-04-2019
// lab08 palindrome

#include<stdio.h>

int main () {

    int counter1 = 0;
    int counter2 = 0;
    int not_symmetry = 0;
    char ch[4096] = {0};
    
    printf ("Enter a string: ");
    ch[counter1] = getchar ();    
    while (ch[counter1] != EOF && ch[counter1] != '\n') {
        counter1++;
        ch[counter1] = getchar ();
    }
    counter1--;
        
    //printf("counter1 = %d\n\n", counter1);
    while (counter2 <= counter1) {
        if (ch[counter2] != ch[counter1]) {
            not_symmetry++;
        }
        counter2++;
        counter1--;
    }
    
    if (not_symmetry == 0) {
        printf ("String is a palindrome\n");
    } else {
        printf ("String is not a palindrome\n");
    }
        
    return 0;
}


