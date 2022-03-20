//
// Created by hello on 20/03/2022.
//

#include "rational_calc.h"

Rational_t rational_calc::add (Rational_t one, Rational_t two) {
    Rational_t result;
    result.set_den(one.den() * two.den());
    result.set_num((one.num() * two.den()) + (two.num() * one.den()));

    auto common_divisor = Rational_t::gcd (result.num(), result.den());

    result.set_num((result.num() / common_divisor));
    result.set_den(result.den() / common_divisor);
    if (result.den() < 0) {
        result.set_num(result.num() * -1);
        result.set_den(result.den() * -1);
    }
    return result;
}

Rational_t rational_calc::subtract (Rational_t one, Rational_t two) {
    Rational_t result;
    result.set_den(one.den() * two.den());
    result.set_num((one.num() * two.den()) - (two.num() * one.den()));

    auto common_divisor = Rational_t::gcd (result.num(), result.den());

    result.set_num((result.num() / common_divisor));
    result.set_den(result.den() / common_divisor);
    if (result.den() < 0) {
        result.set_num(result.num() * -1);
        result.set_den(result.den() * -1);
    }
    return result;
}

Rational_t rational_calc::multiply (Rational_t one, Rational_t two) {
    Rational_t result;

    result.set_num(one.num() * two.num());
    result.set_den(one.den() * two.den());

    if (result.is_nan()) {
        result = Rational_t(0,0);
        return result;
    }

    auto common_divisor = Rational_t::gcd (result.num(), result.den());
    result.set_num(result.num() / common_divisor);
    result.set_den(result.den() / common_divisor);
    if (result.den() < 0) {
        result.set_num(result.num() * -1);
        result.set_den(result.den() * -1);
    }
    return result;
}

Rational_t rational_calc::divide (Rational_t one, Rational_t two) {
    auto temp {two.num()};
    two.set_num(two.den());
    two.set_den(temp);

    Rational_t result = multiply(one, two);
    return result;
}

Rational_t rational_calc::power(Rational_t one, int exponent) {
    Rational_t result;
    result.set_num(pow(one.num(), exponent));
    result.set_den(pow(one.den(), exponent));

    auto common_divisor = Rational_t::gcd (result.num(), result.den());
    result.set_num(result.num() / common_divisor);
    result.set_den(result.den() / common_divisor);
    if (result.den() < 0) {
        result.set_num(result.num() * -1);
        result.set_den(result.den() * -1);
    }

    return result;
}

Rational_t rational_calc::calculate(std::string alg_expression) {
    std::string rational_str[3] = {}; // 3 since there are 3 parts to an expression in a string.
    std::string buffer;
    auto count {0};

    for (auto i{0}; i < alg_expression.length(); ++ i) {
        if (alg_expression[i] == 32) { // ASCII decimal for space.
            rational_str[count] = buffer;
            buffer = "";
            count ++;
        } else {
            buffer.push_back(alg_expression[i]);
        }
    }
    rational_str[count] = buffer;

    Rational_t num_1 (rational_str[0]);
    Rational_t num_2;
    char op = rational_str[1].at(0);

    auto exponent {0};
    if (op == '^') {
        exponent = std::stoi(rational_str[2]);
    } else {
        num_2 = Rational_t(rational_str[2]);
    }
    Rational_t result;
    switch (op) {
        case '+': result = add (num_1, num_2); break;
        case '-': result = subtract (num_1, num_2); break;
        case '*': result = multiply (num_1, num_2); break;
        case '/': result = divide (num_1, num_2); break;
        case '^': result = power (num_1, exponent); break;
    }
    return result;
}
