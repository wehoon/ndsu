#include <gtest/gtest.h>
#include "ndsu/algorithm.h"

using namespace ndsu;

class NdsAlgorithmTest : public ::testing::Test {};

TEST_F(NdsAlgorithmTest, GetBelongTile) {
  auto TestFun = [](int32_t x, int32_t y, uint64_t mortoncode, uint32_t tile_num, uint8_t level) {
    NdsCoordinate np = NdsCoordinate(x, y);
    NdsMortonCode ncode = NdsMortonCode(mortoncode);
    NdsTile tile = NdsTile(tile_num, level);

    EXPECT_EQ(GetBelongTile(ncode, level), tile);
    EXPECT_EQ(GetBelongTile(x, y, level), tile);
    EXPECT_EQ(GetBelongTile(np, level), tile);
  };

  TestFun(27374451, 582901293, 579221254078012839, 131699, 10);
  TestFun(27374451, 582901293, 579221254078012839, 8428778, 13);
  TestFun(-883384626, 485440671, 5973384896724652798, 1358190, 10);
  TestFun(-883384626, 485440671, 5973384896724652798, 86924190, 13);
  TestFun(-514888362, -273788154, 8983442095026671932, 2042598, 10);
  TestFun(-514888362, -273788154, 8983442095026671932, 130726287, 13);
  TestFun(1804055545, -403936054, 4354955230616876489, 990202, 10);
  TestFun(1804055545, -403936054, 4354955230616876489, 63372939, 13);
  TestFun(0, 614454724, 585611620934393888, 133152, 10);
  TestFun(0, 614454724, 585611620934393888, 8521770, 13);
  TestFun(-935944956, 0, 5782627506097029136, 1314817, 10);
  TestFun(-935944956, 0, 5782627506097029136, 84148305, 13);
}

TEST_F(NdsAlgorithmTest, GetTileLevelWidth) {
  EXPECT_EQ(GetTileLevelWidth(10), 2097152);
  EXPECT_EQ(GetTileLevelWidth(13), 262144);
}

TEST_F(NdsAlgorithmTest, GetTileSouthWest) {
  // TODO
}

TEST_F(NdsAlgorithmTest, GetTileAnchor) {
  // TODO
}