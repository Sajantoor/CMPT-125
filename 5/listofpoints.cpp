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
  cout << "Drawing the points..." << endl;
  // array to store points that fit with in the y coordinate
  unsigned int size = 2; 
  // no need to actually have array of classes, just array of class pointers
  Point** arr = new Point*[size];

  if (arr == NULL) {
    cout << "Failed to draw points..." << endl;
    return; 
  } 

  unsigned int len = 0; 

  // draw a 21 x 21 grid with all items on it, points can have coordinates of 0 t0 20 inclusive
  for (int i = 0; i <= 20; i++) { // draw y coord
    int flag = 0;
    Point* el = this->head;

    // find if any item has a y coordinate equal to i add to array 
    while (el != NULL) {
      // check if y coordinate matches to the current y coordinate being printed
      if (el->getY() == i) {
        // add more space to pointer array if hit capacity
        if (len == size) {
          size *= 2; 
          arr = (Point**) realloc(arr, sizeof(Point*) * size);
          // realloc failed
          if (arr == NULL) {
              cout << "Failed to draw points..." << endl;
              return; 
          }
        }

        // add matching element to array 
        arr[len] = el;
        flag = 1;
        len++;
      }

      el = el->getNext();
    }

    // print x coordinate, where actaul printing happens
    for (int j = 0; j <= 20; j++) {
      if (!flag) {
        cout << "- ";
      } else {
        int foundPoint = 0;
        for (unsigned int k = 0; k < len; k++) {
           // check all items in array if their x coord matches 
          if (arr[k]->getX() == j) {
              cout << arr[k]->getName() << " ";
              foundPoint = 1;
              break; // assumes no points at same coords
          }
        }

        if (!foundPoint) {
          cout << "- ";
        }
      }
    }

    // clear array for next use
    for (unsigned int k = 0; k < len; k++) {
      arr[k] = NULL;
    }

    len = 0;
    cout << endl;
  }

  delete [] arr;
}
 