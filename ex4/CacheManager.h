//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__CACHEMANAGER_H_
#define SEARCHALGORITHMS__CACHEMANAGER_H_

/**
 * CacheManager: interface.
 * @tparam Problem mostly string
 * @tparam Solution mostly string
 */
template<class Problem, class Solution>
class CacheManager {
 public:
  virtual bool isExist(Problem) = 0;
  virtual Solution get(Problem) = 0;
  virtual void insert(Problem, Solution) = 0;
};

#endif //SEARCHALGORITHMS__CACHEMANAGER_H_
