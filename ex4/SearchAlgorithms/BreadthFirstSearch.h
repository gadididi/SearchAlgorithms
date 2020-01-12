//
// Created by ori294 on 1/10/20.
//

/*#ifndef EX4_SEARCHALGORITHMS_BREADTHFIRSTSEARCH_H_
#define EX4_SEARCHALGORITHMS_BREADTHFIRSTSEARCH_H_

#include <string>
#include <SearchAlgorithms/Searcher.h>
#include <vector>
#include <queue>
#include <iostream>

template<class T, class Solution>
class BreadthFirstSearch : Searcher<T, Solution> {

 private:
  Searchable<T>* searchable;
  double size;

 public:
  Solution search(Searchable<T>* toSearch) {
    this->searchable = toSearch;
    this->size = searchable->getSize();
    Solution sol = bfs(this->searchable->GetInitialState(),this->searchable->GetGoalState());
    return sol;
  }

  int getNumberOfNodesEvaluated() override {

  }


  Solution bfs(State<T>start , State<T> end){
    std::vector<std::vector<bool>> visited;
    std::vector<std::vector<double>> distances;

    std::vector<bool> tempVisited;
    std::vector<double> tempDistances;
    for (int i = 0; i < size; i++) {
      tempVisited.emplace_back(false);
      tempDistances.emplace_back(0);
    }
    for (int i = 0; i < size; i++) {
      visited.emplace_back(tempVisited);
      distances.emplace_back(tempDistances);
    }



    std::queue<State<T>> searchQueue;
    int sourceIndexX = 0, sourceIndexY = 0;
    int targetIndexX = 0, targetIndexY = 0;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        visited[i][j] = (searchable->getStateByIndex(i, j).getCost() == -1); //-1 for infinity distance (temp)
        if (start.getCol() == j && start.getRow() == i) {
          std::cout << "Found start index" << std::endl;
          sourceIndexX = i;
          sourceIndexY = j;
        }
      }
    }

    searchQueue.push(searchable->getStateByIndex(sourceIndexX, sourceIndexY));
    distances[start.getRow()][start.getCol()] = 0;
    visited[sourceIndexX][sourceIndexY] = true;

    while (!searchQueue.empty()) {
      State<T> vertex = searchQueue.front();
      searchQueue.pop();

      if (vertex.Equals(end)) {
        std::cout << "Target found" << std::endl;
        return Solution(distances[vertex.getRow()][vertex.getCol()]);
      }

      //scan upside
      if (vertex.getRow() > 0 && !visited[vertex.getRow()-1][vertex.getCol()]) {
        searchQueue.push(searchable->getStateByIndex(vertex.getRow() - 1, vertex.getCol()));

        visited[vertex.getRow() - 1][vertex.getCol()] = true;
        distances[vertex.getRow() - 1][vertex.getCol()] = distances[vertex.getRow()][vertex.getCol()] + 1;
      }

      //scan downside
      if (vertex.getRow() < size - 1 && !visited[vertex.getRow()+1][vertex.getCol()]) {
        searchQueue.push(searchable->getStateByIndex(vertex.getRow() + 1, vertex.getCol()));

        visited[vertex.getRow() + 1][vertex.getCol()] = true;
        distances[vertex.getRow() + 1][vertex.getCol()] = distances[vertex.getRow()][vertex.getCol()] + 1;
      }

      //scan rightside
      if (vertex.getCol() < size && !visited[vertex.getRow()][vertex.getCol() + 1]) {
        searchQueue.push(searchable->getStateByIndex(vertex.getRow(), vertex.getCol() + 1));

        visited[vertex.getRow()][vertex.getCol() + 1] = true;
        distances[vertex.getRow()][vertex.getCol() + 1] = distances[vertex.getRow()][vertex.getCol()] + 1;
      }

      //scan leftside
      if (vertex.getCol() > 0 && !visited[vertex.getRow()][vertex.getCol()-1]) {
        searchQueue.push(searchable->getStateByIndex(vertex.getRow(), vertex.getCol() - 1));

        visited[vertex.getRow()][vertex.getCol() - 1] = true;
        distances[vertex.getRow()][vertex.getCol() - 1] = distances[vertex.getRow()][vertex.getCol()] + 1;
      }

    }

  }

};

#endif //EX4_SEARCHALGORITHMS_BREADTHFIRSTSEARCH_H_
*/