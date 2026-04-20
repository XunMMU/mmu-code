#include "Lab02_LinkedList_renameThisFile.hpp" // get from tutor
#include <ostream>
#include <sstream>
#include <vector>

template <typename T,
          std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
class HashTable {
  std::vector<LinkedList<T>> table;

  int hashfunction(const int &hashitem) const { // hash function
    return hashitem % table.size();
  }

public:
  HashTable(const int &size)
      : table(size) // resize vector to support size elements.
  {}

  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      this->table[i].makeEmpty();
  }

  int size() const { return this->table.size(); }

  void insert(const T newItem) {
    this->table[hashfunction(newItem)].insertFront(newItem);
  }

  bool retrieve(const T &target) const {
    return this->table[hashfunction(target)].find(target);
  }

  friend std::ostream &operator<<(std::ostream &os, const HashTable<T> &ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << std::endl;
    return os;
  }
};

template <typename T> struct std::formatter<HashTable<T>, char> {
  template <class ParseContext>
  constexpr ParseContext::iterator parse(ParseContext &ctx) {
    auto it = ctx.begin();
    return it;
  }
  template <class FmtContext>
  FmtContext::iterator format(const HashTable<T> &ht, FmtContext &ctx) const {
    std::ostringstream out;
    out << ht;
    return std::ranges::copy(std::move(out).str(), ctx.out()).out;
  }
};
