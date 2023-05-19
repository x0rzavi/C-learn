#include <stdio.h>

void isPrime(int n);

int main() {
        int n;
        printf("Enter n: ");
        scanf("%d", &n);
        isPrime(n);

        return 0;
}

void isPrime(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
                if (n % i == 0) {
                        count++;
                        if (count > 2) {
                                printf("Not prime");
                                break;
                        }
                }
        }
        if (count <= 2) {
                printf("Prime");
        }
}
