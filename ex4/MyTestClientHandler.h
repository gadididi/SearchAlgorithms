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
  void handleClient(std::ifstream input_stream, std::ofstream output_stream) override;
 private:
  Solver<Problem, Solution> solver;
  CacheManager<Solution> *cache_manager_;
};


#endif //SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
