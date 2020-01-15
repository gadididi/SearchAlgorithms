//
// Created by gadi on 15/01/2020.
//

#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *c) {
  int server_fd;
  struct sockaddr_in address;
  int opt = 1;
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Forcefully attaching socket to the port 8080
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                 &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  // Forcefully attaching socket to the port 8080
  if (bind(server_fd, (struct sockaddr *) &address,
           sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
  std::vector<std::thread> vecOfThreads;
  for (int i = 0; i < 9; i++) {
    auto *listenToOne = new MySerialServer();
    //ClientHandler *new_copy_handle = c->clone();
    vecOfThreads.emplace_back(std::thread(&MyParallelServer::start, this, listenToOne, c, server_fd, address));
  }
  // Iterate over the thread vector
  for (std::thread &th : vecOfThreads) {
// If thread Object is Joinable then Join that thread.
    if (th.joinable())
      th.join();
  }
  close(server_fd);
}
void MyParallelServer::stop() {

}

void MyParallelServer::start(MySerialServer *listenToOne, ClientHandler *c, int socket_Server, sockaddr_in address) {
  listenToOne->start(c, socket_Server, address);
}
