//
// Created by gadi on 10/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_

#include "Searcher.h"
#include <string>
#include <vector>

#define WHITE 0
#define GREY 1
#define BLACK 2

template<class Solution, class T>
class DepthFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;

 public:
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    //init all white in CTOR of state
    searchable->GetInitialState()->set_Visit_In_Progress();
    searchable->GetInitialState()->setCost(1);
    dfs(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    return this->solution_;
  }

  void dfs(State<T> *start, State<T> *end, Searchable<T> *searchable) {
    start->set_Visit_In_Progress();
    if (start->Equals(end)) {
      cout << "finish the cost ";
      cout << start->getCost() << endl;
      //make the solution and return fix it!!!!
      return;
    }
    std::list<State<T> *> adj = searchable->GetAllPossibleStates(start);
    for (State<T> *state:adj) {
      if (state->get_status() == WHITE) {
        state->setCameFrom(start);
        state->setCost(start->getCost() + 1);
        dfs(state, end, searchable);
      }
    }
    start->set_Visited();
  }

  int getNumberOfNodesEvaluated() override {
    return 0;
  }
};

#endif //EX4_SEARCHALGORITHMS_DEPTHFIRSTSEARCH_H_
