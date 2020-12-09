#ifndef _LIST_OF_POINT_HPP
#define _LIST_OF_POINT_HPP

#include <iostream>
#include <vector>

#include "point.hpp"

// the class stores an ordered list of points
// used to store the input to the problem
// may be also used to store a partial solution to the TSP problem
class ListOfPoints {
  private: 
    Point* head;
    Point* tail;
    unsigned int len; 
    // create some data structure of items
  public:
    ListOfPoints();

    // adds a new point to the end of the list
    void addPoint(Point &newPt);
    
    // prints the list of points
    void printList() const;
    
    // draws the points
    void draw() const;

    // returns the head
    Point* getHead() {
      return head;
    }

    Point* getTail() {
      return tail; 
    }

    unsigned int getLen() {
      return len;
    }
};

#endif