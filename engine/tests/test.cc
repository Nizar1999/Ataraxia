#include <gtest/gtest.h>

TEST(TryTest, Test1) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}
