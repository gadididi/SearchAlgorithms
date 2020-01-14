//
// Created by ori294 on 1/6/20.
//
#include <stdio.h>
#include <string>
#include <iostream>
#include <SearchAlgorithms/Matrix.h>
#include <SearchAlgorithms/MatrixBuilder.h>
#include <SearchAlgorithms/BreadthFirstSearch.h>
#include "Solver.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"

int main() {

  /*std::string str = "helloWorld";
  Solver<std::string, std::string> *solver = new StringReverser();

  str = solver->solve(str);*/


  server_side::Server *myserver = new MySerialServer();
  //ClientHandler *client_handler = new MyTestClientHandler<std::string, std::string>();
  ClientHandler *handler = new MyClientHandler<std::string, std::string>();
  myserver->open(1234, handler);
  //myserver->open(1234, client_handler);



  /*std::list<std::string> strlist;
  strlist.emplace_back("1,0,-1,1,3,4");
  strlist.emplace_back("-1,0,-1,5,4,3");
  strlist.emplace_back("1,1,-1,12,2,3");
  strlist.emplace_back("1,0,-1,1,3,4");
  strlist.emplace_back("1,0,1,5,4,3");
  strlist.emplace_back("1,1,1,12,2,3");
  strlist.emplace_back("0,0");
  strlist.emplace_back("2,5");
  Searchable<Point>* matrix = MatrixBuilder::buildMatrix(strlist, 6);

  auto bfs = new BreadthFirstSearch<std::string, Point>();
  std::string result = bfs->search(matrix);*/

  //cout << result << endl;

}
