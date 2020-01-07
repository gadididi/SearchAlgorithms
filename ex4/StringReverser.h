//
// Created by ori294 on 1/7/20.
//

#ifndef EX4__STRINGREVERSER_H_
#define EX4__STRINGREVERSER_H_

#include <string>
#include "Solver.h"

/**
 * StringReverser class: reversing strings
 */
 class StringReverser : public Solver<std::string, std::string> {
  public:
  std::string solve(std::string str) override ;
};

#endif //EX4__STRINGREVERSER_H_
