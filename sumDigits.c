#include <stdio.h>

int main() {
        int n, digit, sum = 0;
        printf("Enter n: ");
        scanf("%d", &n);

        while (n != 0) {
                digit = n % 10;
                sum += digit;
                n = n / 10;
        }

        printf("Sum: %d", sum);
        return 0;
}
