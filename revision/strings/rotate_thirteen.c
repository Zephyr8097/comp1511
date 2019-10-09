// Perform the ROT13 algorithm on a string
// Completed by
//  ... (z0000000)
//  ... (z0000000)
// Commpleted on 2017-08-??
// Tutor's name (day_hH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// Add your own #defines here
#define NUM  13

void rotate_thirteen(char *string);
char rotate_one(char c);
void rotate_thirteen(char *string);
int strings_equal(char *string1, char *string2);

// Add your own function porototypes here

int main(int argc, char *argv[]) {
    // Example tests
    char test_a[MAX_LENGTH] = "Hello, world!";
    rotate_thirteen(test_a);
    assert(strings_equal("Uryyb, jbeyq!", test_a));

    char test_b[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotate_thirteen(test_b);
    assert(strings_equal("nopqrstuvwxyzabcdefghijklm", test_b));

    char test_c[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotate_thirteen(test_c);
    assert(strings_equal("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.", test_c));

    // Add your own tests here

    printf("All tests passed. You are awesome!\n");

    return 0;
}

void rotate_thirteen(char *string) {
    // YOUR CODE HERE
    int i = 0;
    while (string[i] != '\0' && string[i] != '\n') {
        if (string[i] >= 'a' && string[i] <= 'z') {
            if (string[i] + NUM > 'z') {
                string[i] -= NUM;
            } else {
                string[i] += NUM;
            }
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            if (string[i] + NUM > 'Z') {
                string[i] -= NUM;
            } else {
                string[i] += NUM;
            }
        }
        i++;
    }
    // See: https://en.wikipedia.org/wiki/ROT13
}

char rotate_one(char c) {
    // Use your code from the rotate_one exercise up here
    if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z')) {
        c++;
    } else if (c == 'z' || c == 'Z') {
        c = c - 25;
    }
    // Don't forget to return your result.
    return c;
}

int strings_equal(char *string1, char *string2) {
    // Use your code from the strings_equal exercise here
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
