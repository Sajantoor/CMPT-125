#include "listofpoints.hpp"


ListOfPoints::ListOfPoints()
  : head(NULL), tail(NULL), len(0)
{}

void ListOfPoints::addPoint(Point &newPt) {
  // create point on heap
  Point* point = new Point(newPt.getX(), newPt.getY(), newPt.getName());

  // create links 
  point->setNext(NULL);
  point->setPrevious(this->tail);  // if null that's fine, if exist that's also fine
  this->len++;

  // if linked list is empty 
  if (this->head == NULL && this->tail == NULL) {
    this->head = point;
    this->tail = point;
  // linked list is not empty, add to tail, move tail to new element
  } else {
    this->tail->setNext(point);
    this->tail = point;    
  }
}

void ListOfPoints::printList() const {
  // this list is empty 
  if (this->head == NULL && this->tail == NULL) {
    return; 
  }
  
  // list has 1 element
  if (this->head == this->tail) {
    this->head->printPoint();
    return;
  }

  // list has multiple points
  Point* el = this->head;
  while (el != NULL) { // end is always NULL 
    el->printPoint();
    el = el->getNext();
  }
}

void ListOfPoints::draw() const {
  // draw a 20 x 20 grid with all items on it
  cout << "drawing the points..." << endl;
}
 