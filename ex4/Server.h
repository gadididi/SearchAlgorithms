//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__SERVER_H_
#define SEARCHALGORITHMS__SERVER_H_
#include "ClientHandler.h"
namespace server_side {
class Server {
  virtual void open(int port, ClientHandler c) = 0;
  virtual void stop() = 0;
};
}

#endif //SEARCHALGORITHMS__SERVER_H_
