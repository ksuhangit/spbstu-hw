#include <iostream> 
#include <cmath> 
#include <stdexcept>

double calculateValue(double x, double absError, int nMax) {
    if (x <= -1 || x >= 1) {
        throw std::runtime_error("Error! x is out of range (-1, 1)");
    }


    double result = 1;
    double term = 1;
    double factorial = 1;

    for (int n = 1; n <= nMax; n++) {
        term *= ((2 * n) - 1) * (2 * n);
        factorial *= n;

        double nextTerm = term / factorial * pow(-x, n);
        if (abs(nextTerm) < absError) {
            return result;
        }

        result += nextTerm;
    }

    throw std::runtime_error("Error! Absolute error not achieved within nMax");
}

int main() {
    double intervalStart, intervalEnd, step, absError; int nMax;


    std::cout << "Enter interval start, interval end, step, absolute error and max number of terms: ";
    std::cin >> intervalStart >> intervalEnd >> step >> absError >> nMax;

    try {
        for (double x = intervalStart; x <= intervalEnd; x += step) {
            double customValue = calculateValue(x, absError, nMax);
            double standardValue = 1 / std::sqrt(1 + x);

            std::cout << "x = " << x << ", Custom Value = " << customValue << ", Standard Value = " << standardValue << std::endl;
        }

    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}