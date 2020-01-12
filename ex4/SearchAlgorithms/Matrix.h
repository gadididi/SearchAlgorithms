//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__MATRIX_H_
#define EX4__MATRIX_H_
#include <stdio.h>
#include <fstream>
#include <array>
#include <vector>
#include <Point.h>
#include "Searchable.h"

class Matrix : public Searchable<Point> {
 private:

  State<Point> *targetState;
  State<Point> *sourceState;
  std::vector<std::vector<State<Point> *>> matrix;
  int size;

 public:
  Matrix(int s) { // CTOR
    this->size = s;
    targetState = nullptr;
    sourceState = nullptr;
  }

  ~Matrix() {  // DTOR
    delete targetState;
    delete sourceState;
  }
  void setSource(double sourceX, double sourceY) {
    this->sourceState = matrix[sourceX][sourceY];
  }

  void setTarget(double targetX, double targetY) {
    this->targetState = matrix[targetX][targetY];
  }

  void addRow(std::vector<double> row, int numberOfRow) {
    std::vector<State<Point> *> tempVector;
    auto vectorIter = row.begin();
    int numberOfCol = 0;
    while (vectorIter != row.end()) {
      State<Point> *state = new State<Point>(new Point(numberOfRow, numberOfCol));
      state->setCost(*vectorIter);
      tempVector.emplace_back(state);
      numberOfCol++;
      vectorIter++;
    }
    matrix.emplace_back(tempVector);
  }

  State<Point> *GetInitialState() override {
    return this->sourceState;
  }

  State<Point> *GetGoalState() override {
    return this->targetState;
  }

  std::list<State<Point> *> GetAllPossibleStates(State<Point> *state) override {
    std::list<State<Point> *> position;

    //check down side
    if (state->getState()->getRow() < this->size - 1) {
      position.emplace_back(matrix[state->getState()->getRow() + 1][state->getState()->getCol()]);
    }
    //check right side
    if (state->getState()->getCol() < this->size - 1) {
      position.emplace_back(matrix[state->getState()->getRow()][state->getState()->getCol() + 1]);
    }
    //check up side
    if (state->getState()->getRow() > 0) {
      position.emplace_back(matrix[state->getState()->getRow() - 1][state->getState()->getCol()]);
    }
    //check left side
    if (state->getState()->getCol() > 0) {
      position.emplace_back(matrix[state->getState()->getRow()][state->getState()->getCol() - 1]);
    }
    return position;
  }
};

#endif //EX4__MATRIX_H_