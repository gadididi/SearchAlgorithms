//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__MYSERIALSERVER_H_
#define SEARCHALGORITHMS__MYSERIALSERVER_H_
#include "Server.h"

class MySerialServer : public server_side::Server {
  void open(int port, ClientHandler c);
  void stop();
};
#endif //SEARCHALGORITHMS__MYSERIALSERVER_H_
