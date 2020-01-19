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
  Path<State<Point>> *path;

 public:
  Matrix(int s) { // CTOR
    this->size = s;
    targetState = nullptr;
    sourceState = nullptr;
    path = nullptr;
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
/**
 * getter the start state
 * @return start state
 */
  State<Point> *GetInitialState() override {
    return this->sourceState;
  }
/**
 * getter goal state
 * @return goal state
 */
  State<Point> *GetGoalState() override {
    return this->targetState;
  }

/**
 * find all the  adjoins state for this state we get by arg
 * @param state we want to find for it
 * @return list of state of all the adjoins state for this state we get by arg
 */
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
/**
 * create string of the path by recovery step by step
 * @param flag -- 0 if there is no path return NOT EXIST, flag ==1 else.
 * @return string - the path
 */
  std::string Dynamic_programming_recovery(int flag) override {
    if (!flag) {
      std::string not_found = "NOT EXIST ANY SOLUTION";
      return not_found;
    }
    path = new Path<State<Point>>();
    State<Point> *iterator1 = this->targetState;
    State<Point> *iterator2 = this->targetState;
    while (iterator1 != this->sourceState) {
      path->add_to_path(*iterator2);
      iterator1 = iterator2;
      iterator2 = iterator2->Get_cameFrom();
    }
    std::string msg = Convert_to_string_solution();
    //return path;
    return msg;
  }
  /**
   * path is object member that handle stack. we recovery the path by loop and pop every step
   * find out the direction and and print the accumulate string
   * @return the string of the path
   */
  std::string Convert_to_string_solution() {
    std::string solu = "{";
    State<Point> *to_convert1;
    //print up down left right
    to_convert1 = path->get_element();
    to_convert1 = path->get_element();
    double sum = 0;
    int pos;
    std::string _sms_;
    while (!this->path->finish_path()) {
      pos = to_convert1->getState()->compere_2_p(path->top_element()->getState());
      sum = to_convert1->getTrail();
      _sms_ = " (" + std::to_string(sum) + "),";
      solu = solu + switch_case_print(pos) + _sms_;
      to_convert1 = path->get_element();
    }
    sum = to_convert1->getTrail();
    _sms_ = " (" + std::to_string(sum) + "),";
    solu = solu + switch_case_print(pos) + _sms_;
    solu += "}";
    std::cout << "finish the cost: ";
    std::cout << sum << std::endl;
    return solu;
  }
  std::string switch_case_print(int pos) {
    std::string ToAdd;
    switch (pos) {
      case 1: {
        ToAdd = "Up";
        break;
      }
      case 2: {
        ToAdd = "Down";
        break;
      }
      case 3: {
        ToAdd = "Left";
        break;
      }
      default: {
        ToAdd = "Right";
      }
    }
    return ToAdd;
  }
};

#endif //EX4__MATRIX_H_
