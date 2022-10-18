#include <math.h>

float absError(float v, float u)
{
  float error;
  error = fabs(u-v);
  return error;
}
