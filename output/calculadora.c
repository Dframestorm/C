#include <stdio.h>

int main() {
    char op;
    double num1, num2, result;

    while (1) {
        printf("Enter an operator (+, -, *, /) or 'q' to quit: ");
        scanf(" %c", &op);

        if (op == 'q') {
            break;
        }

        printf("Enter two operands: ");
        scanf("%lf %lf", &num1, &num2);

        switch (op) {
            case '+':
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error! Division by zero.\n");
                }
                break;
            default:
                printf("Error! Operator is not correct\n");
        }
    }

    return 0;
}
