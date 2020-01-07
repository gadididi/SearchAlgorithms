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
  listen_tread.join();
  close(socket_Server);
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
  while (!shouldStop()) {
    int iResult, client_socket;
    struct timeval tv;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(socket_Server, &rfds);

    tv.tv_sec = 10.0;
    tv.tv_usec = 0;

    iResult = select(socket_Server + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
    if (iResult > 0) {
      client_socket = accept(socket_Server, (struct sockaddr *) &address, (socklen_t *) &address);
    } else {
      cout << "didnt connect" << endl;
      return;
    }
    if (client_socket == -1) {
      std::cerr << "can't accept client" << std::endl;
    }
    char buffer[1024] = {0};
    int data;
    do {
      std::fill(std::begin(buffer), std::end(buffer), 0);
      data = read(client_socket, buffer, 1024);
      std::ofstream ofs;
      ofs.open("problem.txt", std::ofstream::out | std::ofstream::trunc);
      ofs << buffer;
      std::ifstream ifs("solution.txt", std::ifstream::in);
      c->handleClient(&ifs, &ofs);
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
