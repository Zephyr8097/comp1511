// String Equality
// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>
#include <assert.h>
//#include <string.h>

int strings_equal(char *string1, char *string2);

int main(int argc, char *argv[]) {

    // Some simple assert-based tests.
    // You probably want to write some more.
    assert(strings_equal("", "") == 1);
    assert(strings_equal(" ", "") == 0);
    assert(strings_equal("", " ") == 0);
    assert(strings_equal(" ", " ") == 1);
    assert(strings_equal("\n", "\n") == 1);
    assert(strings_equal("This is 17 bytes.", "") == 0);
    assert(strings_equal("", "This is 17 bytes.") == 0);
    assert(strings_equal("This is 17 bytes.", "This is 17 bytes.") == 1);
    assert(strings_equal("Here are 18 bytes!", "This is 17 bytes.") == 0);

    printf("All tests passed.  You are awesome!\n");

    return 0;
}


// Takes two strings, and if they are the same,
// returns 1, or 0 otherwise.
int strings_equal(char *string1, char *string2) {
    // Your code goes here!
    /*int i = 0;
    if (strcmp (string1, string2) == 0) {
        i = 1;
    }*/
    int counter = 0;
    int i = 0;
    int k = 0;
    int j = 1;
    while (string1[i] != '\0') {
        i++;
    }
    while (string2[k] != '\0') {
        k++;
    }
    if (i != k) {
        j = 0;
    } else {
        while (string1[counter] != '\0' && string2[counter] != '\0') {
            if (string1[counter] != string2[counter]) {
                j = 0;
            }
            counter++;
        }    
    }
    // Don't forget to return your result.
    return j;
}
