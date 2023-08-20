#include <stdio.h>

void find(int*, int, int);

int main() {
        int n;
        printf("Enter no of elements: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter array elements: ");
        for(int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
        }

        int e;
        printf("Enter element to search: ");
        scanf("%d", &e);

        find(arr, n, e);

        return 0;
}

void find(int *arr, int n, int e) {
        int count = 0;
        for(int i = 0; i < n; i++) {
                if(arr[i] == e) {
                        printf("Element found at index %d\n", i);
                        count++;
                }
        }

        if(count == 0) {
                printf("Element was not found\n");
        }
}
