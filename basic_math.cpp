#include "basic_math.hpp"

// Adds two numbers
double add(double a, double b) { return a + b; }

// Subtracts b from a
double subtract(double a, double b) { return a - b; }

// Multiplies two numbers
double multiply(double a, double b) { return a * b; }

// Divides a by b, throws if b == 0
double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    return a / b;
}

// Raises base to the exponent power
double power(double base, int exponent) { return std::pow(base, exponent); }

// Calculates factorial of n (n!)
unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

// Calculates the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a >= 0 ? a : -a; // Ensure GCD is positive
}

// Calculates least common multiple (LCM)
int lcm(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    return std::abs(a / gcd(a, b) * b);
}

// Calculates the square root
double square_root(double x) {
    if (x < 0) {
        throw std::invalid_argument("Square root of negative number!");
    }
    return std::sqrt(x);
}

// Returns the absolute value
double absolute(double x) { return x < 0 ? -x : x; }

// Returns the nth Fibonacci number (simple iterative)
unsigned long long fibonacci(unsigned int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    unsigned long long prev = 0, curr = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        unsigned long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}
