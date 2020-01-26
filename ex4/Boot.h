//
// Created by gadi on 19/01/2020.
//

#ifndef EX4__BOOT_H_
#define EX4__BOOT_H_
#include <stdio.h>
#include <string>
#include <iostream>
#include "Matrix.h"
#include "MatrixBuilder.h"
#include "BreadthFirstSearch.h"
#include "AStarSearch.h"
#include "Solver.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "SolverToSearcherAdapter.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"

namespace boot {
class Main {
 public:
  int main1(int argc, char **argv) {

    server_side::Server *myserver = new MyParallelServer();
    ClientHandler *handler = new MyClientHandler<std::string, std::string>();
    if (argc >= 2) {
      myserver->open(strtod(argv[1], nullptr), handler);
    } else {
      myserver->open(5600, handler);
    }
    return 0;
  }

};
}
#endif //EX4__BOOT_H_
