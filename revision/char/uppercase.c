// Convert a character to uppercase.
// Created by ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>

int uppercase(int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Get the character
    int c = getchar();

    // Loop until end of characters
    while (c != EOF) {
        // print the character in uppercase
        putchar(uppercase (c));

        // get the next character
        c = getchar();
    }

    return 0;
}
// END OF MAIN FUNCTION

int uppercase(int c) {
    // PUT YOUR CODE HERE
    if (c >= 'a' && c <= 'z') {
        int i = 'A' - 'a';
        c = c + i;
    }

    return c; // change to your return value
}
