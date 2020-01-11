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

  State<T>* targetState;
  State<T>* sourceState;

 public:
  std::vector<std::vector<double>> matrix;

  void setSource(int i, int j) {
    sourceState = new State<T>(matrix[i][j], i, j);
  }

  void setTarget(int i, int j) {
    targetState = new State<T>(matrix[i][j], i, j);
  }

  void addRow(std::vector<double> row) {
    matrix.emplace_back(row);
  }

  State<T> getStateByIndex(int i, int j) {
    auto state = new State<T>(matrix[i][j], i, j);
    return *state;
  }

  State<T> GetInitialState() override {
    return *this->sourceState;
  };
  State<T> GetGoalState() override {
    return *this->targetState;
  };
  std::list<State<T>> GetAllPossibleStates() override {

  };

  double getSize() {
    return this->matrix.begin()->size();
  };
};

#endif //EX4__MATRIX_H_
