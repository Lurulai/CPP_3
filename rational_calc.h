//
// Created by hello on 20/03/2022.
//

#ifndef CPP3_RATIONAL_CALC_H
#define CPP3_RATIONAL_CALC_H

#include <numeric>
#include <cmath>

#include "Rational_t.h"


class rational_calc {
public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Handles addition between two rational objects.
     * @param   one                 The primary rational object.
     * @param   two                 The rational object to add onto the first.
     * @return  The added rational objects.
     */
    [[nodiscard]] static Rational_t add (Rational_t one, Rational_t two);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Handles subtraction between two rational objects.
     * @param   one                 The primary rational object.
     * @param   two                 The rational object to subtract from the first.
     * @return  The difference between the two objects.
     */
    [[nodiscard]] static Rational_t subtract (Rational_t one, Rational_t two);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Handles the multiplication of two rational objects.
     * @param   one                 The primary rational object.
     * @param   two                 The rational object to multiply the first.
     * @return  The product of two rational objects.
     */
    [[nodiscard]] static Rational_t multiply (Rational_t one, Rational_t two);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Handles the division between two rational objects.
     * @param   one                 The primary rational object.
     * @param   two                 The rational object to divide the first.
     * @return  The quotient of the two rational objects.
     */
    [[nodiscard]] static Rational_t divide (Rational_t one, Rational_t two);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Handles the exponentiation of a rational object.
     * @param   one                 The rational object to become exponential.
     * @param   exponent            The exponent to use.
     * @return  The result of raising the rational object to the chosen power.
     */
    [[nodiscard]] static Rational_t power (Rational_t one, int exponent);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Handles an expression inputted with a string and solves accordingly.
     * Syntax: a/b (operator) c/d
     * @param   alg_expression      The expression to be solved within a string.
     */
    [[nodiscard]] static Rational_t calculate (std::string alg_expression);
};


#endif //CPP3_RATIONAL_CALC_H
