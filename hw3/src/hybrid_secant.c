#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double hsecant();
double fval(double);

int main()
{
  //
  // Set up and initialzie some storage/numbers
  //------------------------------------------------------------
  //
  double a  = 2;
  double b = 2.5;
  double tol = .001;
  int maxIter = 10;
  // 
  // call the bisection routine
  // -----------------------------------------------------------
  //
  double rootval = hsecant(fval, a, b, tol, maxIter);
  //
  printf("root value = %f\n", rootval);
}

//
// routine to compute approximations of roots using bisection
// -------------------------------------------------------------
//
double hsecant(double (*f)(), double a, double b, double tol, int maxIter)
{
  double error = 10.0*tol;
  int iteration = 0;
  double x0 = .49*(a+b);
  double x1 = .51*(a+b);
  while (error > tol && iteration < maxIter)
    {
      double x2 = x0 - ((x1-x0)*f(x0)) / (f(x1) - f(x0));
      double secant_error = fabs(x2 - x0);
      if (secant_error > error)
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
	  x0 = .49*(a+b);
	  x1 = .51*(a+b);
	}
      else
	{
	  x0 = x1;
	  x1 = x2;
	  error = secant_error;
	}  
      iteration = iteration + 1;
    }
  return x1;
}

double fval(double xval)
{
  double fval = xval * xval - 4.1;
  // printf("xval = %f, fval = %f\n", xval, fval);
  return fval;
}
