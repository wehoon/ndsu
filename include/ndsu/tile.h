#ifndef NDSU_INCLUDE_NDSU_TILE_H_
#define NDSU_INCLUDE_NDSU_TILE_H_

#include <cmath>
#include <iostream>

namespace ndsu {

class NdsTile {
 public:
  uint32_t tile_num;
  uint8_t level;

  NdsTile() : tile_num(0), level(0) {}
  NdsTile(uint32_t tile_num_, uint8_t level_) : tile_num(tile_num_), level(level_) {}
  explicit NdsTile(uint32_t packed_id) {
    level = static_cast<uint8_t>(log2(packed_id) - 16);
    tile_num = packed_id & ((1L << (2 * level + 2)) - 1);
  }

  uint32_t getPackedId() const { return (1 << (16 + level)) | tile_num; }

  uint32_t getWidth() const { return 1L << (31 - level); }

  bool operator==(const NdsTile& rhs) const {
    return (tile_num == rhs.tile_num) && (level == rhs.level);
  }

  bool operator<(const NdsTile& rhs) const { return getPackedId() < rhs.getPackedId(); }

  friend std::ostream& operator<<(std::ostream& os, const NdsTile& obj);
};

}  // namespace ndsu

namespace std {
inline ostream& operator<<(ostream& os, const ndsu::NdsTile& obj) {
  os << "NdsTile([" << obj.level << "]" << obj.tile_num << ")";
  return os;
}
}  // namespace std

#endif  // NDSU_INCLUDE_NDSU_TILE_H_
