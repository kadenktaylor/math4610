#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int const rows = 100;
  int const cols = 100;
  
  int A[rows][cols];
  int B[rows][cols];
  int C[rows][cols];

  for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
	{
	  A[i][j] = rand() % 10;
	  B[i][j] = rand() % 10;
	}
    }
 
  for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
	{
	  C[i][j] = A[i][j] * B[i][j];
	}
    }

  /*  
  printf("C:\n");
  for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
	{
	  printf("%d, ", C[i][j]);
	}
      printf("\n");
    }
  */
  
  printf("A[3][5] = %d, B[3][5] = %d, C[3][5] = %d\n", A[3][5], B[3][5], C[3][5]);
  printf("A[25][97] = %d, B[25][97] = %d, C[25][97] = %d\n", A[25][97], B[25][97], C[25][97]);
  printf("A[47][17] = %d, B[47][17] = %d, C[47][17] = %d\n", A[47][17], B[47][17], C[47][17]);
  return 1;
}
