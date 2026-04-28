#include <cstddef>
#include <print>
#include <utility>
#include <vector>

template <typename T> void printArray(const T A[], const size_t &n) {
  for (size_t i = 0; i < n; i++)
    std::print("{} ", A[i]);
  std::println();
}

template <typename T,
          std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
class PriorityQueue {
  std::vector<T> A;

  void heapify_enqueue(const size_t &index) { // used in heapify enqueue.
    if (index == 0)                           // if already at root.
      return;

    // parent index
    size_t parent = (index - 1) / 2;
    // swap if parent is smaller
    if (this->A[parent] < this->A[index]) {
      std::swap(this->A[parent], this->A[index]);
    }

    // recursion of the function
    this->heapify_enqueue(index - 1);
  }

  void heapify_dequeue(const size_t &index) { // used in heapify dequeue.
    size_t max = index;                       // max index
    // left child index
    const size_t left_i = index * 2 + 1;
    // right child index
    const size_t right_i = index * 2 + 2;
    // compare and find the greatest child
    if (left_i < this->A.size() && this->A[left_i] > this->A[index]) {
      max = left_i;
    }

    if (right_i < this->A.size() && this->A[right_i] > this->A[index]) {
      max = right_i;
    }

    if (left_i < this->A.size() && right_i < this->A.size()) {
      if (this->A[left_i] > this->A[right_i]) {
        max = left_i;
      } else {
        max = right_i;
      }
    }

    if (max != index) {
      std::swap(this->A[index], this->A[max]);
      this->heapify_dequeue(max); // recursion
    }
  }

public:
  void init(const std::vector<T> &ary) {
    this->A = ary;
    for (size_t i = (A.size() - 1) / 2; i > 0; i--)
      this->heapify_dequeue(i);
    this->heapify_dequeue(0);
  }

  void enqueue(T element) {
    this->A.push_back(element);
    this->heapify_enqueue(A.size() - 1); // start at last element.
  }

  T dequeue() {
    T removed_element = A[0];
    this->A[0] = this->A[this->A.size() - 1]; // copy last element to root.
    this->A.pop_back();                       // remove last element.
    this->heapify_dequeue(0);                 // start at root.
    return removed_element;
  }

  size_t size() const { return this->A.size(); }

  void print() const {
    for (size_t i = 0; i < this->A.size(); i++)
      std::print("{} ", this->A[i]);
    std::println();
  }
};

int main() {
  constexpr int A[] = {4, 2, 5, 8, 6, 9, 3, 7};
  constexpr size_t n = std::size(A);
  std::print("Array = ");
  printArray(A, n);

  std::println("\nINIT Enqueue\t: PriorityQueue");
  const std::vector<int> B = {4, 2, 5, 8, 6, 9, 3, 7};
  PriorityQueue<int> pp;
  pp.init(B);
  pp.print();

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
