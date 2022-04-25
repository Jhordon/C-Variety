/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#include <iostream>
#include "shape.h"

using namespace std;

Shape::Shape(string n, double b, double h) {
  setName(n);
  setBase(b);
  setHeight(h);
}

void Shape::setName(string n) {
  name = n;
}

void Shape::setBase(double b) {
  base = b;
}

void Shape::setHeight(double h) {
  height = h;
}

string Shape::getName() {
  return name;
}

double Shape::getBase() {
  return base;
}

double Shape::getHeight() {
  return height;
}