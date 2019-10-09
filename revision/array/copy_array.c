// Scan in an array.
// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (day_hH-lab)

#include <stdio.h>
#include <assert.h>

void scan_array(int size, int array[size]);
void show_array(int size, int array[size]);
void copy_array(int size, int from_array[size], int to_array[size]);

// DO NOT CHANGE THIS MAIN FUNCITON
int main(int argc, char *argv[]) {
    // get array size
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    int array1[size];

    // get values
    printf("Enter array values: ");
    scan_array(size, array1);

    // print values
    show_array(size, array1);

    int array2[size];
    copy_array(size, array1, array2);

    // print copied values
    show_array(size, array2);

    return 0;
}

// copy size elements from from_array into to_array
void copy_array(int size, int from_array[size], int to_array[size]) {
    // Put your code here
    for (int i = 0;i < size; i++) {
        to_array[i] = from_array[i];    
    }
}


// this function reads in values from
// standard input into an array
// this assumes scanf reads a number
void scan_array(int size, int array[size]) {
    // Put your code here
    for (int j = 0; j < size; j++) {
        scanf ("%d",&array[j]);
    }
}

// this function prints the array in the format
// [1, 2, 3, ...]
void show_array(int size, int array[size]) {
    // Put your code here
    printf ("[");
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            printf ("%d, ",array[i]);
        } else {
            printf ("%d]\n", array[i]);
        }
    }
}
