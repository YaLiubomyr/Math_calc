#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {

    double alfa, z1, z2;
    char input[100];

    while (1) {
        printf("Enter the value of alpha (in radians) (between -9999 and 9999), or type 'q' to quit: ");

        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = 0;

            if (input[0] == 'q') {
                break;
            }

            if (sscanf(input, "%lf", &alfa) != 1) {
                printf("Error: Invalid input. Please enter a valid number.\n");
                continue;
            }

            if (alfa < -9999.0 || alfa > 9999.0) {
                printf("Error: Value out of range. Please enter a number between -9999 and 9999.\n");
                continue;
            }

            double numerator = sin(2 * alfa) + sin(5 * alfa) - sin(3 * alfa);
            double denominator = cos(alfa) + 1 - 2 * pow(sin(alfa), 2);

            if (fabs(denominator) < 1e-9) {
                printf("Error: Division by zero in the formula for z1.\n");
                continue;
            }

            z1 = numerator / denominator;
            z2 = 2 * sin(alfa);

            printf("z1 = %lf\n", z1);
            printf("z2 = %lf\n", z2);
        }
        else {
            printf("Error reading input.\n");
        }
    }

    return 0;
}
