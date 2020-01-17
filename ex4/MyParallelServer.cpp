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
  for (int i = 0; i < NUMBER_OF_CLIENTS; i++) {
    while (!shouldStop()) {
      int iResult;
      int client_socket = 0;
      struct timeval tv;
      fd_set rfds;
      FD_ZERO(&rfds);
      FD_SET(server_fd, &rfds);

      tv.tv_sec = 120.0;
      tv.tv_usec = 0;
      int addrlen = sizeof(address);
      iResult = select(server_fd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
      if (iResult > 0) {
        client_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
      } else {
        cout << "Time out.Close the server." << endl;
        stop();
        return;
      }
      if (client_socket == -1) {
        std::cerr << "can't accept client" << std::endl;
        continue;
      }
      ClientHandler *new_handle = c->clone();
      vecOfThreads.emplace_back(std::thread(&MyParallelServer::start, this, client_socket, new_handle, server_fd));
    }
  }
  close(server_fd);
}
void MyParallelServer::stop() {
  // Iterate over the thread vector
  for (std::thread &th : vecOfThreads) {
// If thread Object is Join-able then Join that thread.
    if (th.joinable())
      th.join();
  }
}

void MyParallelServer::start(int client_socket, ClientHandler *c, int socket_Server) {
  c->handleClient(client_socket, socket_Server);

}
bool MyParallelServer::shouldStop() {
  return should_stop;
}
