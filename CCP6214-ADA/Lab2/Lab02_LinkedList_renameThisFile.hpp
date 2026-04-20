// LinkedList.cpp -- class for a linked list as a data structure
// use std::forward_list instead
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template <typename T> struct Node {
  T info;
  Node<T> *next;
};

template <typename T> class LinkedList {
private:
  Node<T> *start;

public:
  LinkedList() : start(nullptr) {}

  ~LinkedList() { makeEmpty(); }

  // inserts at the beginning of the linked list
  void insertFront(const T &element) {
    Node<T> *newNode = new Node<T>;
    newNode->info = element;
    newNode->next = start;
    start = newNode;
  }

  // returns true if element is found; returns false if element is not found
  bool find(const T &target) const {
    Node<T> *ptr = start;
    while (ptr != nullptr) {
      if (ptr->info == target)
        return true;
      ptr = ptr->next;
    }
    return false;
  }

  bool isEmpty() const { return start == nullptr; }

  void makeEmpty() {
    while (start != nullptr) {
      Node<T> *ptr = start;
      start = start->next;
      delete ptr;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
    Node<T> *ptr = list.start;
    while (ptr != nullptr) {
      os << ptr->info << " ";
      ptr = ptr->next;
    }
    return os;
  }
};

#endif
