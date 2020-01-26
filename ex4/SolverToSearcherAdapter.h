//
// Created by ori294 on 1/14/20.
//

#ifndef EX4__SOLVERTOSEARCHERADAPTER_H_
#define EX4__SOLVERTOSEARCHERADAPTER_H_

#include "Searcher.h"
#include "Solver.h"

/**
 * SolverToSearcherAdapter: Adapter from solver to searcher
 * @tparam Solution A solution, mostly string.
 * @tparam Problem A problem, mostly string
 * @tparam T The param inside state, mostly point or vertex.
 */
template<class Solution, class Problem, class T>
class SolverToSearcherAdapter : public Solver<Solution, Problem> {
  Searcher<Solution, T>* searcher_;
 public:
  /**
   * SolverToSearcherAdapter CTOR
   * @param searcher a searcher
   */
  explicit SolverToSearcherAdapter(Searcher<Solution, T>* searcher) {
    this->searcher_ = searcher;
  }
  /**
   * solve: activate the searchable search method and return the solution.
   * @param searchAble a searchable problem.
   * @return the solution.
   */
  Solution solve(Problem searchAble) override {
    return searcher_->search(searchAble);
  }

  /**
   * create clone for adapter for parallel server
   * @return new adapter
   */
  SolverToSearcherAdapter<std::string, Searchable<Point> *, Point> * clone(){
    Searcher<Solution, T>* s = searcher_->clone();
    SolverToSearcherAdapter<std::string, Searchable<Point> *, Point> * adp = new SolverToSearcherAdapter(s);
    return adp;
  }

};

#endif //EX4__SOLVERTOSEARCHERADAPTER_H_
