#include <stdio.h>
#include <math.h>

int main()
{
  int i, n, num2, sum, z;
  double x, temp;

  while (n != 0) {
  	printf("Number ?\n");
  	scanf("%d", &n);
	sum = 0;

  if (n == 0) {
  	printf("Done\n");
  	break;
  }
  
  temp = ((8*n)+1);
  x =  (sqrt(temp) - 1)/2;
  z = (int)x;
  num2 = (z * (z + 1)) / 2;

  for (i = 1; i <= n; i++) {
  	sum += i;
  		if (sum == n) {
  			printf("%d is a triangular number\n", n);
			break;
  		}
		if (i == n) {
			printf("%d is not triangular, nearest triangular number below %d is %d\n", n, n, num2);
			break;
		} 
  }

 }

}
