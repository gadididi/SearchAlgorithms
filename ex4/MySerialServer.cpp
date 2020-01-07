//
// Created by gadi on 07/01/2020.
//


#include "MySerialServer.h"

/**
 *
 * @param port
 * @param c
 */
void MySerialServer::open(int port, ClientHandler *c) {

  int socket_Server = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_Server == -1) {

    std::cerr << "can't open server" << std::endl;
  }
  //create server socket
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socket_Server, (struct sockaddr *) &address, sizeof(address)) == -1) {
    std::cerr << "can't bind server" << std::endl;
  }
  if (listen(socket_Server, 1) == -1) {
    std::cerr << "can't listen server" << std::endl;
  }
  std::thread listen_tread(start, c, socket_Server, address);

}

/**
 *
 */
void MySerialServer::stop() {

}

/**
 *
 * @param c
 * @param socket_Server
 * @param address
 */
void MySerialServer::start(ClientHandler *c, int socket_Server, sockaddr_in address) {
  while (shouldStop()) {
    int client_socket = accept(socket_Server, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1) {
      std::cerr << "can't accept client" << std::endl;
    }
    char buffer[1024] = {0};
    int data;
    do {
      std::fill(std::begin(buffer), std::end(buffer), 0);
      data = read(client_socket, buffer, 1024);

      //c->handleClient();
      if (data == -1) {}
    } while (std::strcmp(buffer, "end") != 0);
  }
}
/**
 *
 * @return
 */
bool MySerialServer::shouldStop() {
  return false;
}
