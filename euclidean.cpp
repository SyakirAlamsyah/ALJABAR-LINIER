#include <iostream>

using namespace std;

double sqrt(double value) {
    double guess = value / 2.0;
    const double epsilon = 1e-10;

    while (true) {
        double next_guess = (guess + value / guess) / 2.0;
        if (abs(next_guess - guess) < epsilon) {
            break;
        }
        guess = next_guess;
    }

    return guess;
}

double abso(double value) {
    return (value < 0) ? -value : value;
}

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;


}
int main() {

}