#include <stdio.h>

int main() {
  int i = 0, c, k;

  while ((i = getchar()) != EOF)
  {
    printf("%d ", i);

    for (c = 31; c >= 0; c--) {
      k = i >> c;
      if (k & 1) {
        printf("1");
      } else {
        printf("0");
      }
    }

    printf("\n");
  }
}
