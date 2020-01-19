//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
#define SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
/**
 * handler that support string reverse protocol.
 * @tparam Problem generic problem
 * @tparam Solution return geneic solution
 */
template<class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
 private:
  Solver<Problem, Solution> *solver;
  CacheManager<Problem, Solution> *cache_manager_;

 public:
  /**
   * CTOR
   */
  MyTestClientHandler() {
    this->solver = new StringReverser();
    this->cache_manager_ = new FileCacheManager<Problem, Solution>(100);
  }
  /**
   * another CTOR
   * @param s Solver
   * @param cache CacheManager =  ame for whole the program
   */
  MyTestClientHandler(Solver<Problem, Solution> *s,
                      CacheManager<Problem, Solution> *cache) : solver(s), cache_manager_(cache) {}
  /**
   * DTOR
   */
  ~MyTestClientHandler() {
    delete this->cache_manager_;
    delete this->solver;
  }
  /**
   * handle client by reading the buffer , every time is string we need to reverse
   * until the client send "end" ,that we know he want to finnish te connection.
   * @param client_socket
   * @param server_socket
   */
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
        sendTo += "\n";
        to_send = sendTo.c_str();
        send(client_socket, to_send, strlen(to_send), 0);
        cout << to_send << endl;
      } else {
        cout << "from solver" << endl;
        std::string sendTo = this->solver->solve(msg);
        sendTo += "\n";
        to_send = sendTo.c_str();
        send(client_socket, to_send, strlen(to_send), 0);
        cout << to_send << endl;
        this->cache_manager_->insert(msg, to_send);
      }
      std::fill(std::begin(buffer), std::end(buffer), 0);
      read(client_socket, buffer, 1024);
    }
    cout << "close socket-finish" << endl;
    close(client_socket);
  }
  /**
   * create clone for this instance of object (for parallel server)
   * @return new MyTestClientHandler
   */
  MyTestClientHandler *clone() override {
    Solver<std::string, Solution> *s = this->solver;
    MyTestClientHandler *handler = new MyTestClientHandler<std::string, std::string>(s, this->cache_manager_);
    return handler;
  }
};

#endif //SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
