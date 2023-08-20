#include <stdio.h>

int hcf(int a, int b);

int main() {
        int a, b;
        printf("Enter a, b: ");
        scanf("%d%d", &a, &b);
        printf("HCF: %d", hcf(a, b));

        return 0;
}

int hcf(int a, int b) {
        if (a == 0) {
                return b;
        } else {
                return hcf(b % a, a);
        }
}
