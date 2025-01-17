#include <gtest/gtest.h>
#include "CudaHelpers.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, CudaHelperDeviceCount) {
  EXPECT_EQ(cudahelpers::deviceCount(5) , 25);
  EXPECT_EQ(cudahelpers::theD(5) , 25);
}

TEST(HelloTest, CudaHelperTheD) {
  EXPECT_EQ(cudahelpers::theD(5), 25);
}