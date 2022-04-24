/*  Example: C program to find area of a square */

#include <stdio.h>

// a comment

int main()
{
  float s, a;

  printf("Enter side (in inches):\n");
  scanf("%f", &s);

  a = s * s;

  printf("Square's area is %3.2f (sq in).\n", a);
}
