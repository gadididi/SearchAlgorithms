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
 private:
  Solver<Problem, Solution> *solver;
  CacheManager<Solution> *cache_manager_;

 public:
  MyTestClientHandler() {
    this->solver = new StringReverser();
    this->cache_manager_ = new FileCacheManager<std::string>(100);
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
      const char *to_send;
      if (this->cache_manager_->isExist(msg)) {
        cout << "from cache" << endl;
        std::string sendTo = this->cache_manager_->get(msg);
        to_send = sendTo.c_str();
        send(client_socket, to_send, strlen(to_send), 0);
        cout << to_send << endl;
      } else {
        cout << "from solver" << endl;
        std::string sendTo = this->solver->solve(msg);
        to_send = sendTo.c_str();
        send(client_socket, to_send, strlen(to_send), 0);
        cout << to_send << endl;
        this->cache_manager_->insert(msg, to_send);
      }
      std::fill(std::begin(buffer), std::end(buffer), 0);
      read(client_socket, buffer, 1024);
    }
    close(client_socket);
  }
};

#endif //SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
