#ifndef NDSU_INCLUDE_NDSU_COORDINATE_H_
#define NDSU_INCLUDE_NDSU_COORDINATE_H_

#include <iostream>

namespace ndsu {

class NdsCoordinate {
 public:
  int32_t x;
  int32_t y;

  NdsCoordinate() : x(0), y(0) {}
  NdsCoordinate(int32_t x_, int32_t y_) : x(x_), y(y_) {}

  bool operator==(const NdsCoordinate& rhs) const { return x == rhs.x && y == rhs.y; }

  bool operator!=(const NdsCoordinate& rhs) const { return !(*this == rhs); }

  bool operator<(const NdsCoordinate& rhs) const {
    return (x == rhs.x) ? (y < rhs.y) : (x < rhs.x);
  }

  bool operator>(const NdsCoordinate& rhs) const { return (*this != rhs) && !(*this < rhs); }

  NdsCoordinate operator+(const NdsCoordinate& rhs) const {
    return NdsCoordinate(x + rhs.x, y + rhs.y);
  }

  NdsCoordinate operator-(const NdsCoordinate& rhs) const {
    return NdsCoordinate(x - rhs.x, y - rhs.y);
  }

  void operator+=(const NdsCoordinate& rhs) {
    x += rhs.x;
    y += rhs.y;
  }

  void operator-=(const NdsCoordinate& rhs) {
    x -= rhs.x;
    y -= rhs.y;
  }

  NdsCoordinate operator<<(size_t bit) { return NdsCoordinate(x << bit, y << bit); }

  NdsCoordinate operator>>(size_t bit) { return NdsCoordinate(x >> bit, y >> bit); }

  void operator<<=(size_t bit) {
    x <<= bit;
    y <<= bit;
  }

  void operator>>=(size_t bit) {
    x >>= bit;
    y >>= bit;
  }

  NdsCoordinate& Shift(size_t bit) {
    *this >>= bit;
    return *this;
  }

  NdsCoordinate& DeShift(size_t bit) {
    *this <<= bit;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const NdsCoordinate& obj);
};

}  // namespace ndsu

namespace std {
inline ostream& operator<<(ostream& os, const ndsu::NdsCoordinate& obj) {
  os << "NdsCoordinate(" << obj.x << "," << obj.y << ")";
  return os;
}
}  // namespace std

#endif  // NDSU_INCLUDE_NDSU_COORDINATE_H_
