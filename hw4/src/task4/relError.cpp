#include <math.h>

float relError(float v, float u)
{
  float error;
  error = fabs(u-v)/fabs(u);  
  return error;
}

