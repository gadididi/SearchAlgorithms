//
// Created by gadi on 13/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_BESTFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_BESTFIRSTSEARCH_H_
#include <set>
#include "Searcher.h"

template<class Solution, class T>
class BestFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool find_path = false;
  int evaluatedNodes = 0;
  std::set<State<T> *> visited;

 public:
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    searchable->GetInitialState()->setCost(0);
    //dfs(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (find_path) {
      solution_ = searchable->Dynamic_programming_recovery();
      //cout << this->getNumberOfNodesEvaluated() << endl;
    }
    return this->solution_;
  }
};

#endif //EX4_SEARCHALGORITHMS_BESTFIRSTSEARCH_H_
