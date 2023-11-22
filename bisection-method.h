#include <assert.h>
#include <stdio.h>

// precision_req: the precision required of the output
static const double precision_req = 1e-5;

// max_iterations: the maximum number of iterations that the method will run for
static const size_t max_iterations = 1000000;

// inputs:
// a pointer to a continuous function f.
// (continuous in the mathematical sense ofc)
// an interval [a,b]
// it is required that f(a) * f(b) < 0.

// output:
// returns the root c of the function f such that either f(c) = 0,
// or f(c) = precision_req ( f(c) is sufficiently precise)
// if max_iterations is exceeded, returns the
// last known value of c and
// prints an error message to stderr
static double bisection_method(double (*f)(double), double a, double b) {
  assert(f(a) * f(b) < 0 && "initial guess doesn't contain the solution");

  double c;
  for (size_t iterations = 0; (iterations < max_iterations); ++iterations) {
    c = (a + b) / 2;
    double f_c = f(c);
    if (f_c == 0 || (f_c - precision_req == 0)) {
      return c;
    }

    // the new interval is constructed as follows:
    // if sign of f(a) and f(c) are same, then [a,b] <- [c,b]
    // else [a,b] <- [a,c]
    if (f(c) * f(a) > 0) {
      a = c;
    } else {
      b = c;
    }
  }

  fprintf(stderr,
          "method failed: max_iterations[%zu] exceeded. final value: %f",
          max_iterations, c);
  return c;
}
