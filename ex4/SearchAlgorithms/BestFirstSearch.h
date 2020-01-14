//
// Created by gadi on 13/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_BESTFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_BESTFIRSTSEARCH_H_
#include <set>

#include "Searcher.h"
#include "PriorityQueueState.h"
#include <queue>
#include <iostream>

template<class Solution, class T>
class BestFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool find_path = false;
  int evaluatedNodes = 0;
  std::set<State<T> *> visited;
  priority_queueState<T> *priority_queue = new priority_queueState<T>();

 public:
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    priority_queue->Push(searchable->GetInitialState());
    Bfs(searchable);
    if (find_path) {
      solution_ = searchable->Dynamic_programming_recovery();
    }
    return this->solution_;
  }
  void Bfs(Searchable<T> *searchable) {
    while (!priority_queue->IsEmpty()) {
      State<T> *state = priority_queue->Top();
      priority_queue->Pop();
      evaluatedNodes++;
      visited.insert(state);
      if (state->Equals(searchable->GetGoalState())) {
        std::cout << "finish the number of Nodes Evaluated: ";
        std::cout << getNumberOfNodesEvaluated() << std::endl;
        find_path = true;
        return;
      }
      std::list<State<T> *> adj = searchable->GetAllPossibleStates(state);
      for (State<T> *s : adj) {
        if (!visited.count(s) && !priority_queue->findState(s) && s->getCost() >= 0) {
          s->setCameFrom(state);
          priority_queue->Push(s);
        } else if (!visited.count(s) && s->getCost() >= 0) {
          if (s->getCost() > state->getCost()) {
            priority_queue->remove(s);
            s->setCost(state->getCost());
            s->setCameFrom(state);
            priority_queue->Push(s);
          }
        }
      }
    }
  }

  int getNumberOfNodesEvaluated() override {
    return evaluatedNodes;
  }
};

#endif //EX4_SEARCHALGORITHMS_BESTFIRSTSEARCH_H_
