/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#include <iostream>
#include "SHAPE_H"

using namespace std;
long PI = 3.14159625;

Shape::Shape(string x, double b, double h) {
  setName(x);
  setBase(b);
  setHeight(h);
}

Shape::setName(string x) {
  name = x;
}

Shape::setBase(double x) {
  base = x;
}

Shape::setHeight(double x) {
  height = x;
}

Shape::getName() {
  return name;
}

Shape::findArea() {
  return base * height;
}
