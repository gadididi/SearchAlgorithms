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

/**
 * BestFirstSearch algorithm. use priority queue and make relax for the path. this algorithm find the shortest path
 * this algorithm is really generic ,can solve any shortest path problem
 * @tparam Solution return solution generic ,depend the kind of solution we need
 * @tparam T the represent of all state , e.g. point
 */
template<class Solution, class T>
class BestFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool find_path = false;
  int evaluatedNodes = 0;
  std::set<State<T> *> visited;
  priority_queueState<T> *priority_queue = new priority_queueState<T>();

 public:
  /**
   * this method initialize the start of the algo and senf to bfs methos to find the shortest path
   * @param searchable the problem we need to solve
   * @return Solution-- generic ,depend the value of returning depend on user.
   */
  Solution search(Searchable<T> *searchable) override {
    searchable->GetInitialState()->setCameFrom(nullptr);
    //searchable->GetInitialState()->setCost(0);
    searchable->GetInitialState()->setTrail(searchable->GetInitialState()->getCost());
    priority_queue->Push(searchable->GetInitialState());
    Bfs(searchable);
    if (find_path) {
      solution_ = searchable->Dynamic_programming_recovery(1);
    }
    return this->solution_;
  }
  /**
   * this method make the search algorithm by priority queue.in addition there are set visited, state that we
   * mark as visited. this is iterative algorithm that run until we find the goal state.
   * @param searchable searchable the problem we need to solve
   */
  void Bfs(Searchable<T> *searchable) {
    while (!priority_queue->IsEmpty()) {
      State<T> *state = priority_queue->Top();
      priority_queue->Pop();
      evaluatedNodes++;
      visited.insert(state);
      //stop condition
      if (state->Equals(searchable->GetGoalState())) {
        std::cout << "finish the number of Nodes Evaluated: ";
        std::cout << getNumberOfNodesEvaluated() << std::endl;
        find_path = true;
        return;
      }
      std::list<State<T> *> adj = searchable->GetAllPossibleStates(state);
      for (State<T> *s : adj) {
        double trailCost = s->getCost() + state->getTrail();
        if (!visited.count(s) && !priority_queue->findState(s) && s->getCost() >= 0) {
          s->setCameFrom(state);
          s->setTrail(trailCost);
          priority_queue->Push(s);
        } else if (!visited.count(s) && s->getCost() >= 0) {
          if (trailCost < s->getTrail()) {
            priority_queue->remove(s);
            s->setTrail(trailCost);
            s->setCameFrom(state);
            priority_queue->Push(s);
          }
        }
      }
    }
  }

  /**
 * clone to this object
 * @return new best first search obj
 */
  Searcher<Solution, T> *clone() override {
    Searcher<Solution, T> *best_f_s_new = new BestFirstSearch();
    return best_f_s_new;
  }

  /**
   * get the number of nodes the algo "touch" them
   * @return get the number of nodes the algo "touch" them
   */
  int getNumberOfNodesEvaluated() override {
    return evaluatedNodes;
  }
};

#endif //EX4_SEARCHALGORITHMS_BESTFIRSTSEARCH_H_
