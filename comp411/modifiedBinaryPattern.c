#include <stdio.h>

char target[100];
void foo (int size, int count)
{
  if (count > size)
    return;
  if (count == size)
  {
    target[count] = '\0';
    printf("%s\n", target);
    return;
  }
  target[count] = '0';
  foo(size, count+1);

  if (count == 0 || target[count-1] != '1')
  {
    target[count] = '1';
    foo(size, count+1);
  }
}

int main()
{
  int n;
  scanf("%i", &n);
  foo(n, 0);
}
