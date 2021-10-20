#include <gtest/gtest.h>
#include "ndsu/tile.h"

using namespace ndsu;

class NdsTileTest : public ::testing::Test {};

TEST_F(NdsTileTest, GetPackedID) {
  EXPECT_EQ(NdsTile(34897, 10).getPackedId(), 67143761);
  EXPECT_EQ(NdsTile(2233410, 13).getPackedId(), 539104322);

  EXPECT_EQ(NdsTile(67143761).getPackedId(), 67143761);
  EXPECT_EQ(NdsTile(539104322).getPackedId(), 539104322);
}

TEST_F(NdsTileTest, GetWidth) {
  EXPECT_EQ(NdsTile(34897, 10).getWidth(), 2097152);
  EXPECT_EQ(NdsTile(2233410, 13).getWidth(), 262144);

  EXPECT_EQ(NdsTile(67143761).getWidth(), 2097152);
  EXPECT_EQ(NdsTile(539104322).getWidth(), 262144);
}

TEST_F(NdsTileTest, operator) {
  EXPECT_EQ(NdsTile(34897, 10), NdsTile(34897, 10));
  EXPECT_EQ(NdsTile(34897, 10), NdsTile(67143761));
  EXPECT_EQ(NdsTile(67143761), NdsTile(67143761));

  EXPECT_LT(NdsTile(34897, 10), NdsTile(34897, 13));
  EXPECT_LT(NdsTile(34897, 10), NdsTile(2233410, 13));
  EXPECT_LT(NdsTile(67143761), NdsTile(539104322));
  EXPECT_LT(NdsTile(67143761), NdsTile(2233410, 13));
  EXPECT_LT(NdsTile(34897, 10), NdsTile(539104322));
}