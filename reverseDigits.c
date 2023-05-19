#include <stdio.h>

int main() {
        int n;
        printf("Enter n: ");
        scanf("%d", &n);

        while (n != 0) {
                printf("%d", n % 10);
                n /= 10;
        }
}
