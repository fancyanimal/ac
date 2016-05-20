#include <stdlib.h>
#include "ctest.h"
#include "root.h"

CTEST(NoSolutions, test1) {
  double *arr = NULL;
  int amount = solve(0, 0, -1, &arr);
  ASSERT_EQUAL(0, amount);
}

CTEST(NoSolutions, test2) {
  double *arr = NULL;
  int amount = solve(1, 1, 1, &arr);
  ASSERT_EQUAL(0, amount);
}

CTEST(OneSolution, test1) {
  double *arr = NULL;
  int amount = solve(0, 1, 1, &arr);
  ASSERT_EQUAL(1, amount);
  ASSERT_DBL_NEAR(-1.00000, *arr);
  free(arr);
}

CTEST(OneSolution, test2) {
  double *arr = NULL;
  int amount = solve(1, -2, 1, &arr);
  ASSERT_EQUAL(1, amount);
  ASSERT_DBL_NEAR(1.00000, *arr);
  free(arr);
}

CTEST(TwoSolutions, test1) {
  double *arr = NULL;
  int amount = solve(1, 1, -6, &arr);
  ASSERT_EQUAL(2, amount);
  ASSERT_DBL_NEAR(-3.00000, *arr);
  ASSERT_DBL_NEAR(2.00000, *(arr + 1));
  free(arr);
}

CTEST(TwoSolutions, test2) {
  double *arr = NULL;
  int amount = solve(1, 0, -1, &arr);
  ASSERT_EQUAL(2, amount);
  ASSERT_DBL_NEAR(-1.00000, *arr);
  ASSERT_DBL_NEAR(1.00000, *(arr + 1));
  free(arr);
}

CTEST(InfSolutions, test1) {
  double *arr = NULL;
  int amount = solve(0, 0, 0, &arr);
  ASSERT_EQUAL(3, amount);
}
