//
// Created by gadi on 11/01/2020.
//

#ifndef EX4__POINT_H_
#define EX4__POINT_H_

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
/**
 * use for the variable the state <T> handle ,for the matrix problem
 */
class Point {
 private:
  double row;
  double col;

 public:
  /**
   * CTOR
   * @param _x
   * @param _y
   */
  Point(double _x, double _y) {
    this->row = _x;
    this->col = _y;
  };
  /**
   * getter row presentation of this point
   * @return x
   */
  double getRow() {
    return this->row;
  }
  /**
   * getter col presentation of this point
   * @return y
   */
  double getCol() {
    return this->col;
  }
  /**
   * get point and find out where is the point for this point up left ect..
   * @param p
   * @return int indicator
   */
  int compere_2_p(Point *p) {
    if (row > p->getRow()) {
      return UP;
    } else if (row < p->getRow()) {
      return DOWN;
    } else if (col < p->getCol()) {
      return RIGHT;
    } else {
      return LEFT;
    }
  }
};

#endif //EX4__POINT_H_
