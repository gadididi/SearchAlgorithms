//
// Created by ori294 on 1/9/20.
//

#ifndef EX4__SEARCHER_H_
#define EX4__SEARCHER_H_

#include "Searchable.h"

template<class Problem, class Solution>
class Searcher {
 public:
  virtual Solution search(Searchable<Problem>* searchable) = 0;
  virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //EX4__SEARCHER_H_
