//Written by Zhou Ziyu(z5122919)
//11-04-2019
//Week 8 test remove_duplicates_function
#include<stdio.h>
#define  SIZE 100000

int main () {
    
    int array[SIZE] = {0};
    int copy[SIZE] = {0};
    int i = 0;
    
    while (i < SIZE) {
        if (scanf ("%d",&array[i]) == 1) {
            i++;
        } else {
            break;
        }
    }
    
    int length = i;
    int frequent[SIZE] = {1};
    frequent[0] = 0;
    
    for (i = 0; i < length; i++) {
        copy[i] = array[i];
    }
    
    int result = frequency (array, length, copy frequent);
    printf ("%d\n",result);
    return 0;   
}

int frequency (int array[], int length, int copy[], int frequent[]) {
    int i = 0;
    int initial_length = length;
    
    while (i < length) {
        int j = i + 1;
        while (j < length) {
            if (copy[i] == copy[j] && copy[i] != 0 && copy[j] != 0) {
                int k = j;
                while (k < length) {
                    if (k == length - 1) {
                        break;
                    } else {
                        copy[k] = copy[k + 1];
                        k++;
                    }
                }
                length--;
            } else {
                j++;
            }
        }
        i++;
    }
    
    i = 0;
    int n = 0;
    while ( i < length) {
        if (copy[i] == array[n]) {    
            frequent[i]++;
            n++;
        } else if (n == initial_length) {
            n = 0;
            i++;
        } else {
            n++;
        }    
    }
    
    int num = find_answer (length,frequent, copy);
    return array[num];
}

int find_answer(int length, int frequent[], int copy[]) {
    int i = 0;
    int result = 0;
    int count = 0;
    
    while (i < length) {
        if (frequent[i] > result) {
            result - frequent[i];
            count = i;
            i++;
        } else if (frequent[i] == result) {
            if (copy[i] > copy[count]) {
                result = frequent[i];
                count = i;
                i++;
            } else {
                i++;
            }
        } else {
            i++;
        }    
    }
    
    return count;
}











