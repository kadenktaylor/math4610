#include <stdio.h>
#include <stdlib.h>

#include <omp.h>
#define NUM_THREADS 5

int main()
{
  int const N = 25;

  double start;
  double end;

  start = omp_get_wtime();


  int const awidth = N;
  int const aheight = N;
  int const bwidth = N;
  int const bheight = N;
  int const cwidth = awidth * bwidth;
  int const cheight = aheight * bheight;

  int a[aheight][awidth];
  int b[bheight][bheight];

  int c[cheight][cwidth];

  int count = 0;
  
  for(int i = 0; i < aheight; i++)
    {
      for(int j = 0; j < awidth; j++)
	{
	  a[i][j] = count;
	  count++;
	}
    }

  count = 0;
  
  for(int i = 0; i < bheight; i++)
    {
      for(int j = 0; j < bwidth; j++)
        {
          b[i][j] = count;
          count++;
        }
    }
  
  
  
  
  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
  {
    int id = omp_get_thread_num();
    int nthrds = omp_get_num_threads();


    for (int i = id; i < aheight; i = i + nthrds)
      {
	for(int j = 0; j < awidth; j++)
	  {
	    for(int y = 0; y < bheight; y++)
	      {
		for(int x = 0; x < bwidth; x++)
		  {
		    int c_row = i*bheight + y;
		    int c_col = j*bwidth + x;
		    int c_value = a[i][j] * b[y][x];
		    
		    c[c_row][c_col] = c_value;
		  }
	      }
	  }
      }
  }
  
  /*
  printf("Result:\n");
  for(int i = 0; i < cheight; i++)
    {
      for(int j = 0; j < cwidth; j++)
	{
	  printf("%d, ", c[i][j]);
	}

      printf("\n");
    
    }
  */
  
  
  end = omp_get_wtime();
  printf("Work took %f seconds\n", end - start);

  
  return 1;
}
