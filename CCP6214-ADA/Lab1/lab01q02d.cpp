#include <chrono>
#include <cstddef>
#include <cstdint>
#include <print>
#include <random>
#include <thread>
#include <type_traits>
#include <vector>

constexpr size_t N = 10 * 1000 * 1000; // size of vector
typedef int16_t APP_NUM_TYPE;          // change the type universal

std::vector<APP_NUM_TYPE> GLOBAL_A(N);

template <typename T>
void printArray(const std::vector<T> &A, const size_t &N) {
  for (size_t i = 0; i < N; i++)
    std::print("{} ", A[i]);
  std::println();
}

template <typename T>
bool verifyArray(const std::vector<T> &a, const std::vector<T> &b) {
  if (a.size() != b.size())
    return false;
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

namespace linear {
template <typename T,
          std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
inline void partialSum(const std::vector<T> &A, std::vector<T> &S,
                       const size_t &N) {
  T ps = 0;
  for (size_t i = 0; i < N; i++) {
    ps += A[i];
    S[i] = ps;
  }
}

template <typename T,
          std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
void main(std::vector<T> &x, const size_t &size) {
  x.resize(size);
  const auto start = std::chrono::steady_clock::now();
  partialSum(GLOBAL_A, x, size);
  const auto end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> duration = end - start;
  std::println("{} Linear DONE ({})", size, duration);
}
} // namespace linear

namespace quad {
template <typename T,
          std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
inline void partialSum(const std::vector<T> &A, std::vector<T> &S,
                       const size_t &N) {
  S[0] = A[0];
  for (size_t i = 1; i < N; i++) {
    S[i] = A[0];
    for (size_t j = 1; j <= i; j++)
      S[i] = S[i] + A[j];
  }
}

template <typename T,
          std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
void main(std::vector<T> &x, const size_t &size) {
  x.resize(size);
  const auto start = std::chrono::steady_clock::now();
  partialSum(GLOBAL_A, x, size);
  const auto end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> duration = end - start;
  std::println("{} Quad DONE ({})", size, duration);
}
} // namespace quad

int main() {
  std::random_device rd;  // a seed source for the random number engine
  std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<int16_t> distrib(0, 100); // range of 0-100

  for (auto &i : GLOBAL_A) {
    i = distrib(gen);
  }

  constexpr size_t testary[] = {10000,  50000,   100000,  250000,  500000,
                                750000, 1000000, 5000000, 10000000};
  std::vector<APP_NUM_TYPE> v1{}, v2{};

  for (const size_t &i : testary) {

    std::jthread t1(quad::main<APP_NUM_TYPE>, std::ref(v1), i),
        t2(linear::main<APP_NUM_TYPE>, std::ref(v2), i);

    t1.join();
    t2.join();

    if (verifyArray(v1, v2)) { // additional O(n) here to verify
      std::println("Array Verified");
    } else {
      std::println("Error in Array");
      return 1;
    }
  }

  return 0;
}
