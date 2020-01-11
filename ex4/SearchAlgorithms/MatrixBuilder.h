//
// Created by ori294 on 1/10/20.
//

#ifndef EX4_SEARCHALGORITHMS_MATRIXBUILDER_H_
#define EX4_SEARCHALGORITHMS_MATRIXBUILDER_H_
#include <SearchAlgorithms/Matrix.h>
#include <string.h>

class MatrixBuilder {

 public:
    static Matrix<std::pair<int,int>>* buildMatrix(std::list<std::string> lineList, int size) {
      int sourceFlag = 0;
      int rowNum = 0, colNum = 0;
      int sourceX = 0, sourceY = 0, targetX = 0, targetY = 0;
      std::vector<std::vector<double>> matrix;

      auto iter = lineList.begin();
      while (iter != lineList.end()) {

        char char_array[iter->length()];
        strcpy(char_array, iter->c_str());

        if (rowNum < size) {
          std::vector<double> tempVector;
          char* token = strtok(char_array, ",");
          while (token != nullptr) {
            tempVector.emplace_back(std::stod(token));
            token = strtok(nullptr, ",");
          }
          matrix.emplace_back(tempVector);
        } else {
          if (sourceFlag) {
            char* token = strtok(char_array, ",");
            targetX = atoi(token);
            token = strtok(nullptr, ",");
            targetY = atoi(token);

          } else {
            sourceFlag = 1;
            char* token = strtok(char_array, ",");
            sourceX = atoi(token);
            token = strtok(nullptr, ",");
            sourceY = atoi(token);
          }
        }
        rowNum++;
        iter++;
      }

      auto newMatrix = new Matrix<std::pair<int,int>>();

      auto vectorIter = matrix.begin();
      while (vectorIter != matrix.end()) {
        newMatrix->addRow(*vectorIter);
        vectorIter++;
      }

      newMatrix->setSource(sourceX,sourceY);
      newMatrix->setTarget(targetX, targetY);

      return newMatrix;
  }
};

#endif //EX4_SEARCHALGORITHMS_MATRIXBUILDER_H_
