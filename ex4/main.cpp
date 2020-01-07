//
// Created by ori294 on 1/6/20.
//
#include <stdio.h>
#include <string>
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

int main() {
  std::string str = "helloWorld";
  Solver<std::string, std::string>* solver = new StringReverser();

  str = solver->solve(str);
  server_side::Server *myserver = new MySerialServer();
  ClientHandler * client_handler = new MyTestClientHandler<std::string, std::string>();
  myserver->open(1234,client_handler);
  std::cout << str << std::endl;

}
