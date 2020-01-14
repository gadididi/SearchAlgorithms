//
// Created by ori294 on 1/13/20.
//

#ifndef EX4_SEARCHALGORITHMS_ASTARSEARCH_H_
#define EX4_SEARCHALGORITHMS_ASTARSEARCH_H_

#include "Searcher.h"
#include "PriorityQueueState.h"
#include <queue>
#include <string>
#include <vector>
#include <set>

/**
 * AStarSearch: the A* algorithm, more info here: https://en.wikipedia.org/wiki/A*_search_algorithm
 * @tparam Solution a generic parameter that represents the solution.
 * @tparam T a generic parameter that represents the object in the searchable (point, vertex, etc')
 */
template<class Solution, class T>
class AStarSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool is_path_exist = false;
  int evaluatedNodes = 0;
  double goalX;
  double goalY;

  priority_queueState<T> *priority_queue = new priority_queueState<T>();
  std::set<State<T> *> open_list;
  std::set<State<T> *> closed_list;

 public:
  /**
   * Search: init a search on the searchable. From the start to the end.
   * @param searchable a searchable (like graph or matrix)
   * @return returns the solution to the search problem
   */
  Solution search(Searchable<T> *searchable) override {
    //init the cost and father of the start vertex.
    searchable->GetInitialState()->setCameFrom(nullptr);
    searchable->GetInitialState()->setTrail(searchable->GetInitialState()->getCost());
    goalX = searchable->GetInitialState()->getState()->getRow();
    goalY = searchable->GetInitialState()->getState()->getCol();

    //Activate the algorithm
    AStar(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (is_path_exist) {
      std::cout << "finish the number of Nodes Evaluated: ";
      std::cout << getNumberOfNodesEvaluated() << std::endl;
      solution_ = searchable->Dynamic_programming_recovery();
    }
    return this->solution_;
  }

  /**
   * AStar searching algorithm: This algorithm works much like Dijkstra's algorithm,
   * but with an Heuristic function that improves the running time of the algorithm.
   * Please find the Heuristic function down below.
   * @param start: starting vertex
   * @param end: target vertex
   * @param searchable a searchable object
   */
  void AStar(State<T> *start, State<T> *end, Searchable<T> *searchable) {
    priority_queue->Push(start);//init from the start vertex

    /*
     * While there're some vertex that yet to be scanned, extract the minimum weighted one.
     */
    while (!priority_queue->IsEmpty()) {
      State<T> *nextVertex = priority_queue->Top();
      priority_queue->Pop();
      evaluatedNodes++;

      //Move the vertex to the closed list.
      closed_list.insert(nextVertex);

      /*
       * Get the possible next vertexes from the searchable.
       */
      std::list<State<T> *> adjacent = searchable->GetAllPossibleStates(nextVertex);
      for (State<T> *adj:adjacent) {
        //if we found the target, we are done.
        if (adj->Equals(end)) {
          //setup cost and father to the target vertex.
          adj->setTrail(nextVertex->getTrail() + adj->getCost());
          adj->setCameFrom(nextVertex);
          is_path_exist = true;
          return;
          //if we didn't find the target, and the vertex is not blocked and yet to be visited.
        } else if (!closed_list.count(adj) && adj->getCost() != -1) { //-1 for infinity
          if (priority_queue->findState(adj)) {
            if (adj->getTrail() > nextVertex->getTrail() + adj->getCost()) {
              adj->setCameFrom(nextVertex);
              adj->setTrail(nextVertex->getTrail() + adj->getCost());
            }
          } else {
            adj->setCameFrom(nextVertex);
            adj->setTrail(nextVertex->getTrail() + adj->getCost());
            priority_queue->Push(adj);
          }
        }
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
   * heuristicFunction: In A* algorithm, we utilize the knowledge of the general direction we're supposed go.
   * By calculating the diff (in absolute value) between the X's and Y's, we take the general direction into
   * consideration, upon choosing the next vertex to visit in.
   * @param current - current vertex
   * @return a double value.
   */
  double heuristicFunction(State<T> *current) {
    return 0;
    //double x = current->getState()->getRow();
    //double y = current->getState()->getCol();
    //return abs(x - goalX) + abs(y - goalY);
  }
};

#endif //EX4_SEARCHALGORITHMS_ASTARSEARCH_H_
