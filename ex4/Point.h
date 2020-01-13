//
// Created by gadi on 11/01/2020.
//

#ifndef EX4__POINT_H_
#define EX4__POINT_H_

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

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
  int compere_2_p(Point *p) {
    if (row == p->getRow()) {

    } else if () {

    } else if () {

    } else{

    }
  }
};

#endif //EX4__POINT_H_
