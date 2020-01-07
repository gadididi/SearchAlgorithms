//
// Created by ori294 on 1/6/20.
//
#include <stdio.h>
#include <string>
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"

int main() {
  std::string str = "helloWorld";
  Solver<std::string, std::string>* solver = new StringReverser();

  str = solver->solve(str);

  std::cout << str << std::endl;

}
