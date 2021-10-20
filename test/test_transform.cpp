#include <gtest/gtest.h>
#include "ndsu/transform.h"

using namespace ndsu;

class NdsTransformTest : public ::testing::Test {};

bool isDoubleZero(double d) { return -0.00001 < d && d < 0.00001; }

bool isDoubleEqual(double x, double y) { return isDoubleZero(x - y); }

TEST_F(NdsTransformTest, Transform) {
  auto TestFun = [](int32_t nds_x, int32_t nds_y, uint64_t mortoncode, double wgs_x, double wgs_y) {
    NdsCoordinate np = NdsCoordinate(nds_x, nds_y);
    NdsMortonCode ncode = NdsMortonCode(mortoncode);

    EXPECT_EQ(NdsCoordinateToNdsMortonCode(np), ncode);
    EXPECT_EQ(NdsCoordinateToNdsMortonCode(nds_x, nds_y), ncode);
    EXPECT_EQ(NdsMortonCodeToNdsCoordinate(ncode), np);
    double wgs_exp_x, wgs_exp_y;
    NdsCoordinateToWgsCoordinate(nds_x, nds_y, wgs_exp_x, wgs_exp_y);
    EXPECT_TRUE(isDoubleEqual(wgs_exp_x, wgs_x));
    EXPECT_TRUE(isDoubleEqual(wgs_exp_y, wgs_y));
    int32_t nds_exp_x, nds_exp_y;
    WgsCoordinateToNdsCoordinate(wgs_x, wgs_y, nds_exp_x, nds_exp_y);
    EXPECT_EQ(nds_exp_x, nds_x);
    EXPECT_EQ(nds_exp_y, nds_y);
  };

  TestFun(27374451, 582901293, 579221254078012839, 2.2945, 48.858222);
  TestFun(-883384626, 485440671, 5973384896724652798, -74.044444, 40.689167);
  TestFun(-514888362, -273788154, 8983442095026671932, -43.157444, -22.948658);
  TestFun(1804055545, -403936054, 4354955230616876489, 151.214189, -33.857529);
  TestFun(0, 614454724, 585611620934393888, 0.0, 51.503);
  TestFun(-935944956, 0, 5782627506097029136, -78.45, 0.0);
}