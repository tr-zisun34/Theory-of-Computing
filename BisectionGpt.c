#include <stdio.h>
#include <math.h>

// Define the function for which we want to find the root
double func(double x) {
    return x*x - 4; // Replace this with your desired function
}

// Bisection method function
double bisection(double a, double b, double tolerance) {
    double c;
    
    // Check if the interval [a, b] contains a root
    if (func(a) * func(b) >= 0) {
        printf("No root found in the given interval.\n");
        return NAN; // Not-a-Number (NaN) to indicate failure
    }
    
    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        
        // Check if c is the root
        if (func(c) == 0.0) {
            break;
        }
        
        // Update the interval [a, b]
        if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    return c;
}

int main() {
    double a, b, tolerance, root;

    printf("Enter the left endpoint of the interval: ");
    scanf("%lf", &a);
    printf("Enter the right endpoint of the interval: ");
    scanf("%lf", &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    root = bisection(a, b, tolerance);

    if (!isnan(root)) {
        printf("Root: %lf\n", root);
    }

    return 0;
}
