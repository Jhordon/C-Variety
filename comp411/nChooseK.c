#include <stdio.h>

int NchooseK(int n, int k)
{
  if (k == n || k == 0)
  {
    return 1;
  }

  return (n * NchooseK(n -1, k - 1)) / k;
}

int main()
{
  int n, k, result;

  do
  {
    printf("Enter two integers (for n and k) separated by space: \n");
    scanf("%i %i", &n, &k);

    result = NchooseK(n, k);

    if (n == 0 && k == n)
    {
      printf("%d\n", result);
      break;
    }

    printf("%d\n", result);

  } while (n != 0);
}
