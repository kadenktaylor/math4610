#include <stdio.h>
#include <stdlib.h>

#include <omp.h>
#define NUM_THREADS 2

int main ()
{
  double start;
  double end;

  start = omp_get_wtime();
  
  int const n = 4;
  
  int u[n] = {1, 2, 3, 4};
  int v[n] = {1, 2, 3, 4};
  int w[n];
  
  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
  {
    int id = omp_get_thread_num();
    int nthrds = omp_get_num_threads();

    for(int i = id; i < n; i = i + nthrds)
      {
	w[i] = u[i] * v[i];     
      }
  }
  
  printf("w = u:v = {");
  for(int i = 0; i < n; i++)
    {
      printf("%d, ", w[i]);
    }
  printf("}\n");

  end = omp_get_wtime();

  printf("Work time: %f seconds\n", end - start);
  
  return 1;
}
