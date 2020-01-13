//
// Created by gadi on 12/01/2020.
//

#ifndef EX4_SEARCHALGORITHMS_PATH_H_
#define EX4_SEARCHALGORITHMS_PATH_H_

#include <stack>
/**
 * need to fix the direction of path!!!
 * @tparam P
 */
template<class P>
class Path {
 private:
  std::stack<P> path{};
 public:
  Path() {
  }
  void add_to_path(P st) {
    this->path.push(st);
  }
  P *get_element() {
    P *tmp = &path.top();
    path.pop();
    return tmp;
  }
  bool finish_path() {
    return path.empty();
  }

};

#endif //EX4_SEARCHALGORITHMS_PATH_H_
