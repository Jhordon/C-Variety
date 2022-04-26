/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
   'Generic Shape Properties'
*/

#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape {
public:
  void setID(string id);
  string getID();

  /* return a double from string input */
  double handleEntry();

  /* ~'shape'.getID() 's Measurements~      2. Shape's Measurements
     Provide a [ base, height, radius ]          Corresponding shapes name is displayed
     :                                           as well as prompts for its attributes
     __________________________________          handleEntry() --> attribute
     Type a numerical value                      display messages on error check
     __________________________________          
     Type a positive numerical value
     __________________________________          **challenge: try to clear terminal...
     Quitting...
     ____________________________________________________________________________________
  */

  /* ~'shape'.getID() 's Geometry~          3. Shape's Geometry
     Base      -->  [ base ]                     Upon success, the corresponding attributes
     Height    -->  [ height ]                   of the shape are shown as well as a prompt
     Area      -->  [ area ]                     that does 'nothing' unless [y] [n] are
     Perimeter -->  [ perimeter ]                pressed.
     _______________________________             "[y] --> 1."   "[n] --> [Q]"
     continue?  [y] [n]
     _____________________________________________________________________________________
  */
  void end();
  
protected:
  string id;
  double area, perimeter;
};


/* '2D Shapes' */
class Square: public Shape {
  public:
    Square(string id);

    void setMeasurements();
    void geoDeets();

  private:
    double side;
};

class Triangle: public Shape {
  public:
    Triangle(string id);

    void setMeasurements();
    void geoDeets();

  private:
    double base, height;
};

class Rectangle: public Shape {
  public:
    Rectangle(string id);

    void setMeasurements();
    void geoDeets();

  private:
    double base, height;
};

class Circle: public Shape {
  public:
    Circle(string id);
    
    void setMeasurements();
    void geoDeets();

  private:
    double radius, diameter;
};

#endif
