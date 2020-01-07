//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
#define SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
 public:
  void handleclient(std::ifstream input_stream, std::ofstream output_stream);
 private:
  Solver<std::string, std::string> solver;
  CacheManager cache_manager_;
};

#endif //SEARCHALGORITHMS__MYTESTCLIENTHANDLER_H_
