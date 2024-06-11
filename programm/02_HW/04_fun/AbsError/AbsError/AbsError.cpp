#include <iostream>
#include <cmath>

double computeFunctionValue(double x, double absError, int nMax) {
    if (x <= -1 || x >= 1) {
        throw std::runtime_error("Error! x is not in the interval (-1,1)");
    }

    double sum = 1;
    double term = 1;
    double fact = 1;
    int n = 1;

    while (std::abs(term) > absError && n <= nMax) {
        fact *= 2 * n;
        term *= -x / n;
        sum += term / fact;
        n++;
    }

    if (n > nMax) {
        throw std::runtime_error("Error! Maximum number of terms exceeded.");
    }

    return sum;
}

int main() {
    double intervalStart, intervalEnd, step, absError;
    int nMax;
    std::cin >> intervalStart >> intervalEnd >> step >> absError >> nMax;

    std::cout << "x\tComputed Value\tStd Function Value";

        for (double x = intervalStart; x <= intervalEnd; x += step) {
            try {
                double computedValue = computeFunctionValue(x, absError, nMax);
                double stdFunctionValue = 1 / std::sqrt(1 + x);
                std::cout << x << "\t" << computedValue << "\t" << stdFunctionValue << "\n";
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << "\n";
            }
        }

    return 0;
}