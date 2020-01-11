//
// Created by ori294 on 1/10/20.
//

#ifndef EX4_SEARCHALGORITHMS_MATRIXBUILDER_H_
#define EX4_SEARCHALGORITHMS_MATRIXBUILDER_H_
#include <SearchAlgorithms/Matrix.h>
#include <string.h>

class MatrixBuilder {

 public:
  static Matrix *buildMatrix(std::list<std::string> lineList, int size) {
    int sourceFlag = 0;
    int rowNum = 0, colNum = 0;
    double sourceX = 0, sourceY = 0, targetX = 0, targetY = 0;
    std::vector<std::vector<double>> matrix;

    auto iter = lineList.begin();
    while (iter != lineList.end()) {

      char char_array[iter->length()];
      strcpy(char_array, iter->c_str());

      if (rowNum < size) {
        std::vector<double> tempVector;
        char *token = strtok(char_array, ",");
        while (token != nullptr) {
          tempVector.emplace_back(std::stod(token));
          token = strtok(nullptr, ",");
        }
        matrix.emplace_back(tempVector);
      } else {
        if (sourceFlag) {
          char *token = strtok(char_array, ",");
          targetX = atoi(token);
          token = strtok(nullptr, ",");
          targetY = atoi(token);

        } else {
          sourceFlag = 1;
          char *token = strtok(char_array, ",");
          sourceX = atoi(token);
          token = strtok(nullptr, ",");
          sourceY = atoi(token);
        }
      }
      rowNum++;
      iter++;
    }
    /**
     * create Matrix and add by loop row by row , send the cost vector ,and the num of row
     * to method of matrix class to create the matrix of state<point>
     */
    Matrix *newMatrix = new Matrix(size);
    auto vectorIter = matrix.begin();
    int numberOfRow = 0;
    while (vectorIter != matrix.end()) {
      newMatrix->addRow(*vectorIter, numberOfRow);
      vectorIter++;
      numberOfRow++;
    }
    /**
     * set the trg and src state point for the matrix by sending 2 state src , trg and 2 cost
     */
    State<Point> *stateSrc = new State<Point>(new Point(sourceX, sourceY));
    State<Point> *stateTrg = new State<Point>(new Point(targetX, targetY));
    newMatrix->setSource(stateSrc, matrix[sourceX][sourceY]);
    newMatrix->setTarget(stateTrg, matrix[targetX][targetY]);
    return newMatrix;
  }
};

#endif //EX4_SEARCHALGORITHMS_MATRIXBUILDER_H_
