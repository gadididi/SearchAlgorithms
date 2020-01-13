//
// Created by gadi on 10/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_

#include "Searcher.h"
#include <string>
#include <vector>
#include <set>

template<class Solution, class T>
class DepthFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool find_path = false;
  int evaluatedNodes = 0;
  std::set<State<T> *> visited;

 public:
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    searchable->GetInitialState()->setCost(1);
    dfs(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (find_path) {
      solution_ = searchable->Dynamic_programming_recovery();
      cout << this->getNumberOfNodesEvaluated() << endl;
    }
    return this->solution_;
  }

  void dfs(State<T> *start, State<T> *end, Searchable<T> *searchable) {
    visited.insert(start);
    if (start->Equals(end)) {
      cout << "finish the cost ";
      cout << "finish the number of Nodes Evaluated: ";
      cout << start->getCost() << endl;
      find_path = true;
      return;
    }
    std::list<State<T> *> adj = searchable->GetAllPossibleStates(start);
    for (State<T> *state:adj) {
      if (!visited.count(state)) {
        visited.insert(state);
        state->setCameFrom(start);
        state->setCost(start->getCost() + 1);
        evaluatedNodes++;
        if (!find_path) {
          dfs(state, end, searchable);
        }
      }
    }
  }

  int getNumberOfNodesEvaluated() override {
    return evaluatedNodes;
  }
};

#endif //EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
