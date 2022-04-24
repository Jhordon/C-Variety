#include <stdio.h>
#include <string.h>

int main()
{
    int num, n;

    printf("Please enter the starting number of the Collatz sequence:\n");
    scanf("%i", &num);

    n = num;

    while (n != 1)
    {
        printf("%i, ", n);

        if ((n & 1) == 1)
            n = (3*n) + 1;
        else
            n = n / 2;
    }
   printf("%i\n", n);

   printf("press a key");
   getchar();
   getchar();
   getchar();
   getchar();
}
