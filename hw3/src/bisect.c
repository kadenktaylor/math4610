#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bisect();
double fval(double);

int main()
{
  //
  // Set up and initialzie some storage/numbers
  //------------------------------------------------------------
  //
  double a = 1.0;
  double b = 3.0;
  double tol = .00000001;
  // 
  // call the bisection routine
  // -----------------------------------------------------------
  //
  double rootval = bisect(fval, a, b, tol);
  //
}
//
// routine ot ocmpute approximations of roots using bisection
// -------------------------------------------------------------
//
double bisect(double (*f)(), double a, double b, double tol)
{
  //
  // set up storage for the work to be done
  // -----------------------------------------------------------
  // 
  double fa = f(a);
  double fb = f(b);
  //
  // test the endpoints for a root in the interval
  // -----------------------------------------------------------
  // 
  if(fa*fb >= 0.0)
    {
      printf("There may not be a root in [a,b]: f(a)*f(b) = %e", fa*fb);
      exit(-1);
    }
  double c;
  double fc;
  //
  //compute the number of
  int k = 
