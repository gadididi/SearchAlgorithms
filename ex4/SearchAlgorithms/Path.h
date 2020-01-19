//
// Created by gadi on 12/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_PATH_H_
#define EX4_SEARCHALGORITHMS_PATH_H_

#include <stack>
/**
 * path class that hold stack of generic state .this class help us to recovery the path of searchable problm
 * @tparam P
 */
template<class P>
class Path {
 private:
  std::stack<P> path{};
 public:
  Path() {}
  /**
   * add node to stack
   * @param st
   */
  void add_to_path(P st) {
    this->path.push(st);
  }
  /**
   * getter the top element and pop the stack by this method
   * @return
   */
  P *get_element() {
    P *tmp = &path.top();
    path.pop();
    return tmp;
  }
  /**
   * top option for stack
   * @return p -  the top element
   */
  P *top_element() {
    P *tmp = &path.top();
    return tmp;
  }
  /**
   * is empty method
   * @return t- empty else not
   */
  bool finish_path() {
    return path.empty();
  }

};

#endif //EX4_SEARCHALGORITHMS_PATH_H_
