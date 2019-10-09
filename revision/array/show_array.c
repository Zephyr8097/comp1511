#include <stdio.h>
#include <assert.h>

void show_array(int size, int array[size]);

int main(int argc, char *argv[]) {
    // DO NOT CHANGE THIS MAIN FUNCITON
    // get array size
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // declare array
    int array[size];

    printf("Enter array values: ");
    // intialise array values
    int i = 0;
    while (i < size) {
        assert(scanf("%d", &array[i]) == 1);
        i = i + 1;
    }

    show_array(size, array);

    return 0;
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
