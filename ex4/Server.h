//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__SERVER_H_
#define SEARCHALGORITHMS__SERVER_H_
#include "ClientHandler.h"
#include <string>
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"

namespace server_side {
class Server {
 public:
  virtual void open(int port, ClientHandler *c) = 0;
  virtual void stop() = 0;
};
}

/*
namespace boot {
  int main(int argc, std::string* argv[]) {

    Solver<std::string, std::string>* solver = new StringReverser();
    CacheManager<std::string>* cache_manager = new FileCacheManager<std::string>(10);
    //MySerialServer(atoi(argv[0]), ClientHandler);
  }
}
 */

#endif //SEARCHALGORITHMS__SERVER_H_
