#include "HashTable.cpp"
#include <iostream>
#include <print>
// 1. Include HashTable.cpp.

int main() {
  constexpr int n = 10;
  constexpr int A[n] = {36, 99, 80, 21, 58, 11, 25, 46, 91, 10};
  // 2. Declare a hashtable of int named "ht", size is 11.
  HashTable ht = HashTable<int>(11);

  std::print("Array : ");
  for (int i = 0; i < n; i++) {
    std::print("{} ", A[i]);
    // 3. Insert A[i] into ht.
    ht.insert(A[i]);
  }
  std::println();

  // Display ht.
  std::println("{}", ht); // no implementation for print

  int target;
  std::print("Target to retrieve: ");
  std::cin >> target;
  // 4. Retrieve the target from ht.
  if (ht.retrieve(target))
    std::println("Target found");
  else
    std::println("Target not found");
}
