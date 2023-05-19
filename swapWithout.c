#include <stdio.h>

int main() {
        int a, b;
        printf("Enter a & b: ");
        scanf("%d%d", &a, &b);

        // a = a + b;
        // b = a - b;
        // a = a - b;

        a = a * b;
        b = a / b;
        a = a / b;

        printf("a & b are: %d %d", a, b);
        return 0;
}
