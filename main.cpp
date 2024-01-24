#include <iostream>

#include "quadzilla.h"

#include "gtest/gtest.h"

TEST(BasicTests, Square) {
  constexpr double side_length = 5.0;
  constexpr double expected_area = 25.0;
  const auto integrand = [](double x) { return side_length; };
  EXPECT_EQ(expected_area, quad(integrand, 0.0, side_length));
}

TEST(BasicTests, Triangle1) {
  const auto integrand = [](double x) {
    constexpr double base = 1.0;
    constexpr double height = 1.0;
    return height / base * x;
  };
  ASSERT_EQ(0.5, quad(integrand, 0.0, 1.0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}