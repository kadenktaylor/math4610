#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

int main()
{
  double start;
  double end;

  start = omp_get_wtime();
  
  // a_col must equal b_row
  int const a_col = 10;
  int const a_row = 10;
  int const b_col = 10;
  int const b_row = 10;

  int a[a_row][a_col];
  int b[b_row][b_col];
  
  int result[a_row][b_col];

  int num = 0;
  for(int i = 0; i < a_row; i++)
    {
      for(int j = 0; j < a_col; j++)
	{
	  a[i][j] = num;
	  b[i][j] = num;
	  num++;
	}
    }


  for(int i = 0; i < a_row; i++)
    {
      for(int j = 0; j < b_col; j++)
	{
	  int sum = 0;
	  
	  for(int k = 0; k < a_col; k++)
	    {
	      int adding = a[i][k] * b[k][j];
	      //printf("Sum is: %d, Adding: %d\n", sum, adding);
	      sum += adding;
	    }
	  
	  result[i][j] = sum;
	  //printf("\n\n");
	}
    }
  
  printf("Result: \n");

  for(int i = 0; i < a_row; i++)
    {
      for(int j = 0; j < b_col; j++)
	{
	  printf("%d, ", result[i][j]);
	}
      printf("\n");
    }

  end = omp_get_wtime();
  
  printf("Work time: %f second\n", end - start);

  return 1;
}
