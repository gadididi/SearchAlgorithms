//
// Created by gadi on 10/01/2020.
//

#ifndef EX4__MYCLIENTHANDLER_H_
#define EX4__MYCLIENTHANDLER_H_

#include <SearchAlgorithms/DepthFirstSearch.h>
#include <SearchAlgorithms/BestFirstSearch.h>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Matrix.h"

template<class Problem, class Solution>
class MyClientHandler : public ClientHandler {
 private:
  Solver<Problem, Solution> *solver;
  CacheManager<Problem, Solution> *cache_manager_;

 public:
  MyClientHandler() {
    //fill
    this->cache_manager_ = new FileCacheManager<Problem, Solution>(100);
  }
  ~MyClientHandler() {
    delete this->cache_manager_;
  }
  void handleClient(int client_socket, int server_socket) override {
    list<std::string> matrix;
    char buffer[1024] = {0};
    string msg;
    int size = 0;
    read(client_socket, buffer, 1024);
    while (std::strcmp(buffer, "end") != 0) {
      size++;
      msg = buffer;
      matrix.emplace_back(msg);
      std::fill(std::begin(buffer), std::end(buffer), 0);
      read(client_socket, buffer, 1024);
    }
    Matrix *my_matrix = MatrixBuilder::buildMatrix(matrix, size - 2);
    /**
     * check if exist in cache ,return solution else ,solve the problem
     * need to check if exist the problem
     */
    /*if (this->cache_manager_->isExist(msg)) {
        cout << "from cache" << endl;
        cout << this->cache_manager_->get(msg) << endl;
      } else {
        cout << "from solver" << endl;
        Solution sol = this->solver->solve(msg);
        cout << sol << endl;
        this->cache_manager_->insert(msg, sol);
      }*/

    Searcher<string, Point> *dd = new AStarSearch<string, Point>();
    std::string sms = dd->search(my_matrix);
    const char *to_send;
    to_send = sms.c_str();
    send(client_socket, to_send, strlen(to_send), 0);
    cout << sms << endl;
    cout << "close socket-finish" << endl;
    close(client_socket);

  }

};
#endif //EX4__MYCLIENTHANDLER_H_
