#ifndef NDSU_INCLUDE_NDSU_TRANSFORM_H_
#define NDSU_INCLUDE_NDSU_TRANSFORM_H_

#include "coordinate.h"
#include "mortoncode.h"
#include "tile.h"

namespace ndsu {

const double kNdsWgsRatio = (1L << 32) / 360.0;

inline void WgsCoordinateToNdsCoordinate(const double& wgs_x,
                                         const double& wgs_y,
                                         int32_t& nds_x,
                                         int32_t& nds_y) {
  nds_x = wgs_x * kNdsWgsRatio;
  nds_y = wgs_y * kNdsWgsRatio;
}

inline void NdsCoordinateToWgsCoordinate(const int32_t& nds_x,
                                         const int32_t& nds_y,
                                         double& wgs_x,
                                         double& wgs_y) {
  wgs_x = static_cast<double>(nds_x) / kNdsWgsRatio;
  wgs_y = static_cast<double>(nds_y) / kNdsWgsRatio;
}

inline NdsMortonCode NdsCoordinateToNdsMortonCode(const int32_t& x, const int32_t& y) {
  uint64_t code(0);
  for (size_t p = 0; p < 31; ++p) {
    code |= (((uint64_t)x >> p) & 0x1) << (2 * p);
    code |= (((uint64_t)y >> p) & 0x1) << (2 * p + 1);
  }
  code |= (((uint64_t)x >> 31) & 0x1) << 62;
  return NdsMortonCode(code);
}

inline NdsMortonCode NdsCoordinateToNdsMortonCode(const NdsCoordinate& coord) {
  return NdsCoordinateToNdsMortonCode(coord.x, coord.y);
}

inline NdsCoordinate NdsMortonCodeToNdsCoordinate(const uint64_t& code) {
  int32_t x(0);
  int32_t y(0);
  for (size_t p = 0; p < 31; ++p) {
    x |= ((code >> (2 * p)) & 0x1) << p;
    y |= ((code >> (2 * p + 1)) & 0x1) << p;
  }
  x |= ((code >> 62) & 0x1) << 31;
  y |= ((y >> 30) & 0x1) << 31;
  return NdsCoordinate(x, y);
}

inline NdsCoordinate NdsMortonCodeToNdsCoordinate(const NdsMortonCode& mortoncode) {
  return NdsMortonCodeToNdsCoordinate(mortoncode.code);
}

}  // namespace ndsu

#endif  // NDSU_INCLUDE_NDSU_TRANSFORM_H_
