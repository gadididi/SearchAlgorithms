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
    searchable->GetInitialState()->setTrail(searchable->GetInitialState()->getCost());
    //searchable->GetInitialState()->setCost(0);
    dfs(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (find_path) {
      solution_ = searchable->Dynamic_programming_recovery();
    }
    return this->solution_;
  }

  void dfs(State<T> *start, State<T> *end, Searchable<T> *searchable) {
    visited.insert(start);
    if (start->Equals(end)) {
      cout << "finish the number of Nodes Evaluated: ";
      cout << this->getNumberOfNodesEvaluated() << endl;
      find_path = true;
      return;
    }
    std::list<State<T> *> adj = searchable->GetAllPossibleStates(start);
    for (State<T> *state:adj) {
      if (!visited.count(state) && state->getCost() >= 0) {
        visited.insert(state);
        state->setCameFrom(start);
        state->setTrail(start->getTrail() + state->getCost());
        evaluatedNodes++;
        dfs(state, end, searchable);
      }
    }
  }

  /**
 * getNumberOfNodesEvaluated: returns the number of nodes that were evaluated during the process.
 * @return int, the number of evaluated vertexes.
 */
  int getNumberOfNodesEvaluated() override {
    return evaluatedNodes;
  }

  /**
   *
   * @return
   */
  Searcher<Solution, T> *clone() override {
    Searcher<Solution, T> *d_f_s_new = new DepthFirstSearch();
    return d_f_s_new;
  }
};

#endif //EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
