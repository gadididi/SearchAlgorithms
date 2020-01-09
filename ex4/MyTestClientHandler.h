//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
#define SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

template<class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
 public:
  MyTestClientHandler() {
    this->solver = new StringReverser();
    this->cache_manager_ = new FileCacheManager<Solution>(100);
  }
  ~MyTestClientHandler() {
    delete this->cache_manager_;
    delete this->solver;
  }
  void handleClient(int client_socket, int server_socket) override {
    char buffer[1024] = {0};
    string msg;
    read(client_socket, buffer, 1024);
    while (std::strcmp(buffer, "end") != 0) {
      msg = buffer;
      if (this->cache_manager_->isExist(msg)) {
        cout << this->cache_manager_->get(msg) << endl;
      } else {
        Solution sol = this->solver->solve(msg);
        cout << sol << endl;
        //this->cache_manager_->insert(msg, sol);
      }
      std::fill(std::begin(buffer), std::end(buffer), 0);
      read(client_socket, buffer, 1024);
    }
    close(client_socket);
  };

 private:
  Solver<Problem, Solution> *solver;
  CacheManager<Solution> *cache_manager_;
};

#endif //SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
