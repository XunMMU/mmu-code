#include <chrono>
#include <cstddef>
#include <print>
// 1. Add chrono library.

// 2. Add partialSum function.

template <typename T> void partialSum(const T A[], T S[], const size_t &N) {
  T ps = 0;
  for (size_t i = 0; i < N; i++) {
    ps += A[i];
    S[i] = ps;
  }
}

template <typename T> void printArray(const T A[], const size_t &N) {
  for (size_t i = 0; i < N; i++)
    std::print("{} ", A[i]);
  std::println();
}

int main() {
  constexpr size_t N = 8;
  const int *const A = new int[N]{11, 23, 5, 27, 33, 1, 45, 18};
  int *const S = new int[N];

  // 3. Take start time.

  auto start = std::chrono::steady_clock::now();

  // 4. Call partialSum.

  partialSum(A, S, N);

  // 5. Take end time.

  auto end = std::chrono::steady_clock::now();

  // 6. Calculate duration.

  auto duration = end - start;

  std::println("A:");
  printArray(A, N);
  std::println("Partial sum S:");
  printArray(S, N);

  // 7. Display duration.

  std::println("{}", duration);

  delete[] A;
  delete[] S;

  return 0;
}
