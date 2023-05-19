// Number pattern
//     1 
//   2 3 2 
// 3 4 5 4 3 

#include <stdio.h>

int main() {
        int n, num;
        printf("Enter n: ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
                num = i;
                for (int j = 1; j <= n - i; j++) {
                        printf("  ");
                }
                for (int j = 1; j <= i; j++) {
                        printf("%d ", num);
                        num++;
                }
                num -= 2;
                for (int j = 1; j < i; j++) {
                        printf("%d ", num);
                        num--;
                }
                printf("\n");
        }

        return 0;
}
