#include <stdio.h>

void fib(int n);

int main() {
        fib(6);
        return 0;
}

void fib(int n) {
        int first = 0, second = 1, sum;
        for (int i = 1; i <= n; i++) {
                if (i == 0) {
                        printf("0 ");
                } else if (i == 1) {
                        printf("1 ");
                } else {
                        sum = first + second;
                        printf("%d ", sum);
                        first = second;
                        second = sum;
                }
        }
}
