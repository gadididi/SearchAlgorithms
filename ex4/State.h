//
// Created by ori294 on 1/10/20.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_
/**
 * state is the situation that the problem/game now
 * handle generic represtation for this state and cost
 * moreover there is camefrom pointer from the last state.
 * @tparam T
 */
template<class T>
class State {

 private:
  T *state; // the state represented by a string
  double cost; // cost to reach this state (set by a setter)
  double trailCost;
  State<T> *cameFrom; // the state we came from to this state (setter)

/**
 * CTOR
 */
 public:
  State(T *s) {
    this->state = s;
    cameFrom = nullptr;
  }
/**
 * setter for cost for this specific state
 * @param c
 */
  void setCost(double c) {
    this->cost = c;
  }
  /**
   * set came from
   */
  void setCameFrom(State<T> *state1) {
    this->cameFrom = state1;
  }
  /**
   * set trail cost from the begin until this state
   * @param s value cost
   */
  void setTrail(double s) {
    this->trailCost = s;
  }
  /**
   * getter trail cost
   * @return trail cost
   */
  double getTrail() {
    return this->trailCost;
  }
  /**
   * getter this state cost
   * @return state cost
   */
  double getCost() {
    return this->cost;
  }
/**
 * getter the presentation of this state
 * @return T
 */
  T *getState() {
    return this->state;
  }
/**
 * check if 2 state are equals
 * @param toCompare
 * @return
 */
  bool Equals(State<T> *toCompare) {
    return (this == toCompare);
  }
/**
 * getter for the came form state
 * @return came from state
 */
  State<T> *Get_cameFrom() {
    return this->cameFrom;
  }
};

#endif //EX4__STATE_H_
