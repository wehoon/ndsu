#include <gtest/gtest.h>
#include "ndsu/coordinate.h"

using namespace ndsu;

class NdsCoordinateTest : public ::testing::Test {};

TEST_F(NdsCoordinateTest, operator) {
  EXPECT_EQ(NdsCoordinate(27374451, 582901293), NdsCoordinate(27374451, 582901293));
  EXPECT_EQ(NdsCoordinate(-883384626, 485440671), NdsCoordinate(-883384626, 485440671));
  EXPECT_EQ(NdsCoordinate(-514888362, -273788154), NdsCoordinate(-514888362, -273788154));

  EXPECT_LT(NdsCoordinate(14888362, -273788154), NdsCoordinate(1804055545, -403936054));
  EXPECT_LT(NdsCoordinate(-883384626, 403936054), NdsCoordinate(-883384626, 485440671));
  EXPECT_LT(NdsCoordinate(83384626, -403936054), NdsCoordinate(1804055545, -403936054));
}

TEST_F(NdsCoordinateTest, shift) {
  EXPECT_EQ(NdsCoordinate(27374451, 582901293).Shift(2),
            NdsCoordinate((27374451 >> 2), (582901293 >> 2)));
  EXPECT_EQ(NdsCoordinate(-27374451, -582901293).Shift(4),
            NdsCoordinate((-27374451 >> 4), (-582901293 >> 4)));

  EXPECT_EQ(NdsCoordinate(27374451, 5829012).DeShift(2),
            NdsCoordinate((27374451 << 2), (5829012 << 2)));
  EXPECT_EQ(NdsCoordinate(-27374451, -5829012).DeShift(4),
            NdsCoordinate(((-27374451) << 4), ((-5829012) << 4)));
}