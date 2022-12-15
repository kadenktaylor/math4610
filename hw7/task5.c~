#include <stdio.h>
#include <stdlib.h>

int main()
{
  int const uLen = 5;
  int const vLen = 10;
  
  int u[uLen] = {1, 2, 3, 4, 5};
  int v[vLen] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int A[uLen][vLen];
  
  for(int i = 0; i < uLen; i++)
    {
      for(int j = 0; j < vLen; j++)
	{
	  A[i][j] = u[i]*v[j];
	}
    }
  
  printf("A:\n");
  for(int i = 0; i < uLen; i++)
    {
      for(int j = 0; j < vLen; j++)
	{
	  printf("%d, ", A[i][j]);
	}
      printf("\n");
    }

  
  return 1;
}
