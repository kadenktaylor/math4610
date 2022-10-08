#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fixedPoint.h"
#include "bisect.h"
#include "newton.h"
#include "secant.h"
#include "hybrid_newton.h"
#include "hybrid_secant.h"

double gval(double);
double fval(double);
double dfval(double);


int main()
{
  double a = -2.0;
  double b = 3.0;
  double x0 = -.001;
  double x1 = .001;
  double tol = .00000001;
  double maxIter = 10;

  double fixedPointVal = fixedPoint(gval, x0, tol, maxIter);
  double bisectVal = bisect(fval, a, b, tol);
  double newtonVal = newton(fval, dfval, x0, tol);
  double secantVal = secant(fval, x0, x1, tol);
  double hnewtonVal = hnewton(fval, dfval, a, b, tol, maxIter);
  double hsecantVal = hsecant(fval, a, b, tol, maxIter);


  printf("Fixed Point Root: %f\n", fixedPointVal);
  printf("Bisect Root: %f\n", bisectVal);
  printf("Newton Root: %f\n", newtonVal);
  printf("Secant Root: %f\n", secantVal);
  printf("Hybird Newton Root: %f\n", hnewtonVal);
  printf("Hybrid Secant Root: %f\n", hsecantVal);
}

double gval (double xval)
{
  double gval = xval - (xval*exp(-xval));
  return gval;
}

double fval (double xval)
{
  double fval = xval * exp(-xval);
  //printf("xval = %f, fval = %f\n", xval, fval);
  return fval;
}

double dfval(double xval)
{
  double dfval = exp(-xval) - xval*exp(-xval);
  // printf("xval = %f, fval = %f\n", xval, dfval);
  return dfval;
}
