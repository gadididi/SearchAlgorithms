//
// Created by ori294 on 1/13/20.
//

#ifndef EX4_SEARCHALGORITHMS_ASTARSEARCH_H_
#define EX4_SEARCHALGORITHMS_ASTARSEARCH_H_

#include "Searcher.h"
#include <queue>
#include <string>
#include <vector>
#include <set>

template<class Solution, class T>
class AStarSearch : public Searcher<Solution, T>{
 private:
  Solution solution_;
  bool is_path_exist = false;
  int evaluatedNodes = 0;
  double goalX;
  double goalY;

  std::set<State<T>*> open_list;
  std::set<State<T>*> closed_list;

 public:
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    searchable->GetInitialState()->setCost(0);
    goalX = searchable->GetInitialState()->getState()->getRow();
    goalY = searchable->GetInitialState()->getState()->getCol();

    AStar(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (is_path_exist) {
      solution_ = searchable->Dynamic_programming_recovery();
    }
    return this->solution_;
  }

  void AStar(State<T> *start, State<T> *end, Searchable<T> *searchable) {
    open_list.push(start);

    while (!open_list.empty()) {
      auto list_iter = open_list.begin();
      double minimum = (*list_iter)->getCost() + heuristicFunction(*list_iter);
      State<T> *nextVertex = *list_iter;
      list_iter++;

      while (list_iter != open_list.end()) {
        if ((*list_iter)->getCost() + heuristicFunction(*list_iter) < minimum) {
          minimum = (*list_iter)->getCost() + heuristicFunction(*list_iter);
          nextVertex = *list_iter;
          open_list.clear();
          closed_list.emplace_back(nextVertex);
          list_iter++;
        }
      }

      if (nextVertex->Equals(end)) {
        is_path_exist = true;
        return;
      }

      std::list<State<T>*> adjacent = searchable->GetAllPossibleStates(nextVertex);
      for (State<T>* adj:adjacent) {
        if (adj->Equals(end)) {
          //setups like costs and fathers
          adj->setCost(nextVertex->getCost() + adj->getCost());
          adj->setCameFrom(nextVertex);
          is_path_exist = true;
          return;
        } else if(!closed_list.count(adj) || adj->getCost() != -1) { //-1 for infinity
          open_list.emplace(adj);
        }
      }
    }
  }

  int getNumberOfNodesEvaluated() override {
    return evaluatedNodes;
  }

  double heuristicFunction(State<T>* current) {
    double x = current->getState()->getRow();
    double y = current->getState()->getCol();
    return abs(x - goalX) + abs(y - goalY);
  }
};

#endif //EX4_SEARCHALGORITHMS_ASTARSEARCH_H_
