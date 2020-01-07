//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__CACHEMANAGER_H_
#define SEARCHALGORITHMS__CACHEMANAGER_H_

template<class Problem, class Solution>
class CacheManager {
 public:
  virtual bool isExist() = 0;
  virtual void get_solution() = 0;
  virtual void saveInCache() = 0;
};

#endif //SEARCHALGORITHMS__CACHEMANAGER_H_
