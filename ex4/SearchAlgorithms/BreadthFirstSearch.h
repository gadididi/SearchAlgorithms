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


/**
 * BreadthFirstSearch: the BFS algorithm, more info here: https://en.wikipedia.org/wiki/Breadth-first_search
 * @tparam Solution a generic parameter that represents the solution.
 * @tparam T a generic parameter that represents the object in the searchable (point, vertex, etc')
 */

template<class Solution, class T>
class BreadthFirstSearch : public Searcher<Solution, T> {
 private:
  Solution solution_;
  bool is_path_exist = false;
  int evaluatedNodes = 0;
  std::set<State<T> *> visited;
  std::queue<State<T> *> bfs_queue;

 public:
  /**
 * Search: init a search on the searchable. From the start to the end.
 * @param searchable a searchable (like graph or matrix)
 * @return returns the solution to the search problem
 */
  Solution search(Searchable<T> *searchable) override {
    //init the cost and father of the start vertex.
    searchable->GetInitialState()->setCameFrom(nullptr);
    searchable->GetInitialState()->setCost(0);

    //Activate the algorithm
    bfs(searchable->GetInitialState(), searchable->GetGoalState(), searchable);
    if (is_path_exist) {
      std::cout << "finish the number of Nodes Evaluated: ";
      std::cout << getNumberOfNodesEvaluated() << std::endl;
      solution_ = searchable->Dynamic_programming_recovery();
    }
    return this->solution_;
  }

  /**
 * BFS searching algorithm: Breadth first search algorithm, proceed to the breadth and find the shortest path
 * between the source and the target.
 * @param start: starting vertex
 * @param end: target vertex
 * @param searchable a searchable object
 */
  void bfs(State<T> *start, State<T> *end, Searchable<T> *searchable) {

    //init the source vertex
    visited.insert(start);
    bfs_queue.push(start);

    /*
    * While there're some vertex that yet to be scanned, extract the front one.
    */
    while (!bfs_queue.empty()) {
      State<T> *vertex = bfs_queue.front();
      bfs_queue.pop();
      evaluatedNodes++;

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
          adj->setCost(1);
          bfs_queue.push(adj);
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
};
#endif //EX4_SEARCHALGORITHMS_BREADTHFIRSTSEARCH_H_
