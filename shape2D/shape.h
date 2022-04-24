/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
  Shape(string x, double b, double h);
  void setName(string x);
  void setBase(double x);
  void setHeight(double x);
  string getName();
  double findArea();
  virtual double findPerimeter()=0;

private:
  string name;
  double base, height, area, perimeter;
};

#endif
