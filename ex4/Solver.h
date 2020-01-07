//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__SOLVER_H_
#define SEARCHALGORITHMS__SOLVER_H_

template<class Problem, class Solution>
class Solver {
 public:
  virtual Solution solve(Problem p) = 0;
};

#endif //SEARCHALGORITHMS__SOLVER_H_
