/*
        MIT License

        Copyright (c) 2025 Nizar Daouk

        Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
        furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/

#include <gtest/gtest.h>
#include <vector.h>

// ------------------------- Vector 3 ------------------------
TEST(Vec3Test, AssignmentFromV2) {
  ata::Vec2 v2(1.0f, 2.0f);
  ata::Vec3 v3;

  v3 = v2;
  EXPECT_FLOAT_EQ(v2.x, v3.x);
  EXPECT_FLOAT_EQ(v2.y, v3.y);
  EXPECT_FLOAT_EQ(0.0f, v3.z);
}

TEST(Vec3Test, DifferentTypesAssignmentFromV2) {
  ata::Vec2 v2(1.5f, 2.5f);
  ata::IVec3 v3;

  v3 = v2;
  EXPECT_FLOAT_EQ(v2.x, static_cast<float>(v3.x) + 0.5f);
  EXPECT_FLOAT_EQ(v2.y, static_cast<float>(v3.y) + 0.5f);
  EXPECT_EQ(0.0f, v3.z);
}

TEST(Vec3Test, DifferentTypesConstructionFromV2) {
  ata::Vec2 v2(1.5f, 2.5f);
  ata::IVec3 v3 = v2;

  EXPECT_FLOAT_EQ(v2.x, static_cast<float>(v3.x) + 0.5f);
  EXPECT_FLOAT_EQ(v2.y, static_cast<float>(v3.y) + 0.5f);
  EXPECT_EQ(0, v3.z);
}

TEST(Vec3Test, UnaryNegation) {
  ata::IVec3 v{1, 2, 3};

  v = -v;
  EXPECT_EQ(-1, v.x);
  EXPECT_EQ(-2, v.y);
  EXPECT_EQ(-3, v.z);
}

TEST(Vec3Test, ScalarMultiplication) {
  ata::IVec3 v{1, 2, 3};

  v = v * 2;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(4, v.y);
  EXPECT_EQ(6, v.z);

  v = 5 * v;
  EXPECT_EQ(10, v.x);
  EXPECT_EQ(20, v.y);
  EXPECT_EQ(30, v.z);
}

// ------------------------- Vector 2 ------------------------
TEST(Vec2Test, AssignmentFromV3) {
  ata::Vec3 v3(1.0f, 2.0f, 0.0f);
  ata::Vec2 v2;

  v2 = v3;
  EXPECT_FLOAT_EQ(v3.x, v2.x);
  EXPECT_FLOAT_EQ(v3.y, v2.y);
}

TEST(Vec2Test, DifferentTypesAssignmentFromV3) {
  ata::Vec3 v3(1.5f, 2.5f, 0.0f);
  ata::IVec2 v2;

  v2 = v3;
  EXPECT_FLOAT_EQ(v3.x, static_cast<float>(v2.x) + 0.5f);
  EXPECT_FLOAT_EQ(v3.y, static_cast<float>(v2.y) + 0.5f);
}

TEST(Vec2Test, DifferentTypesConstructionFromV3) {
  ata::Vec3 v3(1.5f, 2.5f, 0.0f);
  ata::IVec2 v2 = v3;

  EXPECT_FLOAT_EQ(v3.x, static_cast<float>(v2.x) + 0.5f);
  EXPECT_FLOAT_EQ(v3.y, static_cast<float>(v2.y) + 0.5f);
}

TEST(Vec2Test, UnaryNegation) {
  ata::IVec2 v{1, 2};

  v = -v;
  EXPECT_EQ(-1, v.x);
  EXPECT_EQ(-2, v.y);
}

TEST(Vec2Test, ScalarMultiplication) {
  ata::IVec2 v{1, 2};

  v = v * 2;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(4, v.y);

  v = 5 * v;
  EXPECT_EQ(10, v.x);
  EXPECT_EQ(20, v.y);
}
