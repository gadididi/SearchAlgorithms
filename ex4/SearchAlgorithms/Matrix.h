//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__MATRIX_H_
#define EX4__MATRIX_H_
#include <stdio.h>
#include <fstream>
#include <array>
#include <vector>
#include "Searchable.h"

template<class T>
class Matrix : public Searchable<T> {
 int sourceX = 0, sourceY = 0;
 int targetX = 0, targetY = 0;

 public:
  std::vector<std::vector<double>> matrix;
  Matrix(int srcX, int srcY, int tarX, int tarY) {
    this->sourceX = srcX;
    this->sourceY = srcY;
    this->targetX = tarX;
    this->targetY = tarY;
  }

  void addRow(std::vector<double> row) {
    matrix.emplace_back(row);
  }

  State<T> getState (int i, int j) {
    return matrix[i][j];
  }

  State<T> GetInitialState() override {
    return matrix[this->sourceX][this->sourceY];
  };
  State<T> GetGoalState() override {
    return matrix[this->targetX][this->targetY];
  };
  std::list<State<T>> GetAllPossibleStates() override {

  };
};

#endif //EX4__MATRIX_H_
