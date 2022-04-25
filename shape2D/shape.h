/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;
class Shape {
public:
  Shape(string n, double b, double h);
  virtual double findArea(double b, double h)=0;
  virtual double findPerimeter(double b, double h)=0;
  void setName(string n);
  void setBase(double b);
  void setHeight(double h);
  string getName(); 
  double getHeight();
  double getBase();

protected:
  string name;
  double base, height, area, perimeter;
};

#endif
