//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__MATRIX_H_
#define EX4__MATRIX_H_
#include <stdio.h>
#include <fstream>
#include "Searchable.h"

class Matrix : public Searchable<std::string> {
 public:
  Matrix(std::fstream matrix_as_file) {

  }
};

#endif //EX4__MATRIX_H_
