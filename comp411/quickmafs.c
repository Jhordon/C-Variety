
#include <stdio.h>

int main()
{

  double num, sum, min, max, product;
  sum = 0;
  min = 0;
  max = 0;
  product = 1;

  printf("Enter 10 floating-point numbers:\n");

  for (int i = 0; i < 10; i++) {
  scanf("%lf", &num);
  sum = sum + num;
  product = product * num;
  
  if (min > num) {
  min = num;
  } 
  if (max < num) {
  max = num;
  }
  }

  printf("Sum is %3.5lf\n", sum);
  printf("Min is %3.5lf\n", min);
  printf("Max is %3.5lf\n", max);
  printf("Product is %3.5lf\n", product);
}
