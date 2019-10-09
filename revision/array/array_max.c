// Find the maximum value in an array.
// Sample solution.

#include <stdio.h>
#include <assert.h>

int array_max(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    assert(size > 0);
    int array[size];

    // Scan in values for the array.
    printf("Enter array values: ");
    int i = 0;
    while (i < size) {
        assert(scanf("%d", &array[i]) == 1);
        i = i + 1;
    }

    printf("Maximum value is %d.\n", array_max(size, array));

    return 0;
}

// Return the largest value in a given array.
int array_max(int size, int array[size]) {
    // Put your code here
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (max < array[i]) {
            max = array[i];    
        }
    }
    return max;
}
