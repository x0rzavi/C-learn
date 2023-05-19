#include <stdio.h>

int main() {
        int x, y, prod = 1;
        printf("Enter x, y: ");
        scanf("%d%d", &x, &y);

        for (int i = 1; i <= y; i++) {
                prod = prod * x;
        }

        printf("pow(x,y) : %d", prod);
        return 0;
}
