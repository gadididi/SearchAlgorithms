//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_

template<class T>
class State {

 private:
  T state;
  double cost;
  State<T> cameFrom;

 public:
  State(T state) {
    this->state = state;
  }

  bool Equals(State<T> toCompare) {
    return this->state.Equals(toCompare.state);
  }
};

#endif //EX4__STATE_H_
