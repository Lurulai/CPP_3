cmake_minimum_required(VERSION 3.22)
project(cpp3)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp3 main.cpp Rational_t.cpp Rational_t.h rational_calc.cpp rational_calc.h rational_processor.cpp rational_processor.h)
