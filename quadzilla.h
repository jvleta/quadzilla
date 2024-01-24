#ifndef QUADZILLA_H
#define QUADZILLA_H

#include <functional>

double quad(std::function<double(double)> func, double a, double b){
    double height = 0.5 * (func(b) + func(a));
    double base = b - a;
    return base * height;
}

#endif