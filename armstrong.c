#include <stdio.h>

int main() {
        int n, digit, sum = 0;
        printf("Enter n: ");
        scanf("%d", &n);
        int copy = n;

        while (n != 0) {
                digit = n % 10;
                sum = sum + (digit * digit * digit);
                n = n / 10;
        }

        if (copy == sum) {
                printf("Armstrong");
        } else {
                printf("Not Armstrong");
        }

        return 0;
}
