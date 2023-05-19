#include <stdio.h>

int main() {
        int i, j;
        printf("Enter i, j: ");
        scanf("%d%d", &i, &j);
        int a[i][j], b[i][j];

        for (int x = 0; x < i; x++) {
                printf("Enter elements of row %d: ", x + 1);
                for (int y = 0; y < j; y++) {
                        scanf("%d", &a[x][y]);
                        b[y][x] = a[x][y];
                }
        }

        printf("Transpose matrix is: \n");
        for (int x = 0; x < i; x++) {
                for (int y = 0; y < j; y++) {
                        printf("%d ", b[x][y]);
                }
                printf("\n");
        }
        return 0;
}
