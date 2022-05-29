/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, c;

  printf("Enter radius (in cm):\n");
  scanf("%f", &r);
  
  c = PI * ((r * 2)) / 2.54; 
  a = PI * (r / 2.54) * (r / 2.54);
  // this is a comment 
  printf("Circle's area is %3.2f (sq in).\n", a);
  printf("Its circumference is %3.2f (in).\n", c);
}
