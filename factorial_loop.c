#include <stdio.h>

int fact(int n);

int main() {
        int n;
        printf("Enter n: ");
        scanf("%d", &n);
        printf("Factorial is: %d", fact(n));

        return 0;
}

int fact(int n) {
        int prod = 1;
        for (int i = 1; i <= n; i++) {
                prod = prod * i;
        }
        
        return prod;
}
