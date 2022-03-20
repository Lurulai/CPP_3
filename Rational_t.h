//
// Created by hello on 20/03/2022.
//

#ifndef CPP3_RATIONAL_T_H
#define CPP3_RATIONAL_T_H

#include <iostream>
#include <string>
#include <cmath>

class Rational_t {
public:
    int numerator{};
    int denominator{};
    std::string fraction;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Creation of a simplified rational object with a given numerator and denominator.
     * @param   numerator           The numerator to be given.
     * @param   denominator         The denominator to be given.
     */
    explicit Rational_t (int numerator, int denominator);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Creation of a simplified rational object with a given numerator and default denominator.
     * @param   numerator           The numerator to be given.
     */
    explicit Rational_t (int numerator);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Creation of a simplified rational object with a given string.
     * @param   rational_in_string  A string with a numerator/denominator.
     */
    explicit Rational_t (std::string rational_in_string);

    // Default constructor.
    Rational_t();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Getter for a read-only numerator.
     * @return  The numerator of the current fraction.
     */
    [[nodiscard]] int num() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Getter for a read-only denominator.
     * @return  The denominator of the current fraction.
     */
    [[nodiscard]] int den() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Converting a simplified rational to a string.
     * @return  A rational object made into a string.
     */
    [[nodiscard]] std::string to_str() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Converting a simplified rational to a double.
     * @return A rational object made into a double.
     */
    [[nodiscard]] double to_double() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Will return true if the rational object is positive.
     * @return  True when rational object is positive.
     */
    [[nodiscard]] bool is_positive() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Will return true if the rational object is negative.
     * @return  True when rational object is negative.
     */
    [[nodiscard]] bool is_negative() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Will return true if the rational object is an infinite value.
     * @return  True when rational object is infinite, determined +inf or -inf by the numerator.
     */
    [[nodiscard]] bool is_inf() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Will return true if the rational object is not a number.
     * @return  True when rational object is not a number.
     */
    [[nodiscard]] bool is_nan() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Greatest common divisor function used to find the gcd between the numerator and denominator.
     * Used as the factor for simplifying fractions.
     * @param   num_1               The first number to compare.
     * @param   num_2               The second number to compare
     * @return  The gcd of num_1 & num_2.
     */
    [[nodiscard]] static int gcd (int num_1, int num_2);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Setting the numerator to a chosen number. The new rational object will be simplified.
     * @param   num                 The number to set the numerator to.
     */
    void set_num (int num);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Setting the denominator to a chosen number. The new rational object will be simplified.
     * @param   den                 The number to set the denominator to.
     */
    void set_den (int den);
};


#endif //CPP3_RATIONAL_T_H
