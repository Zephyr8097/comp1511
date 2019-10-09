// COMP1511 Week 5 Lab: Circle Facts
//
// This program was written by ZHOU ZIYU (z5212919)
// on 18-03-2019
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>
#define Pi 3.1415926535932354626

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    // TODO: complete this function.
    double a;
    a = Pi * radius * radius;
    return a;
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    // TODO: complete this function.
    double c;
    c= 2.0 * Pi * radius;
    return c;
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    // TODO: complete this function.
    double d;
    d = 2.0 * radius;
    return d;
}
