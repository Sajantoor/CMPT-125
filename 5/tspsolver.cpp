#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list): 
  m_list(list)
{}

void TSPSolver::solve() {
  Point* start = getAvg();
  swap(start, 0);
  
  // Go through all points, find nearest, break ties by going further away from start
  // once point is found counter++, move it in the list
  // Moving: swap index where item is supposed to go and item 
  // Continue with that point and look at remaining points

  Point* last = start; 
  unsigned int length = m_list.getLen();
  unsigned int i = 1; // start is already decided
  
  while (i < length) {
    // find min distance of all items 
    int minDist = 40;
    Point* winner = NULL; // element with least distance 
    Point* el = last; 

    while (el != NULL) {
      int dist = el->getDistance(*last);
      
      if (dist < minDist) { 
        minDist = dist;
        winner = el; 
      // in tie case, break tie by looking at element furthest from start since we have to go back anyways, other element is the current winner 
      } else if (dist == minDist) {
        int currentWinDist = start->getDistance(*winner);
        int elDist = start->getDistance(*el);
        
        if (elDist > currentWinDist) {
          winner = el;
        }
      }

      el = el->getNext();
    }

    // winner has be determined, swap
    this->swap(winner, i);
    i++;
  }
}

// find index and swap 
void TSPSolver::swap(Point* point, unsigned int swapIndex) {
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
} 

ListOfPoints TSPSolver::getSolution() {
  return m_list;
}

// picks the initial point by averaging max - min for x and y and finding closest point to it 
Point* TSPSolver::getAvg() {
  Point* el = this->m_list.getHead();
  cout << *el << endl;
  // initialize max and min 
  int max_x = -1;
  int min_x = 21;
  int max_y = -1;
  int min_y = 21;

  // traverse through all element in list and find max and min
  while (el != NULL) {
    cout << *el << endl;
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
  int avgX = max_x - min_x;
  int avgY = max_y - min_y;

  // if all points are in straight line or more or less straight line
  // the avg point will not be right, this corrects for it
  if (avgX == 0) {
    avgY /= 2;
  } 
  
  if (avgY == 0) {
    avgX /= 2;
  }

  cout << "AvgX: " << avgX << " AvgY: " << avgY << endl;

  // create new point with these avg x and y
  Point avg = Point(avgX, avgY, "Average point"); 

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

  cout << *winner << endl;
  return winner;
}

void TSPSolver::printSolution() {
  Point* el = m_list.getHead();
  
  while (el != NULL) {
    cout << el->getName() << " -> ";
    el = el->getNext();
  }

  cout << m_list.getHead()->getName() << endl;
}