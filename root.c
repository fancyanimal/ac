#include <math.h>
#include <stdlib.h>

int solve(double a, double b, double c, double **arr) {
  if (arr == NULL) {
    return -1;
  }
  *arr = NULL;
  if (a == 0) {
    if (b == 0) {
      if (c == 0) {
        return 3;
      }
      else {
        return 0;
      }
    }
    *arr = malloc(sizeof(double));
    if (*arr == NULL) {
      return -1;
    }
    **arr = -c / b;
    return 1;
  }
  double disk = b * b - 4 * a * c;
  if (disk < 0) {
    *arr = NULL;
    return 0;
  }
  disk = sqrt(disk);
  if (disk == 0) {
    *arr = malloc(sizeof(double));
    if (*arr == NULL) {
      return -1;
    }
    **arr = -b / (2 * a);
    return 1;
  }
  *arr = malloc(sizeof(double) * 2);
  if (*arr == NULL) {
    return -1;
  }
  **arr = (-b + disk) / (2 * a);
  *(*arr + 1) = (-b - disk) / (2 * a);
  if (**arr > *(*arr + 1)) {
    double tmp = **arr;
    **arr = *(*arr + 1);
    *(*arr + 1) = tmp;
  }
  return 2;
}
