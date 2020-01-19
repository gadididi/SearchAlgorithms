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


#endif //SEARCHALGORITHMS__SERVER_H_
