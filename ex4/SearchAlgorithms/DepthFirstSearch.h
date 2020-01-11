//
// Created by gadi on 10/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_

#include "Searcher.h"
#include <string>

template<class Solution, class T>
class DepthFirstSearch : public Searcher<T, Solution> {
 public:
  Solution search(Searchable<T> searchable) {
    Solution sol = dfs(searchable.GetInitialState(), searchable.GetGoalState());
    return sol;
  }
  Solution dfs(State<T> start, State<T> end) {

  }
};

#endif //EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
