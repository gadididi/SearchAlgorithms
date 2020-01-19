//
// Created by gadi on 14/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_PRIORITYQUEUESTATE_H_
#define EX4_SEARCHALGORITHMS_PRIORITYQUEUESTATE_H_

#include <vector>
#include <functional>
#include <queue>
#include "State.h"

/**
 * comparator class ,compare by trail cost value.
 * @tparam T kind of state
 */
template<class T>
class CompByCost {
 public:
  bool operator()(State<T> *state, State<T> *comp) {
    bool b = (state->getTrail() > comp->getTrail());
    return b;
  }
};
/**
 * implementation of priority_queueState by all the regular options
 * @tparam T
 */
template<class T>
class priority_queueState {
 private:
  std::priority_queue<State<T> *, std::vector<State<T> *>, CompByCost<T>> priority_queue_;
 public:
  /**
   * pop one element
   */
  void Pop() {
    this->priority_queue_.pop();
  }
  /**
   * top option
   * @return the first element in the stack
   */
  State<T> *Top() {
    return this->priority_queue_.top();
  }
  /**
   * push state to the stack
   * @param s
   */
  void Push(State<T> *s) {
    this->priority_queue_.push(s);
  }
  /**
 * is empty method
 * @return True=is empty ,false else
 */
  bool IsEmpty() {
    return this->priority_queue_.empty();
  }
  /**
   * find if state exist in the implementation of priority_queueState
   * @param state
   * @return true =exist ,else nor
   */
  bool findState(State<T> *state) {
    std::priority_queue<State<T> *, std::vector<State<T> *>, CompByCost<T>> priority_queue_tmp{};
    while (!priority_queue_.empty()) {
      State<T> *tmp = priority_queue_.top();
      priority_queue_.pop();
      if (tmp == state) {
        priority_queue_.push(tmp);
        while (!priority_queue_tmp.empty()) {
          State<T> *move_back = priority_queue_tmp.top();
          priority_queue_tmp.pop();
          priority_queue_.push(move_back);
        }
        return true;
      }
      priority_queue_tmp.push(tmp);
    }
    while (!priority_queue_tmp.empty()) {
      State<T> *tmp2 = priority_queue_tmp.top();
      priority_queue_tmp.pop();
      priority_queue_.push(tmp2);
    }
    return false;
  }
  /**
   * remove the s element from the priority_queueState
   * @param s = the state we want to remove
   */
  void remove(State<T> *s) {
    std::vector<State<T> *> tmp;
    while (!priority_queue_.empty()) {
      State<T> *t = priority_queue_.top();
      priority_queue_.pop();
      if (t == s) {
        break;
      }
      tmp.emplace_back(t);
    }
    for (State<T> *b: tmp) {
      priority_queue_.push(b);
    }
  }
};

#endif //EX4_SEARCHALGORITHMS_PRIORITYQUEUESTATE_H_
