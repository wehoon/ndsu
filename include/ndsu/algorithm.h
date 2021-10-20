#ifndef NDSU_INCLUDE_NDSU_ALGORITHM_H_
#define NDSU_INCLUDE_NDSU_ALGORITHM_H_

#include <cassert>
#include "coordinate.h"
#include "mortoncode.h"
#include "tile.h"
#include "transform.h"

namespace ndsu {

inline NdsTile GetBelongTile(const NdsMortonCode& mortoncode, size_t level) {
  uint32_t tile_num = mortoncode.code >> (63 - 2 * level - 1);
  return NdsTile(tile_num, level);
}

inline NdsTile GetBelongTile(int32_t nds_x, int32_t nds_y, size_t level) {
  NdsMortonCode code = NdsCoordinateToNdsMortonCode(nds_x, nds_y);
  return GetBelongTile(code, level);
}

inline NdsTile GetBelongTile(const NdsCoordinate& coord, size_t level) {
  return GetBelongTile(coord.x, coord.y, level);
}

inline uint32_t GetTileLevelWidth(size_t level) {
  assert(0 <= level && level <= 15);
  return 1L << (31 - level);  // 2^(31-k) in level k
}

inline NdsMortonCode GetTileSouthWestMortonCode(const NdsTile& tile) {
  uint64_t code = tile.tile_num << (62 - 2 * tile.level);
  return NdsMortonCode(code);
}

inline NdsCoordinate GetTileSouthWestCoordinate(const NdsTile& tile) {
  return NdsMortonCodeToNdsCoordinate(GetTileSouthWestMortonCode(tile));
}

inline NdsCoordinate GetTileAnchor(const NdsTile& tile) {
  NdsCoordinate coord = GetTileSouthWestCoordinate(tile);
  uint32_t half_tile_width = tile.getWidth() / 2;
  coord.x += half_tile_width;
  coord.y += half_tile_width;
  return coord;
}

}  // namespace ndsu

#endif  // NDSU_INCLUDE_NDSU_ALGORITHM_H_
