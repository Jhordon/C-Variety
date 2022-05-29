#include <stdio.h>
int n;
void rec2(int val, int count, int b)
{
  if (count <= 1)
  {
    int i;
    for (i = b - 1; i >=0; i--)
    {
      printf("%d", (val >> i) & 1);
    }
    printf("\n");
  } else {
    rec2(val * 2, count - 1, b);
    rec2(val * 2 + 1, count - 1, b);
  }
}

void rec(int val, int count)
{
  rec2(val, count, count);
}

int main()
{
  scanf("%i", &n);
  rec(0, n);
  rec(1, n);
  return 0;
}
