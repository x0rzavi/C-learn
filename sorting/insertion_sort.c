// WIP
//
// insert an element from unsorted array to correct position in sorted array
// https://www.youtube.com/watch?v=3GC83dh4cf0
#include <stdio.h>

int main() {
        int n = 7;
        int arr[] = {12, 64, 45, 23, 51, 19, 8};

        for (int i = 1; i < n; i++) {
                int curr = arr[i];
                int j = i - i;
                while (arr[j] > curr && j >= 0) {
                        arr[j + 1] = arr[j];
                        j--;
                }
                arr[j + 1] = curr;
        }

        for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]); // ascending order
        }

}
