#ifndef _TSP_SOLVER_HPP
#define _TSP_SOLVER_HPP

#include <iostream>

#include "listofpoints.hpp"

using namespace std;

// the class implement the TSP solver
class TSPSolver {
  private:  
  // may hold the following members:
  ListOfPoints m_list;
  // you may remove/modify these in any way you want

  public:
    // constructor
    TSPSolver(ListOfPoints &list);

    // solves the problem and stores solution
    void solve();

    // returns the solution obtained by the solve method
    ListOfPoints getSolution();

    // get the length of the solution
    float getLength();

    // prints the TSP solution
    void printSolution();

    // gets the avg of all points
    Point* getAvg();

    Point* swap(Point* point, unsigned int swapIndex);
};

#endif