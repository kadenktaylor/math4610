#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fixedPoint(double (*)(double), double, double, int);
double gval(double);

int main()
{
  //
  // Set up and initialzie some storage/numbers
  //------------------------------------------------------------
  //
  double x0  = -.001;
  double tol = .00000001;
  int maxIter = 10;
  // 
  // call the bisection routine
  // -----------------------------------------------------------
  //
    double rootval = fixedPoint(gval, x0, tol, maxIter);
  //
}
//
// routine to ocmpute approximations of roots using bisection
// -------------------------------------------------------------
//
double fixedPoint(double (*g)(double), double x0, double tol, int maxIter)
{
  double error = 100;
  double x1 = 0.0;
  for(int i=0; i<maxIter && error>tol; i++)
    {
      x1 = g(x0);
      error = abs(x1 - x0);
      x0 = x1;
    }
  
  // printf("\nroot value = %f\n", x0);
  return x0;
}

double gval(double xval)
{
  double gval = xval - (xval*exp(-xval));
  printf("xval = %f, fval = %f\n", xval, gval);
  return gval;
}
