#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
  long long t1 = 0, t2 = 1;
  long long nextTerm;

  if (n <= 0) {
    return;
  }

  if (n == 1) {
    printf("%lld\n", t1);
  } else {
    printf("%lld, %lld", t1, t2);
    for (int i = 3; i <= n; ++i) {
      nextTerm = t1 + t2;
      printf(" ,%lld", nextTerm);
      t1 = t2;
      t2 = nextTerm;
    }
  }
}

int main(void) {
  int numTerms;
  scanf("%d", &numTerms);
  fibonacci(numTerms);
}
