/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name: Victoria Stephany Huisman Sigcha
 * Student Number: 491775@student.saxion.nl
 * Assignment: W3, Rational Calculator
 *      Basically a calculator with many functions and three different classes. Rational_t contains how a rational
 * should behave, rational_calc handles how they calculate each other, and rational_processor handles the processing
 * of files. This is just a very chunky program..!
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "rational_processor.h"

int main() {
//    while (true) {
//        std::cout << "Welcome! Would you like to ...\n"
//                     "[1] Enter an expression to solve?\n"
//                     "[2] Read expressions from a file?\n"
//                     "[3] Exit." << std::endl;
//        std::string temp_choice = {};
//        getline (std::cin, temp_choice);
//        auto choice = std::stoi(temp_choice);
//
//        std::string situational_string = {}; // situational_string: handles either file_name or calc expression.
//        Rational_t result;
//        switch (choice) {
//            case 1:
//                std::cout << "Enter an expression below!" << std::endl;
//                std::getline (std::cin, situational_string);
//                result = rational_calc::calculate(situational_string);
//                std::cout << "Result is: " << result.to_str() << "\n" << std::endl;
//                break;
//            case 2:
//                std::cout << "What's the file name?" << std::endl;
//                std::getline (std::cin, situational_string);
//                if (rational_processor::read_from_file(situational_string)) {
//                    std::cout << "Your file will be printed out with an .out extension once you exit.\n" << std::endl;
//                } else {
//                    std::cout << "Try again, file name not found." << std::endl;
//                }
//                break;
//            case 3: return 0; // Exit without needing to use strange functions.
//        }
//    }

    Rational_t r;
    std::cout << r.to_str() << std::endl;
}
