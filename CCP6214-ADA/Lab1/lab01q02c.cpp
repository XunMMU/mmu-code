#include <chrono>
#include <cstddef>
#include <print>
// 1. Add chrono library.

// 2. Add partialSum function.

template <typename T> void partialSum(const T A[], T S[], const size_t &N) {
  S[0] = A[0];
  for (size_t i = 1; i < N; i++) {
    S[i] = A[0];
    for (size_t j = 1; j <= i; j++)
      S[i] = S[i] + A[j];
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

  const auto start = std::chrono::steady_clock::now();

  // 4. Call partialSum.

  partialSum(A, S, N);

  // 5. Take end time.

  const auto end = std::chrono::steady_clock::now();
  // 6. Calculate duration.

  auto duration = end - start;

  std::println("A:");
  printArray(A, N);
  std::println("Partial sum S:");
  printArray(S, N);

  // 7. Display duration.

  std::println("{}", duration.count());
}
