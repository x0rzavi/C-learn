// Print 0 at even postions, 1 at odd postions
// 1 
// 1 0 
// 1 0 1
#include <stdio.h>

int main() {
        int n;
        printf("Enter n: ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                        j % 2 == 0 ? printf("0 ") : printf("1 ");
                }
                printf("\n");
        }

        return 0;
}
