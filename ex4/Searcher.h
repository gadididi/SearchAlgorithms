//
// Created by ori294 on 1/9/20.
//

#ifndef EX4__SEARCHER_H_
#define EX4__SEARCHER_H_

template<class Problem, class Solution>
class Searcher {
 public:
  virtual Solution search(Problem p) = 0;
};


#endif //EX4__SEARCHER_H_
