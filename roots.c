#include <stdio.h>
#include <math.h>

int main() {
        float a, b, c;
        printf("Enter coefficients a, b, c: ");
        scanf("%f%f%f", &a, &b, &c);

        if (a == 0 && b == 0) {
                printf("No solution");
        } else if (a == 0) {
                printf("One root is: %f", -c / b);
        } else if ((b * b - 4 * a * c) < 0) {
                printf("No real roots");
        } else {
                float d = b * b - 4 * a * c;
                float x1 = (-b + sqrt(d)) / (2 * a);
                float x2 = (-b - sqrt(d)) / (2 * a);
                printf("Roots are: %f %f", x1, x2);
        }
        return 0;
}
