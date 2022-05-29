/* Example: matrices represented by 2-dimensional arrays */

#include <stdio.h>

int main()
{
  int A[3][3];    // matrix A     
  int B[3][3];    // matrix B
  int C[3][3];    // matrix to store their sum

  // add your code below
    int row, col;

    /* Input elements in first matrix*/
    printf("Please enter 9 values for matrix A:\n");
    for(row=0; row<3; row++)
    {
        for(col=0; col<3; col++)
        {
            scanf("%d", &A[row][col]);
        }
    }

    /* Input elements in second matrix */
    printf("Please enter 9 values for matrix B:\n");
    for(row=0; row<3; row++)
    {
        for(col=0; col<3; col++)
        {
            scanf("%d", &B[row][col]);
        }
    }

    /*
     * Add both matrices A and B entry wise or element wise
     * and stores result in matrix C
     */
    for(row=0; row<3; row++)
    {
        for(col=0; col<3; col++)
        {
            /* Cij = Aij + Bij */
            C[row][col] = A[row][col] + B[row][col];
        }
    }


    /* Print the value of resultant matrix C */
    printf("C = B + A =\n");
    for(row=0; row<3; row++)
    {
        for(col=0; col<3; col++)
        {
            printf("%10d", C[row][col]);
        }
        printf("\n");
    }

    return 0;
}  


