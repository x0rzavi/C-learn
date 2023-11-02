// find minimum element in unsorted array and swap with element at beginning
// https://www.youtube.com/watch?v=dQa4A2Z0_Ro
#include <stdio.h>

int main() {
        int n = 7;
        int arr[] = {12, 45, 23, 37, 51, 19, 8};

        for (int i = 0; i < n - 1; i++) { // until 2nd last element; no unsorted array after last element
                for (int j = i; j < n; j++) { // compare starting from next upto last
                        if (arr[j] < arr[i]) { // check if moving element is smaller than fixed element
                                int temp = arr[j]; // swap if not in order: smaller < larger
                                arr[j] = arr[i];
                                arr[i] = temp;
                        }
                }
        }

        for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]); // ascending order
        }

        return 0;
}
