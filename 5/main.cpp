#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,7,"Q");
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;
  q.printPoint();
  cout << q.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << q << endl;
}


// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  ListOfPoints list = solver.getSolution();

  cout << "Solution found is: " << endl;
  solver.printSolution();
  cout << "the length of the solution is: " << solver.getLength() << endl;
}

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    p = Point(i,0,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

// completely random test to test
void test3() {
  srand(time(NULL));
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i < rand() % 400; i++) {
    char randomChar = rand() % 95 + 32;
    string randomString = string(1,  randomChar);
    p = Point(rand() % 20, rand() % 20, randomString);
    inputTSP.addPoint(p);
  }
  inputTSP.printList();  
  inputTSP.draw();  
  
  testSolver(inputTSP);
}

// test points at all coordinates
void test4() {
  ListOfPoints inputTSP;
  Point p(0,0, "a");
  cout << "Creating a list of points:" << endl;
  
  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 20; j++) {
      p = Point(i, j, "" + to_string(rand() % 5000));
      inputTSP.addPoint(p); 
    }
  }

  inputTSP.printList();  
  inputTSP.draw();  
  testSolver(inputTSP);
}

// vertical line
void test5() {
  ListOfPoints inputTSP;
  Point p(0,0, "a");
  cout << "Creating a list of points:" << endl;
  
  for (int i = 0; i <= 20; i++) {
      p = Point(0, i, "" + to_string(i));
      inputTSP.addPoint(p); 
  }

  inputTSP.printList();  
  inputTSP.draw();  
  testSolver(inputTSP);
}


int main() {
  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;

  return 0;
}