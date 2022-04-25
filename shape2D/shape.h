/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;
class Shape {
public:
  void setID(string i);
  void setBase(double b);
  void setHeight(double h);
  void setRadius(double r);

  void findArea();
  void findPerimeter();
  
  string getID();
  double getRadius();
  double getHeight();
  double getBase();
  double getArea();
  double getPerimeter();

protected:
  string id;
  double base, height, area, perimeter, radius;
};

class Square: public Shape {
  public:
    Square();
    void findArea();
    void findPerimeter();
};

class Triangle: public Shape {
  public:
    Triangle();
    void findArea();
    void findPerimeter();
};

class Rectangle: public Shape {
  public:
    Rectangle();
    void findArea();
    void findPerimeter();
};

class Circle: public Shape {
  public:
    Circle();
    void findArea();
    void findPerimeter();  
};

#endif
