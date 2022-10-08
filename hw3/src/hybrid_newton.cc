#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hybrid_newton.h"

//double hnewton(double (*)(double), double (*)(double), double, double, double, int);
//double fval(double);
//double dfval(double);

/*

int main()
{
  //
  // Set up and initialzie some storage/numbers
  //------------------------------------------------------------
  //
  double a  = -2;
  double b = 3;
  double tol = .001;
  int maxIter = 10;
  // 
  // call the bisection routine
  // -----------------------------------------------------------
  //
  double rootval = hnewton(fval, dfval, a, b, tol, maxIter);
  //
  printf("root value = %f\n", rootval);
}


*/

//
// routine to compute approximations of roots using bisection
// -------------------------------------------------------------
//
double hnewton(double (*f)(double), double (*df)(double), double a, double b, double tol, int maxIter)
{
  double error = 10.0*tol;
  double iteration =0;
  double x0 = 0.5*(a+b);
  
  while (error > tol && iteration < maxIter)
    {
      double x1 = x0 - f(x0)/df(x0);
      double newton_error = fabs(x1 - x0);
      if (newton_error > error)
	{
	  double fa = f(a);
	  double fb = f(b);
	  for (int i = 0; i < 4; i++)
	    {
	      double c = 0.5*(a+b);
	      double fc = f(c);
	      if (fa*fc < 0)
		{
		  b = c;
		  fb = fc;
		}
	      else
		{
		  a = c;
		  fa = fc;
		}
	    }
	  error = fabs(b-a);
	  x0 = 0.5*(a+b);
	}
      else
	{
	  x0 = x1;
	  error = newton_error;
	}
      iteration = iteration + 1;
    }
  return x0;
}

/*

double fval(double xval)
{
  double fval = xval * exp(-xval);
  // printf("xval = %f, fval = %f\n", xval, fval);
  return fval;
}

double dfval (double xval)
{
  double dfval = exp(-xval) - xval*exp(-xval);
  return dfval;
}

*/