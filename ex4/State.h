//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_

template<class T>
class State {

 private:
  T *state; // the state represented by a string
  double cost; // cost to reach this state (set by a setter)
  State<T> *cameFrom; // the state we came from to this state (setter)

 public:
  State(T *s) {
    this->state = s;
  }

  void setCost(double c) {
    this->cost = c;
  }
  void setCameFrom(State<T> *state1) {
    this->cameFrom = state1;
  }

  double getCost() {
    return this->cost;
  }

  T *getState() {
    return this->state;
  }

  bool Equals(State<T> *toCompare) {
    return (this->state == toCompare);
  }
};

#endif //EX4__STATE_H_
