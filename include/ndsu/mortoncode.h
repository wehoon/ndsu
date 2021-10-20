#ifndef NDSU_INCLUDE_NDSU_MORTONCODE_H_
#define NDSU_INCLUDE_NDSU_MORTONCODE_H_

#include <iostream>

namespace ndsu {

class NdsMortonCode {
 public:
  uint64_t code;

  NdsMortonCode() : code(0) {}
  explicit NdsMortonCode(uint64_t code_) : code(code_) {}

  bool operator==(const NdsMortonCode& rhs) const { return code == rhs.code; }

  bool operator<(const NdsMortonCode& rhs) const { return code < rhs.code; }

  bool operator>(const NdsMortonCode& rhs) const { return code > rhs.code; }

  friend std::ostream& operator<<(std::ostream& os, const NdsMortonCode& obj);
};

}  // namespace ndsu

namespace std {
inline ostream& operator<<(ostream& os, const ndsu::NdsMortonCode& obj) {
  os << "NdsMortonCode(" << obj.code << ")";
  return os;
}
}  // namespace std

#endif  // NDSU_INCLUDE_NDSU_MORTONCODE_H_
