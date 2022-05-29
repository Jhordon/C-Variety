#include <stdio.h>

int main()
{

  int num, num2;
  printf("Enter six integers:\n");

  for (int i = 0; i < 3; i++) {
  scanf("%d %d", &num, &num2);
  if (i == 0) {
  printf("1234567890bb1234567890\n");
  }
  printf("%*d%*d\n", 10, num, 12, num2);
  }
}
