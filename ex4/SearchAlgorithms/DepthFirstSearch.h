//
// Created by gadi on 10/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_

#include "Searcher.h"
#include <string>
#include <stack>
#include <vector>

#define WHITE 0
#define GREY 1
#define BLACK 2

template<class Solution, class T>
class DepthFirstSearch : public Searcher<Solution, T> {
 private:
  std::stack<State<T>> my_stack;
  std::vector<std::vector<std::pair<State<T>, int>>> visited;

 public:
  Solution search(Searchable<T> *searchable) override {
    Solution sol = dfs(searchable->GetInitialState(), searchable->GetGoalState());
    return sol;
  }
  Solution dfs(State<T> start, State<T> end) {
    start.setCameFrom(nullptr);
    //start.
    my_stack.push(start);
  }

  int getNumberOfNodesEvaluated() override {
    return 0;
  }
};

#endif //EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
