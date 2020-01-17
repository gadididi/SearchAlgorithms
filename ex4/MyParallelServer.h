//
// Created by gadi on 15/01/2020.
//

#ifndef EX4__MYPARALLELSERVER_H_
#define EX4__MYPARALLELSERVER_H_
#include "Server.h"
#include "MySerialServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <cstring>
#include <vector>
#define NUMBER_OF_CLIENTS 20

class MyParallelServer : public server_side::Server {

  std::vector<std::thread> vecOfThreads;
  bool should_stop = false;
 public:
  void open(int port, ClientHandler *c) override;
  void stop() override;
  void start(int client_socket, ClientHandler *c, int socket_Server);
  bool shouldStop();
};

#endif //EX4__MYPARALLELSERVER_H_
