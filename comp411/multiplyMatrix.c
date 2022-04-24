#include <stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];

int main() {
  int N, i, j, k;
  //scanning for rowXcol
  scanf("%i", &N);

  //scanning for inputs
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      scanf("%i", &A[i][j]);
    }
  }

  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      scanf("%i", &B[i][j]);
    }
  }


  // the multiplication process
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      C[i][j] = 0;
      for (k = 0; k < N; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  // printing
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      printf("%6d", C[i][j]);
    }
    printf("\n");
  }
}
