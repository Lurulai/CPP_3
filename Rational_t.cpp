//
// Created by hello on 20/03/2022.
//

#include "Rational_t.h"

Rational_t::Rational_t():
// Default constructor.
        numerator {1},
        denominator {1}
{ }

Rational_t::Rational_t (int numerator):
        denominator {1}
{
    // Constructor that takes numerator and sets denominator as default.
    this->numerator = numerator;
}

Rational_t::Rational_t (int numerator, int denominator) {
    auto common_divisor = gcd(numerator, denominator);

    // Constructor that takes two values and simplified.
    this->numerator = (numerator / common_divisor);
    this->denominator = (denominator / common_divisor);
    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

Rational_t::Rational_t (std::string rational_in_string) {
    auto num {0};
    auto den {0};
    std::string buffer;

    for (auto i{0}; i < rational_in_string.length(); ++ i) {
        // Usage of ASCII table values, not magic numbers.
        if (rational_in_string[i] >= 47 && rational_in_string[i] <= 57 || rational_in_string[i] == 45) {
            if (rational_in_string[i] == 47) {
                num = std::stoi(buffer);
                buffer = "";
            } else {
                buffer.push_back(rational_in_string[i]);
            }
        }
    }
    den = std::stoi(buffer);
    auto common_divisor = gcd(num, den);

    this->numerator = (num / common_divisor);
    this->denominator = (den / common_divisor);
    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

int Rational_t::num() const {
    return this->numerator;
}

int Rational_t::den() const {
    return this->denominator;
}

void Rational_t::set_num (int num) {
    auto common_divisor = gcd (num, this->denominator);
    this->numerator = num / common_divisor;
    this->denominator /= common_divisor;
}

void Rational_t::set_den (int den) {
    auto common_divisor = gcd (this->numerator, den);
    this->numerator /= common_divisor;
    this->denominator = (den / common_divisor);
    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

std::string Rational_t::to_str() const {
    std::string return_str;
    if (this->is_inf()) {
        if (this->numerator > 0) {
            return "+inf";
        }
        return "-inf";
    } else if (this->is_nan()) {
        return "NaN";
    }
    return_str.append(std::to_string(this->numerator));
    return_str.append("/");
    return_str.append(std::to_string(this->denominator));
    return return_str;
}

double Rational_t::to_double() const {
    if (!this->is_inf() && !this->is_nan()) {
        auto return_double = (double) this->numerator / (double) this->denominator;
        return return_double;
    } else if (this->is_nan()) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    return std::numeric_limits<double>::infinity();
}

bool Rational_t::is_positive() const {
    return (this->numerator > 0 && this->denominator > 0) || (this->numerator < 0 && this->denominator < 0);
}

bool Rational_t::is_negative() const {
    return (this->numerator < 0 && this->denominator > 0) || (this->denominator < 0 && this->numerator > 0);
}

bool Rational_t::is_inf() const {
    return this->denominator == 0 && this->numerator != 0;
}

bool Rational_t::is_nan() const {
    return (this->numerator == 0) && (this->denominator == 0);
}

int Rational_t::gcd (int num_1, int num_2) {
    if (num_1 == 0 && num_2 == 0) {
        return 1; // Will allow NaN to happen since 0*1 is still 0.
    }
    if (num_2 == 0) {
        return num_1;
    }
    return gcd (num_2, num_1 % num_2);
}
