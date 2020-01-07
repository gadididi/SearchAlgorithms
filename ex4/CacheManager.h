//
// Created by gadi on 07/01/2020.
//

#ifndef SEARCHALGORITHMS__CACHEMANAGER_H_
#define SEARCHALGORITHMS__CACHEMANAGER_H_

template<class Solution>
class CacheManager {
 public:
  virtual bool isExist(std::string) = 0;
  virtual Solution get(std::string) = 0;
  virtual void insert(std::string, Solution) = 0;
};

#endif //SEARCHALGORITHMS__CACHEMANAGER_H_
