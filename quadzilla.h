#ifndef QUADZILLA_H
#define QUADZILLA_H

#include <functional>

double trapezoid(std::function<double(double)> integrand, double left_endpoint,
                 double right_endpoint) {
  const double length1 = integrand(right_endpoint);
  const double length2 = integrand(left_endpoint);
  const double average_length = 0.5 * (length1 + length2);
  const double width = right_endpoint - left_endpoint;
  return average_length * width;
}

double composite_trapezoid(std::function<double(double)> integrand,
                           double left_endpoint, double right_endpoint,
                           int num_intervals) {
  double result = 0.0;
  const double dx =
      (right_endpoint - left_endpoint) / static_cast<double>(num_intervals - 1);
  
  for (int i = 0; i < num_intervals; ++i) {
    const double a = left_endpoint + i * dx;
    const double b = a + dx;
    result += trapezoid(integrand, a, b);
  }
  return result;
}

#endif