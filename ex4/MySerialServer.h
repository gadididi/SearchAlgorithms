//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__MYSERIALSERVER_H_
#define SEARCHALGORITHMS__MYSERIALSERVER_H_
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <cstring>

class MySerialServer : public server_side::Server {
 public:
  void open(int port, ClientHandler *c) override;
  void stop() override;
  static bool shouldStop();
  static void start(ClientHandler *c, int socket_Server, sockaddr_in address);
};
#endif //SEARCHALGORITHMS__MYSERIALSERVER_H_
