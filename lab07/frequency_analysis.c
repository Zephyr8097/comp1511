// ZHOU ZIYU (z5212919)
// 10-04-2019
// lab07 frenquency_analysis

#include<stdio.h>

int main() {
    int ch;
    int charactor[1000] = {0};
    double counter = 0;
    int t = 0;
    int i = 0;
    int j = 0;
    
    ch = getchar();
    charactor[0] = ch;
    i = 1;
    
    while (ch != EOF) {
        ch = getchar();
        charactor[i] = ch;
        i++;
    }
    while (charactor[j] != 0) {
        if (charactor[j] >= 'a' && charactor[j] <= 'z') {
            counter++;
        } if (charactor[j] >= 'A' && charactor[j] <= 'Z') {
            counter++;
        }
        j++;        
    }
    i = 0;
    int letter = 'a';
    while (letter <= 'z') {
        while (i < j) {
            if (letter - 'a' == charactor[i] - 'a' || letter - 'a' == charactor[i] - 'A') {
                t++;
            }
            i++;
        }
        i = 0;
        printf ("'%c' %lf %d\n", letter, t/counter, t);
        t = 0;
        letter++;
    }
              
    
    return 0;
}
