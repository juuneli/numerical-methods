// A minimal example of using the header 'bisection-method.h' to find the roots
// of a mathematical function
// Author: june(github.com/juuneli)

#include "../bisection-method.h"

#include <stdio.h>
#include <stdlib.h>

// some way of parsing command-line input.
// (note that this has no error checking)
// you can also ask for the input from stdin
static double parseStr(const char *p) {
  char *end;
  return strtod(p, &end);
}

// a continuous function
double f(double x) {
  //         3
  // f(x) = x  - x - 2
  return x * x * x - x - 2;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s [a,b]", argv[0]);
    return -1;
  }

  // a and b are the initial guesses
  const double a = parseStr(argv[1]);
  const double b = parseStr(argv[2]);

  // provide the function as a reference to the method
  // &f is a function pointer(i.e. pointer to function)
  double result = bisection_method(&f, a, b);

  printf("bisection_method: result: %lf\n", result);

  return 0;
}
