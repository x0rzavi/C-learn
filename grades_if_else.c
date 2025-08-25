#include <stdio.h>

int main() {
  int marks;
  printf("Enter marks: ");
  scanf("%d", &marks);

  if (marks <= 100 && marks >= 90) {
    printf("O");
  } else if (marks <= 89 && marks >= 80) {
    printf("E");
  } else if (marks <= 79 && marks >= 70) {
    printf("A");
  } else if (marks <= 69 && marks >= 60) {
    printf("B");
  } else if (marks <= 59 && marks >= 50) {
    printf("C");
  } else if (marks <= 49 && marks >= 40) {
    printf("D");
  } else if (marks <= 39 && marks >= 0) {
    printf("F");
  } else {
    printf("Invalid input");
  }
  return 0;
}
