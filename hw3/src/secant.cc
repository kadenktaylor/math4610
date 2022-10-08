#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secant(double (*)(double), double, double, double);
double fval(double);

int main()
{
  //
  // Set up and initialzie some storage/numbers
  //------------------------------------------------------------
  //
  double x0  = 2.021;
  double x1 = 2.022;
  double tol = .001;
  // 
  // call the bisection routine
  // -----------------------------------------------------------
  //
  double rootval = secant(fval, x0, x1, tol);
  //
  printf("root value = %f\n", rootval);
}

//
// routine to ocmpute approximations of roots using bisection
// -------------------------------------------------------------
//
double secant(double (*f)(double), double x0, double x1, double tol)
{
  printf("Iteration, x0: %f, x1: %f,error: %f\n", x0, x1, fabs(f(x1)) );
  
  if ( fabs(f(x1)) < tol )
    {
      return x1;
    }
  else
    {
      return secant(f, x1, ((x1-x0) * f(x0)) / (f(x1) - f(x0)), tol);
    }
}

double fval(double xval)
{
  double fval = xval * exp(-xval);
  // printf("xval = %f, fval = %f\n", xval, fval);
  return fval;
}
