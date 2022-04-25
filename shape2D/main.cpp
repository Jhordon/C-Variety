/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#include <iostream>
#include "shape.h"

using namespace std;

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

double handleEntry(string i) {
  // return a double from string input
}

int main() {
  /* ~Shape Geometry: 2D Edition~             1. Menu Prompt
     [1]  Circle                                 Press the associated key for the action
     [2]  Square      [Q] Quit                   Other key presses do nothing
     [3]  Triangle
     [4]  Rectangle
     ___________________________________________________________________________________
  */

  /* ~'shape'.getName() 's Measurements~      2. Shape's Measurements
     Provide a [ base, height, radius ]          Corresponding shapes name is displayed
     :                                           as well as prompts for its attributes
     __________________________________          handleEntry() --> attribute
     Type a numerical value                      display these messages on error check
     __________________________________          do nothing if '.empty()'
     Type a positive numerical value             
     __________________________________          challenge: try to clear terminal...
     Quitting...
     ____________________________________________________________________________________
  */

  /* ~'shape'.getName() 's Geometry~          3. Shape's Geometry
     Base      -->  [ base ]                     Upon success, the corresponding attributes
     Height    -->  [ height ]                   of the shape are shown as well as a prompt
     Area      -->  [ area ]                     that again does nothing unless [y] [n] are
     Perimeter -->  [ perimeter ]                pressed. 
     _______________________________             "[y] --> 1."   "[n] --> [Q]"
     continue?  [y] [n]
     _____________________________________________________________________________________
  */
  return 0;
}
