//
// Created by ori294 on 1/7/20.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <functional>
#include "CacheManager.h"
using namespace std;
/**
 * CacheManager: managing a cahce with O(1) access or O(n) if the item isn't in the cache.
 * @tparam T an object, in this ex it will be Student Or Employee
 */
template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {

 private:
  int _cacheCap{};
  fstream _writeFile;
  list<string> _cacheList;
  hash<Problem> myHash;
  unordered_map<string, pair<Solution, list<string>::iterator>> _cacheMap;

 public:
  /**
   * returns an object in O(1) if it's in the cache and O(n) if not.
   * @param key object key
   * @return an object
   * @return an object
   */
  Solution get(Problem problem) override {
    std::size_t hash = myHash(problem);
    std::string key = to_string(hash);

    typename unordered_map<string, pair<Solution, list<string>::iterator>>::const_iterator iter = _cacheMap.find(key);
    if (iter != _cacheMap.end()) {
      _cacheList.erase(iter->second.second);
      _cacheList.push_front(key);
      Solution tempObj = Solution(iter->second.first);
      _cacheMap.erase(iter);

      pair<Solution, list<string>::iterator> tempPair =
          pair<Solution, list<string>::iterator>(tempObj, _cacheList.begin());
      _cacheMap.insert({key, tempPair});

      return iter->second.first;
    } else {
      //get from file O(n)
      Solution obj = read(key);
      insertFileToCache(key, obj);
      return obj;
    }
  };

  /**
   * read object from function
   * @param obj object pointer
   * @param key object key
   * @return object T
   */
  Solution read(std::string key) {
    fstream readFile(key + ".txt", ios::in);
    if (!readFile) {
      throw "Error opening file";
    } else {
      std::string buffer;
      std::string solution = "";

      while (!readFile.eof()) {
        std::getline(readFile, buffer);
        solution += buffer;
      }
      return solution;
    }
  }

  /**
   * Insert a new object into memory file.
   * @param key object key
   * @param obj the object
   */
  void insert(Problem problem, Solution obj) override {
    std::size_t hash = myHash(problem);
    std::string key = to_string(hash);

    _writeFile.open(key + ".txt", ios::out);
    if (!_writeFile) {
      throw "Error opening file";
    }
    _writeFile << obj;
    _writeFile.close();

    std::cout << "saving file..." << endl;

    if (_cacheMap.find(key) == _cacheMap.end()) {
      insertFileToCache(key, obj);
    } else {
      typename unordered_map<string, pair<Solution, list<string>::iterator>>::const_iterator iter = _cacheMap.find(key);
      _cacheList.erase(iter->second.second);
      _cacheMap.erase(iter);
      insertFileToCache(key, obj);
    }
  };

  /**
   * Insert a new object into the cache.
   * @param key object key
   * @param obj the object
   */
  void insertFileToCache(std::string key, Solution obj) {
    //Add to the start of the cache in O(1)
    if (_cacheCap > _cacheMap.size()) {
      _cacheList.push_front(key);

      pair<Solution, list<string>::iterator> tempPair = pair<Solution, list<string>::iterator>(obj, _cacheList.begin());
      _cacheMap.insert({key, tempPair});
    } else {
      _cacheMap.erase(_cacheMap.find(*(--_cacheList.end())));
      _cacheList.pop_back();
      _cacheList.push_front(key);

      pair<Solution, list<string>::iterator> tempPair = pair<Solution, list<string>::iterator>(obj, _cacheList.begin());
      _cacheMap.insert({key, tempPair});

    }
  }

  /**
   * Activate a function on each of the cache objects.
   * @tparam function : any functor or lambda function
   * @param func the given function
   */
  void foreach(const function<void(Solution &)> func) {
    for (auto iter = _cacheList.begin(); iter != _cacheList.end(); iter++) {
      typename unordered_map<string, pair<Solution,
                                          list<string>::iterator>>::const_iterator tempIter = _cacheMap.find(*iter);
      Solution obj = Solution(tempIter->second.first);
      func(obj);
    }
  }

  /**
   * isExist: find is a solution is already exists in the cache.
   * @param key a string to search
   * @return boolean value.
   */
  bool isExist(Problem problem) override {
    std::size_t hash = myHash(problem);
    std::string key = to_string(hash);
    if (_cacheMap.find(key) == _cacheMap.end()) {
      ifstream f((key + ".txt").c_str());
      return f.good();
    } else {
      return true;
    }
  }

  /**
   * CTOR
   * @param capacity - max objects in the cache
   */
  FileCacheManager(int capacity) {
    this->_cacheCap = capacity;
    this->_cacheMap = unordered_map<string, pair<Solution, list<string>::iterator>>();
    this->_cacheList = list<string>();
  }

  /**
   * DTOR.
   */
  ~FileCacheManager() {
    //
  };

};

#endif //EX4__FILECACHEMANAGER_H_
