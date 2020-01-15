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

class MyParallelServer : public server_side::Server {

 public:
  void open(int port, ClientHandler *c) override;
  void stop() override;
  void start(MySerialServer *listenToOne,ClientHandler *c, int socket_Server, sockaddr_in address);

};

#endif //EX4__MYPARALLELSERVER_H_
