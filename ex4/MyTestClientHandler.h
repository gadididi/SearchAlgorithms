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
  void handleClient(std::ifstream *input_stream, std::ofstream *output_stream) override {
    string line;
    while (getline(*input_stream, line)) {
      cout << line << '\n';
    }
    input_stream->close();
    if (this->cache_manager_->isExist(line)) {
      *output_stream << this->cache_manager_->get(line);
    } else {
      Solution sol = this->solver->solve(line);
      *output_stream << sol;
      this->cache_manager_->insert(line, sol);
      output_stream->close();
    }
  };

 private:
  Solver<Problem, Solution> *solver;
  CacheManager<Solution> *cache_manager_;
};

#endif //SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
