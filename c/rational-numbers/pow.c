
#include <math.h>
#include <stdio.h>

// integer power: x^a
double int_pow(double x, int a) {
    double result = 1.0;
    int exp = (a < 0) ? -a : a;

    for (int i = 0; i < exp; i++)
        result *= x;

    if (a < 0)
        return 1.0 / result;
    return result;
}

// nth root: q-th root of p
double nth_root(double p, int q) {
    return pow(p, 1.0 / q);
}

// rational power: x^(a/b)
double rational_pow(double x, int a, int b) {
    double powered = int_pow(x, a);
    return nth_root(powered, b);
}

int main() {
    printf("%f\n", rational_pow(27, 1, 3));   // cube root of 27 = 3
    printf("%f\n", rational_pow(16, 3, 4));   // 16^(3/4) = 8
}
