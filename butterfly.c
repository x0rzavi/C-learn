// Butterfly pattern
// *       * 
// * *   * * 
// * * * * * 
// * *   * * 
// *       *
#include <stdio.h>

int main() {
        int n;
        printf("Enter n (odd): ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) { // rows
                // columns
                for (int j = 1; j <= i; j++) { // left triangle
                        printf("* ");
                }
                for (int j = 1; j <= (2 * n - 1) - (2 * i); j++) { // spaces
                        printf("  ");
                }
                for (int j = 1; j <= i; j++) { // left triangle
                        if (j != n) {
                                printf("* "); // remove extra star
                        }
                }
                printf("\n"); // next line
        }

        for (int i = n - 1; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                        printf("* ");
                }
                for (int j = 1; j <= (2 * n - 1) - (2 * i); j++) {
                        printf("  ");
                }
                for (int j = 1; j <= i; j++) {
                        if (j != n) {
                                printf("* ");
                        }
                }
                printf("\n");
        }
        return 0;
}
