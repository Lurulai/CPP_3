//
// Created by hello on 20/03/2022.
//

#include "rational_processor.h"

bool rational_processor::read_from_file(std::string file_name) {
    std::ifstream input {file_name};
    if (input.is_open()) {
        std::ofstream out_file(file_name.substr(0, file_name.find('.')) + ".out");
        for (std::string line; getline(input, line); ) {
            if (!line.empty()) {
                Rational_t result = rational_calc::calculate(line);
                out_file << result.to_str() << std::endl;
            }
        }
        return true;
    }
    return false;
}
