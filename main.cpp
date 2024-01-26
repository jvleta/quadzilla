#include <iostream>
#include <ratio>

#include "quadzilla.h"

#include "gtest/gtest.h"

TEST(TrapezoidTests, Square) {
  constexpr double side_length = 5.0;
  constexpr double expected_area = 25.0;
  const auto integrand = [](double x) { return side_length; };
  EXPECT_EQ(expected_area, trapezoid(integrand, 0.0, side_length));
}

TEST(TrapezoidTests, SawTooth) {
  const auto integrand = [](double x) {
    constexpr double base = 1.0;
    constexpr double height = 1.0;
    return height / base * x;
  };
  ASSERT_EQ(0.5, trapezoid(integrand, 0.0, 1.0));
}

TEST(CompositeTrapezoidTests, Parabola) {
  const auto x_squared = [](double x) { return x * x; };
  const double expected = 2.0 / 3.0;
  const auto check = [&](int num_intervals, double tolerance) {
    const double estimated =
        composite_trapezoid(x_squared, -1.0, 1.0, num_intervals);
    const double relative_error = std::abs((expected - estimated) / expected);
    ASSERT_LE(relative_error, tolerance);
  };
  check(1000, 1e-2);
  check(10000, 1e-3);
  check(100000, 1e-4);
  check(1000000, 1e-5);
  check(10000000, 1e-6);
  check(100000000, 1e-7);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}