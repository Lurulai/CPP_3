//
// Created by hello on 20/03/2022.
//

#ifndef CPP3_RATIONAL_PROCESSOR_H
#define CPP3_RATIONAL_PROCESSOR_H

#include <numeric>
#include <cmath>
#include <fstream>
#include <string>

#include "Rational_t.h"
#include "rational_calc.h"

class rational_processor {
public:
    /*
     * Handles the reading of a file and creating an output file with all solved expressions.
     * @param   file_name           The name of the file to be opened and read from.
     *
     */
    static bool read_from_file (std::string file_name);
};


#endif //CPP3_RATIONAL_PROCESSOR_H
