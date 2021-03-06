//Written by ZhouZiyu (z5212919)
//on 21-03-2019
//Lab05 vector_distance

#include <stdio.h>
#include <math.h>
#define MAX_SIZE     1000


void caculate_distance(int l, int vector1[l], int vector2[l]);

int main(void) {
    int vector1[MAX_SIZE];
    int vector2[MAX_SIZE];
    int i = 0;
    int length;
    printf("Enter vector length: ");
    scanf("%d",&length);
    printf("Enter vector 1: ");
    while(i < length) {
        scanf("%d",&vector1[i]);
        i++;
    }
    printf("Enter vector 2: ");
    i = 0;
    while(i < length) {
        scanf("%d",&vector2[i]);
        i++;
    }
    caculate_distance(length, vector1, vector2);
    return 0;
}           

// the function of the distance
void caculate_distance(int l, int vector1[l], int vector2[l]) {
    double sum = 0;
    int i = 0;
    while(i < l) {
        sum = sum + ((vector1[i]-vector2[i]) * (vector1[i]-vector2[i]));
        i++;
    }
    double distance;
    distance = sqrt(sum);
    printf("Euclidean distance =  %.6lf\n", distance);
}    
