#include <cstddef>
#include <print>
#include <utility>
#include <vector>

template <typename T> void printArray(const T A[], const size_t &n) {
  for (size_t i = 0; i < n; i++)
    std::print("{} ", A[i]);
  std::println();
}

template <typename T> class PriorityQueue {
  std::vector<T> A;

  void heapify_enqueue(const size_t &index) { // used in heapify enqueue.
    if (index == 0)                           // if already at root.
      return;

    // parent index

    // swap if parent is smaller
    if (A[index] < A[index - 1]) {
      std::swap(A[index], A[index - 1]);
    } else {
      return;
    }

    // recursion of the function
    heapify_enqueue(index - 1);
  }

  void heapify_dequeue(const size_t &index) { // used in heapify dequeue.
    size_t max = index;                       // max index
    if (index == A.size() - 1 || A.size() == 0)
      return;
    // left child index
    const T &left = A[index];
    // right child index
    const T &right = A[index + 1];
    // compare and find the greatest child, and the greast child index become
    // max
    if (left > right) {
      max++;
    }

    if (max != index) {
      std::swap(A[index], A[max]);
      heapify_dequeue(max); // recursion
    }
  }

public:
  void enqueue(T element) {
    A.push_back(element);
    heapify_enqueue(A.size() - 1); // start at last element.
  }

  T dequeue() {
    T removed_element = A[0];
    A[0] = A[A.size() - 1]; // copy last element to root.
    A.pop_back();           // remove last element.
    heapify_dequeue(0);     // start at root.
    return removed_element;
  }

  size_t size() const { return A.size(); }

  void print() const {
    for (size_t i = 0; i < A.size(); i++)
      std::print("{} ", A[i]);
    std::println();
  }
};

int main() {
  constexpr int A[] = {4, 2, 5, 8, 6, 9, 3, 7};
  constexpr size_t n = std::size(A);
  std::print("Array = ");
  printArray(A, n);

  std::println("\nEnqueue\t: PriorityQueue");
  PriorityQueue<int> pq;
  for (size_t i = 0; i < n; i++) {
    std::print("{}\t: ", A[i]);
    pq.enqueue(A[i]);
    pq.print();
  }

  std::println("\nDequeue\t: PriorityQueue");
  for (size_t i = 0; i < n; i++) {
    std::print("{}\t: ", pq.dequeue());
    pq.print();
  }
}
