#include <stdio.h>

int main() {
        int n;
        printf("Enter no of elements: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter array elements: ");
        for(int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
        }

        int e, count = 0;
        printf("Enter element to search: ");
        scanf("%d", &e);

        for(int i = 0; i < n; i++) {
                if(arr[i] == e) {
                        printf("Element found at index %d\n", i);
                        count++;
                }
        }

        if(count == 0) {
                printf("Element was not found\n");
        }

        return 0;
}
