// Print out characters in lower case.
// Created by
//  ... (z5212919)
//  ... 
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>

int lowercase(int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Scan in the first character.
    int c = getchar();

    // Loop until there are no more characters to scan.
    while (c != EOF) {
        // Print the character, in lowercase.
        putchar(lowercase(c));

        // Get the next character.
        c = getchar();
    }

    return 0;
}

// Returns the specified character `c`, in lowercase.
int lowercase(int c) {
    // Your code goes here!
    if (c >= 'A' && c <= 'Z') {
        int i = 'A' - 'a';
        c = c - i;
    }
    // Don't forget to return your result.
    return c;
}
