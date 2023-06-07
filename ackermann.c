#include <stdio.h>

// ack(m,n) = n + 1 if m = 0
// ack(m,n) = ack(m - 1, 1) if m > 0 & n = 0
// ack(m,n) = ack(m - 1, ack(m, n - 1)) if m > 0 & n > 0

int ack(int m, int n);

int main() {
        int m, n;
        printf("Enter m, n: ");
        scanf("%d%d", &m, &n);

        printf("Ackermann: %d", ack(m, n));
        return 0;
}

int ack(int m, int n) {
        if (m == 0) {
                return n + 1;
        } else if (m > 0 && n == 0) {
                return ack(m - 1, 1);
        } else {
                return ack(m - 1, ack(m, n - 1));
        }
}
