//
// Created by ori294 on 1/7/20.
//

#include "StringReverser.h"

/**
 * Reverse the string
 * @param str string
 * @return the new reversed string
 */
std::string StringReverser::solve(std::string str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++)
    std::swap(str[i], str[n - i - 1]);

  return str;
}