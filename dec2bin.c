#include <stdio.h>

int main() {
        int n;
        printf("Enter decimal: ");
        scanf("%d", &n);

        int digit, bin[50], count = 0;
        while (n != 0) {
                bin[count] = n % 2;
                count++;
                n = n / 2;
        }

        printf("Binary: ");        
        for (int i = count - 1; i >= 0; i--) {
                printf("%d", bin[i]);
        }
        return 0;
}
