//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_

template<class T>
class State {

 private:
  double cost = 0;
  double row = 0;
  double col = 0;
  double distance = 0;
  State<T>* cameFrom;

 public:
  State(int cost, int row, int col) {
    this->cost = cost;
    this->row = row;
    this->col = col;
  }

  void setCameFrom(State<T>* state1) {
    this->cameFrom = state1;
  }

  double getCost() {
    return this->cost;
  };

  double getRow() {
    return this->row;
  };

  double getCol() {
    return this->col;
  };

  bool Equals(State<T> toCompare) {
    return (this->getCol() == toCompare.getCol() && this->getRow() == toCompare.getRow());
  }
};

#endif //EX4__STATE_H_
