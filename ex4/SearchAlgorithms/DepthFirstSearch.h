//
// Created by gadi on 10/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_

#include "Searcher.h"
#include <string>
#include <vector>
#include <set>
/**
 * DepthFirstSearch algorithm use set of nodes that mark every node as visited node.
 * we implement by recursive method dfs
 * @tparam Solution return solution generic ,depend the kind of solution we need
 * @tparam T the represent of all state , e.g. point
 */
template<class Solution, class T>
class DepthFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool find_path = false;
  int evaluatedNodes = 0;
  std::set<State<T> *> visited;

 public:
  /**
   * initialize the start node as visited and go to dfs method after dfs finish go to Dynamic_programming_recovery
   * to recovery the path (maybe tha path does not exist).
   * @param searchable the problem we need to solve
   * @return Solution-- generic ,depend the value of returning depend on user.
   */
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    searchable->GetInitialState()->setTrail(searchable->GetInitialState()->getCost());
    //searchable->GetInitialState()->setCost(0);
    dfs(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (find_path) {
      cout << "finish the number of Nodes Evaluated: ";
      cout << this->getNumberOfNodesEvaluated() << endl;
      solution_ = searchable->Dynamic_programming_recovery(1);
    }
    return this->solution_;
  }
  /**
   * recursive method with stop condition.
   * dfs does not return the shortest path , this algo return if exist any path to the target node.
   * @param start the start state
   * @param end the goal state
   * @param searchable the problem we find tha path on it.
   */
  void dfs(State<T> *start, State<T> *end, Searchable<T> *searchable) {
    visited.insert(start);
    if (start->Equals(end)) {
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
   * create new dfs searcher end return it for parallel server
   * @return new dfs
   */
  Searcher<Solution, T> *clone() override {
    Searcher<Solution, T> *d_f_s_new = new DepthFirstSearch();
    return d_f_s_new;
  }
};

#endif //EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
