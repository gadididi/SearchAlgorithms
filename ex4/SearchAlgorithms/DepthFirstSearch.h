//
// Created by gadi on 10/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_

#include "Searcher.h"
#include <string>

template<class Problem, class Solution,class T>
class DepthFirstSearch : public Searcher<Problem, Solution> {
 public:
  Solution search(Searchable<Problem> searchable) {
    Solution sol = dfs(searchable.GetInitialState(),searchable.GetGoalState());
  }
  Solution dfs(State<T>start , State<T> end){

  }
};

#endif //EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
