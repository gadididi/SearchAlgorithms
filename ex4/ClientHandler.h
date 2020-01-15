//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__CLIENTHANDLER_H_
#define SEARCHALGORITHMS__CLIENTHANDLER_H_
#include <iostream>
#include <fstream>

class ClientHandler {
 public:
  virtual void handleClient(int client_socket, int server_socket) = 0;
  virtual ClientHandler *clone() = 0;
};

#endif //SEARCHALGORITHMS__CLIENTHANDLER_H_
