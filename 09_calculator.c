#include <stdio.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

int divide(double a, double b, double *res) {
    if (b == 0.0) {
        printf("Error: Division by zero is undefined!\n");
        return 0;
    }
    *res = a / b;
    return 1;
}

int calculate(double a, double b, char op, double *res) {
    switch (op) {
        case '+':
            *res = add(a, b);
            return 1;
        case '-':
            *res = subtract(a, b);
            return 1;
        case '*':
            *res = multiply(a, b);
            return 1;
        case '/':
            return divide(a, b, res);
        default:
            printf("Error: Unsupported operator '%c'\n", op);
            return 0;
    }
}

int main(void) {
    double a, b, res;
    char op;

    printf("Enter first number: ");
    if (scanf("%lf", &a) != 1) {
        printf("Invalid input for first number!\n");
        return 1;
    }

    printf("Enter operator (+, -, *, /): ");
    if (scanf(" %c", &op) != 1) {
        printf("Invalid operator input!\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &b) != 1) {
        printf("Invalid input for second number!\n");
        return 1;
    }

    if (calculate(a, b, op, &res)) {
        printf("Result: %.4f %c %.4f = %.4f\n", a, op, b, res);
    }

    return 0;
}
