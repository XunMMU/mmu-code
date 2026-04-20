// #include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <print>
#include <random>

int64_t arrayMax(int64_t A[], size_t n) {
  int64_t currentMax = A[0];
  for (size_t i = 1; i <= n - 1; i++) {
    if (A[i] > currentMax)
      currentMax = A[i];
  }
  return currentMax;
}

template <typename T> void printArray(const T A[], const size_t &n) {
  for (size_t i = 0; i < n; i++)
    std::print("{} ", A[i]);
  std::println();
}

int main() {
  constexpr size_t N = 500;

  std::random_device rd;  // a seed source for the random number engine
  std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<int64_t> distrib(0); // range of 0-I64::MAX

  std::unique_ptr<std::array<int64_t, N>> A(new std::array<int64_t, N>);

  for (int64_t &i : *A)
    i = distrib(gen); // generate randon number defined by the range.

  std::println("Array A:");
  printArray(A->begin(), N);

  const auto start = std::chrono::steady_clock::now();
  // const int64_t currentMax = *std::max_element(A->begin(), A->end());
  const int64_t currentMax = arrayMax(A->begin(), N);
  const auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> duration = end - start;

  std::println("The maximum integer in A is {}", currentMax);
  std::println("Duration: {}s", duration.count());

  return 0;
}
