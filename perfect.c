#include <stdio.h>

int main() {
        int n, sum = 0;
        printf("Enter n: ");
        scanf("%d", &n);

        for (int i = 1; i < n; i++) {
                if (n % i == 0) {
                        sum = sum + i;
                }
        }

        if (n == sum) {
                printf("Perfect");
        } else {
                printf("Not Perfect");
        }

        return 0;
}
