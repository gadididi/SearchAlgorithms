//
// Created by gadi on 11/01/2020.
//

#ifndef EX4__POINT_H_
#define EX4__POINT_H_

class Point {
 private:
  double row;
  double col;

 public:
  Point(double _x, double _y) {
    this->row = _x;
    this->col = _y;
  };
  double getRow() {
    return this->row;
  }
  double getCol() {
    return this->col;
  }
};

#endif //EX4__POINT_H_
