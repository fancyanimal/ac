#include <stdio.h>
#include <stdlib.h>
#include "root.h"

int main(int argc, char **argv) {
  double a = 0;
  double b = 0;
  double c = 0;
  double *arr = NULL;
  printf("Enter coefficients a, b, c.\n");
  scanf("%lf%lf%lf", &a, &b, &c);
  int amount = solve(a, b, c, &arr);
  if (amount == 0) {
    printf("No solutions in real numbers.\n");
  }
  else if (amount == 1) {
    printf("%lf\n", *arr);
    free(arr);
  }
  else if (amount == 2) {
    printf("%lf, %lf\n", *arr, *(arr + 1));
    free(arr);
  }
  else if (amount == 3) {
    printf("Infinite amout of solutions.\n");
  }
  return 0;
}
