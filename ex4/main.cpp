//
// Created by ori294 on 1/6/20.
//
#include <stdio.h>
#include <string>
#include <iostream>
#include <SearchAlgorithms/Matrix.h>
#include <SearchAlgorithms/MatrixBuilder.h>
#include <SearchAlgorithms/BreadthFirstSearch.h>
#include <SearchAlgorithms/AStarSearch.h>
#include "Solver.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "SolverToSearcherAdapter.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"

int main() {

  server_side::Server *myserver = new MyParallelServer();
  ClientHandler *client_handler = new MyTestClientHandler<std::string, std::string>();
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

  Searchable<Point> *matrix = MatrixBuilder::buildMatrix(strlist, 6);
  auto star = new AStarSearch<std::string, Point>();

  auto adapter = new SolverToSearcherAdapter<std::string, Searchable<Point>*, Point>(star);
  std::string result;// = adapter->solve(matrix);

  auto cache_manager =  new FileCacheManager<std::string, std::string>(5);
  //cache_manager->insert("1,0,1,5,4,3", result);

  if (cache_manager->isExist("1,0,1,5,4,3")) {
    cout << "exists" << endl;
    result = cache_manager->get("1,0,1,5,4,3");
    cout << result << endl;
  }
*/
}

