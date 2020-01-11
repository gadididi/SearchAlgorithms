//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__SEARCHABLE_H_
#define EX4__SEARCHABLE_H_

#include <list>
#include "State.h"

template<class T>
class Searchable {
 public:
  virtual State<T> GetInitialState() = 0;
  virtual State<T> GetGoalState() = 0;
  virtual std::list<State<T>> GetAllPossibleStates() = 0;
};

#endif //EX4__SEARCHABLE_H_
