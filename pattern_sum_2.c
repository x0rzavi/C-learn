#include <stdio.h>

int fact(int n);

int main() {
        int n;
        float sum = 0;
        printf("Enter n: ");
        scanf("%d", &n);

        int odd = 1;
        for (int i = 1; i <= n; i++) {
                if (i % 2 == 0) {
                        sum += 1.0 / fact(odd);
                } else {
                        sum += -1.0 / fact(odd);
                }
                odd += 2;
        }

        printf("Sum is %f", sum);
        return 0;
}

int fact(int n) {
        if (n == 0) {
                return 1;
        } else {
                return fact(n - 1) * n;
        }
}
