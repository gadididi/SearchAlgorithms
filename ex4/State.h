//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_
#define WHITE 0
#define GREY 1
#define BLACK 2

template<class T>
class State {

 private:
  T *state; // the state represented by a string
  double cost; // cost to reach this state (set by a setter)
  State<T> *cameFrom; // the state we came from to this state (setter)
  int status;
 public:
  State(T *s) {
    this->state = s;
    cameFrom = nullptr;
    status = 0;
  }

  void setCost(double c) {
    this->cost = c;
  }
  void setCameFrom(State<T> *state1) {
    this->cameFrom = state1;
    this->status = WHITE;
  }

  double getCost() {
    return this->cost;
  }

  T *getState() {
    return this->state;
  }

  bool Equals(State<T> *toCompare) {
    return (this == toCompare);
  }

  void set_Visit_In_Progress() {
    this->status = GREY;
  }
  void set_Visited() {
    this->status = BLACK;
  }

  void set_init_status() {
    this->status = WHITE;
  }
  int get_status() {
    return this->status;
  }
  State<T> *Get_cameFrom() {
    return this->cameFrom;
  }
};

#endif //EX4__STATE_H_
