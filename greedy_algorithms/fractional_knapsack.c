#include <stdio.h>

struct Item {
  int value, weight;
  double ratio;
};

void swap(struct Item *a, struct Item *b) {
  struct Item t = *a;
  *a = *b;
  *b = t;
}

void sort(struct Item arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i].ratio < arr[j].ratio) {
        swap(&arr[i], &arr[j]);
      }
    }
  }
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
  sort(arr, n);
  int curWeight = 0;
  double finalvalue = 0.0;

  for (int i = 0; i < n; i++) {
    if (curWeight + arr[i].weight <= W) {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    } else {
      int remain = W - curWeight;
      finalvalue += arr[i].value * ((double)remain / arr[i].weight);
      break;
    }
  }

  return finalvalue;
}

int main() {
  int W = 50;
  struct Item arr[] = {{60, 10, 0}, {100, 20, 0}, {120, 30, 0}};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n; i++) {
    arr[i].ratio = ((double)arr[i].value / arr[i].weight);
  }

  printf("Maximum value we can obtain = %.2f", fractionalKnapsack(W, arr, n));
  return 0;
}
