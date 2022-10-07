#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double (*)(double), double (*)(double), double, double);
double fval(double);
double dfval(double);

int main()
{
  //
  // Set up and initialzie some storage/numbers
  //------------------------------------------------------------
  //
  double x0  = .001;
  double tol = .00000001;
  // 
  // call the bisection routine
  // -----------------------------------------------------------
  //
  double rootval = newton(fval, dfval, x0, tol);
  //
  printf("root value = %f\n", rootval);
}

//
// routine to ocmpute approximations of roots using bisection
// -------------------------------------------------------------
//
double newton(double (*f)(double), double (*df)(double), double x0, double tol)
{

  if ( fabs(f(x0)) < tol )
    {
      return x0;
    }
  else
    {
      return newton(f, df, x0 - f(x0)/df(x0), tol);
    }

}

double fval(double xval)
{
  double fval = xval * exp(-xval);
  // printf("xval = %f, fval = %f\n", xval, fval);
  return fval;
}

double dfval(double xval)
{
  double dfval = exp(-xval) - xval*exp(-xval);
  // printf("xval = %f, fval = %f\n", xval, dfval);
  return dfval;
}
