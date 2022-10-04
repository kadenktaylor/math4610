#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secant();
double fval(double);

int main()
{
  //
  // Set up and initialzie some storage/numbers
  //------------------------------------------------------------
  //
  double x0  = 1;
  double x1 = 10;
  double tol = .0001;
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
double secant(double (*f)(), double x0, double x1, double tol)
{

  if ( abs(f(x1)) < tol )
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
  double fval = xval * xval - 4.1;
  // printf("xval = %f, fval = %f\n", xval, fval);
  return fval;
}