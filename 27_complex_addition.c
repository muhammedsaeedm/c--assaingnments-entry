#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex add(Complex c1, Complex c2) {
    Complex res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

void print_complex(Complex c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi", c.real, -c.imag);
    }
}

int main(void) {
    Complex c1, c2, sum;

    printf("Enter real and imaginary parts of first complex number (e.g. 3.5 2.0): ");
    if (scanf("%lf %lf", &c1.real, &c1.imag) != 2) {
        printf("Invalid input for first complex number!\n");
        return 1;
    }

    printf("Enter real and imaginary parts of second complex number (e.g. 1.5 -4.0): ");
    if (scanf("%lf %lf", &c2.real, &c2.imag) != 2) {
        printf("Invalid input for second complex number!\n");
        return 1;
    }

    sum = add(c1, c2);

    printf("\nFirst Complex Number:  ");
    print_complex(c1);
    printf("\nSecond Complex Number: ");
    print_complex(c2);
    printf("\n-------------------------------\n");
    printf("Sum:                   ");
    print_complex(sum);
    printf("\n");

    return 0;
}
