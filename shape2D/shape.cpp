/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#include <iostream>
#include "shape.h"

using namespace std;

void Shape::setID(string i) {
  id = i;
}

void Shape::setBase(double b) {
  base = b;
}

void Shape::setHeight(double h) {
  height = h;
}

void Shape::setRadius(double r) {
  radius = r;
}

string Shape::getID() {
  return id;
}

double Shape::getBase() {
  return base;
}

double Shape::getHeight() {
  return height;
}

double Shape::getArea() {
  return area;
}

double Shape::getPerimeter() {
  return perimeter;
}

/* class Shape {} --> "Circle, Square, Triangle, Rectangle"
                                '|A.P.I.E|' 
   Useful Formulas:
    Circle:
      Area = pi*radius^2    Circumference = pi*diameter
    Square:
      Area = side^2   Perimeter = side*4
    Triangle:
      Area = 1/2*base*height    Perimeter = base*3
    Rectangle:
      Area = base*height  Perimeter = (base*2) + (height*2)
*/

class Square: public Shape {
  public:
    Square() {
      setID("Square");
    }
    void findArea() {
      area = base * height;
    }
    
    void findPerimeter() {
      perimeter = base * 4;
    }
};

class Triangle: public Shape {
  public:
    Triangle() {
      setID("Triangle");
    }
    void findArea() {
      area = 0.5 * base * height;
    }

    void findPerimeter() {
      perimeter = base * 3;
    }
};

class Rectangle: public Shape {
  public:
    Rectangle() {
      setID("Rectangle");
    }
    void findArea() {
      area = base * height;
    }

    void findPerimeter() {
      perimeter = ((base*2)+(height*2));
    }
};

class Circle: public Shape {
  public:
    Circle() {
      setID("Circle");
    }

    void findArea() {
      area = (3.14159256 * (radius * radius));
    }

    void findPerimeter() {
      perimeter = (3.14159256 * (radius * 2));
    }
};