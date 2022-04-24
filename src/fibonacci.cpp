#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    double sqrt_5 = sqrt(5);
    double x1 = pow((1 - sqrt_5) / 2, 2);
    double x2 = pow((1 + sqrt_5) / 2, 2);
    double ans = ((x1 - x2) / sqrt_5);
    return ans;
  }

  int64_t fib_iterative(int n) {
    if (n <= 1) {
      return n;
    }
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    int res;
    for (int i = 1; i < n; i++) {
      res = fib_curr + fib_prev;
      fib_prev = fib_curr;
      fib_curr = res;
    }
    return res;
  }

  int64_t fib_recursive(int n) {
    if (n <= 1) {
      return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {
    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }
    cache[n] = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);
    return cache[n];
  }

  int64_t fib_matrix(int n) {
    if (n <= 1) {
      return n;
    }
    Matrix2x2 matrix = matrix_power(FibMatrix, n);
    return matrix[0][1];
  }
}