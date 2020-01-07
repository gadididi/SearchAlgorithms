//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__CLIENTHANDLER_H_
#define SEARCHALGORITHMS__CLIENTHANDLER_H_
#include <iostream>
#include <fstream>

class ClientHandler {
  virtual void handleClient(std::ifstream input_stream, std::ofstream output_stream) = 0;
};

#endif //SEARCHALGORITHMS__CLIENTHANDLER_H_
