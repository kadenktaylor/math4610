#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int const n = 4;
  
  int u[n] = {1, 2, 3, 4};
  int v[n] = {1, 2, 3, 4};
  int w[n];
 
  for(int i = 0; i < n; i++)
    {
      w[i] = u[i] * v[i];     
    }
  
  printf("w = u:v = {");
  for(int i = 0; i < n; i++)
    {
      printf("%d, ", w[i]);
    }
  printf("}\n");
  
  return 1;
}
