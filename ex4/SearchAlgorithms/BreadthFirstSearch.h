//
// Created by ori294 on 1/10/20.
//

#ifndef EX4_SEARCHALGORITHMS_BREADTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_BREADTHFIRSTSEARCH_H_

#include "Searcher.h"
#include <queue>
#include <string>
#include <vector>
#include <set>

template<class Solution, class T>
class BreadthFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool is_path_exist = false;
  int evaluatedNodes = 0;
  std::set<State<T> *> visited;
  std::queue<State<T> *> bfs_queue;

 public:
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    searchable->GetInitialState()->setCost(0);
    bfs(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (is_path_exist) {
      solution_ = searchable->Dynamic_programming_recovery();
    }
    return this->solution_;
  }

  void bfs(State<T> *start, State<T> *end, Searchable<T> *searchable) {

    visited.insert(start);
    bfs_queue.push(start);
    while (!bfs_queue.empty()) {
      State<T> *vertex = bfs_queue.front();
      bfs_queue.pop();

      if (vertex->Equals(end)) {
        is_path_exist = true;
        return;
      }

      std::list<State<T> *> adjacent = searchable->GetAllPossibleStates(vertex);
      for (State<T> *adj:adjacent) {
        if (adj->getCost() == -1) { //-1 for infinity, IDK how they gonna represent it
          visited.insert(adj);
        }
        if (!visited.count(adj)) {
          visited.insert(adj);
          adj->setCameFrom(vertex);
          adj->setCost(vertex->getCost() + 1);
          bfs_queue.push(adj);
          evaluatedNodes++;
        }
      }
    }
  }

  int getNumberOfNodesEvaluated() override {
    return evaluatedNodes;
  }
};
#endif //EX4_SEARCHALGORITHMS_BREADTHFIRSTSEARCH_H_
