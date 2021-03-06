#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list): 
  m_list(list)
{}

void TSPSolver::solve() {
  // empty list
  if (m_list.getHead() == NULL) {
    cout << "Empty list" << endl;
    return;
  }

  Point* start = getAvg();
  start = swap(start, 0);
  
  // Go through all points, find nearest, break ties by going further away from start
  // once point is found counter++, move it in the list
  // Moving: swap index where item is supposed to go and item 
  // Continue with that point and look at remaining points

  Point* last = start; // the last element already sorted
  unsigned int length = m_list.getLen();
  unsigned int i = 1; // start is already decided
  
  while (i < length) {
    // find min distance of all items 
    float minDist = 40;
    Point* winner = NULL; // element with least distance 
    Point* el = last->getNext(); // we don't want to sort same element again, already in correct spot so we look at next element

    while (el != NULL) {
      float dist = el->getDistance(*last);      
      if (dist < minDist) { 
        minDist = dist;
        winner = el; 
      // in tie case, break tie by looking at element furthest from start since we have to go back anyways, other element is the current winner 
      } else if (dist == minDist) {
        float currentWinDist = start->getDistance(*winner);
        float elDist = start->getDistance(*el);
        // furthest gets declared as winner
        if (elDist > currentWinDist) {
          winner = el;
        }
      }

      el = el->getNext();
    }

    // winner has be determined, swap, get address and last
    last = this->swap(winner, i);
    i++;
  }
}

// find index and swap 
Point* TSPSolver::swap(Point* point, unsigned int swapIndex) {
  Point* el = m_list.getHead();
  unsigned int i = 0;

  while (i != swapIndex && el) {
    el = el->getNext();
    i++;
  }

  // copy of original values
  Point swapValues = *el;
  
  // probably easier to just swap values instead of moving in the linked list so just gonna do that unless there's bugs
  el->setName(point->getName());
  el->setX(point->getX());
  el->setY(point->getY());

  point->setName(swapValues.getName());
  point->setX(swapValues.getX());
  point->setY(swapValues.getY());

  return el;
} 

ListOfPoints TSPSolver::getSolution() {
  return m_list;
}

// picks the initial point by averaging max - min for x and y and finding closest point to it 
Point* TSPSolver::getAvg() {
  Point* el = this->m_list.getHead();
  // initialize max and min 
  int max_x = -1;
  int min_x = 21;
  int max_y = -1;
  int min_y = 21;

  // traverse through all element in list and find max and min
  while (el != NULL) {
    int x = el->getX();
    int y = el->getY();

    if (x > max_x) {
      max_x = x;
    } 

    if (x < min_x) {
      min_x = x;
    }

    if (y > max_y) {
      max_y = y;
    }

    if (y < min_y) {
      min_y = y;
    }

    el = el->getNext();
  } 

  // coordinates of the approximate middle of the all points
  int avgX = round((max_x - min_x) / 2.0) + min_x;
  int avgY = round((max_y - min_y) / 2.0) + min_y;

  // create new point with these avg x and y
  Point avg = Point(avgX, avgY, "Average point"); 
  cout << "AvgX: " << avgX << "AvgY: " << avgY << endl;

  // compare distances to average point and find the smallest distance, whichever point has the smallest is the first point 
  el = this->m_list.getHead();
  Point* winner = el;
  float lowestDistance = 40; // 20 * 20 coords so 40 is init value, high non possible value

  while (el != NULL) {
    float distance = el->getDistance(avg);
    // found new winner, lowest distance 
    if (distance < lowestDistance) {
      lowestDistance = distance; 
      winner = el;
    }

    el = el->getNext();
  }

  return winner;
}

void TSPSolver::printSolution() {
  Point* el = m_list.getHead();
  if (el == NULL) {
    return;
  }
  
  while (el != NULL) {
    cout << el->getName() << " -> ";
    el = el->getNext();
  }

  cout << m_list.getHead()->getName() << endl;
}

float TSPSolver::getLength() {
  float length = 0; 
  Point* head = m_list.getHead();
  
  if (head == NULL) {
    return 0;
  }

  Point* el = head->getNext();
  if (el == NULL) {
    return 0;
  }

  Point* lastEl = head;

  // go through all points and add up lengths
  while (el != NULL) {
    length += el->getDistance(*lastEl);
    lastEl = el; 
    el = el->getNext();
  }

  // length of last point 
  length += lastEl->getDistance(*head);
  return length;
}