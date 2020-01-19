//
// Created by gadi on 07/01/2020.
//


#include "MySerialServer.h"

/**
 * server that hold one user .there is timer about 120 sec ,if no one connect in that time the server is closed.
 * @param port
 * @param c client handler that solve problem for specific protocol
 */
void MySerialServer::open(int port, ClientHandler *c) {

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

  std::thread listen_tread(&MySerialServer::start, this, c, server_fd, address);
  listen_tread.join();
  close(server_fd);
}

/**
 * not needed in this program.
 */
void MySerialServer::stop() {

}

/**
 * accept client and send him to ch for solve his problem
 * @param c ch
 * @param socket_Server
 * @param address address of the socket
 */
void MySerialServer::start(ClientHandler *c, int socket_Server, sockaddr_in address) {
  while (!shouldStop()) {
    int iResult;
    int client_socket = 0;
    struct timeval tv;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(socket_Server, &rfds);

    tv.tv_sec = 120.0;
    tv.tv_usec = 0;
    int addrlen = sizeof(address);
    iResult = select(socket_Server + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
    if (iResult > 0) {
      client_socket = accept(socket_Server, (struct sockaddr *) &address, (socklen_t *) &addrlen);
    } else {
      cout << "Time out.Close the server." << endl;
      return;
    }
    if (client_socket == -1) {
      std::cerr << "can't accept client" << std::endl;
      return;
    }
    c->handleClient(client_socket, socket_Server);
  }
}
/**
 * if this server should stop ,alaways stop. the server stop by rerurn in condition ,if the time
 * @return
 */
bool MySerialServer::shouldStop() {
  return false;
}
