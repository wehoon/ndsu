#include <gtest/gtest.h>
#include "ndsu/mortoncode.h"

using namespace ndsu;

class NdsMortonCodeTest : public ::testing::Test {};

TEST_F(NdsMortonCodeTest, operator) {
  EXPECT_EQ(NdsMortonCode(579221254078012839), NdsMortonCode(579221254078012839));
  EXPECT_EQ(NdsMortonCode(5973384896724652798), NdsMortonCode(5973384896724652798));

  EXPECT_LT(NdsMortonCode(579221254078012839), NdsMortonCode(5973384896724652798));
  EXPECT_LT(NdsMortonCode(5973384896724652798), NdsMortonCode(8983442095026671932));
}

TEST_F(NdsMortonCodeTest, GetCode) {
  EXPECT_EQ(NdsMortonCode(579221254078012839).code, 579221254078012839);
  EXPECT_EQ(NdsMortonCode(5973384896724652798).code, 5973384896724652798);
}