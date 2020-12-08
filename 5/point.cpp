#include "point.hpp"

float Point::getDistance(const Point &other) {
  // distance between two points is sqrt((x_2 - x_1)^2 + (y_2 - y_1)^2))
  int x_1 = other.getX();
  int y_1 = other.getY();

  int x_2 = this->getX();
  int y_2 = this->getY();
  
  return sqrt( pow(x_2 - x_1, 2.0) + pow(y_2 - y_1, 2.0) );
}

string Point::toString() const{
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const{
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
