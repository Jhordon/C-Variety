/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#include <iostream>
#include "shape.h"

using namespace std;

int main() {
  string input;
  /* ~Shape Geometry: 2D Edition~             1. Menu Prompt
     [1]  Circle                                 Type the associated key and press enter
     [2]  Square      [Q] Quit                   Other entries do nothing
     [3]  Triangle
     [4]  Rectangle
     ___________________________________________________________________________________
  */

  while(input != "Q") {
    cout << "\n~Shape Geometry: 2D Edition\n[1] Circle\n[2] Square      [Q] Quit\n[3] Triangle\n[4] Rectangle\n:";
    getline(cin, input);

    if (input.compare("1") == 0) {
      Circle myObj("Circle");
    
    } else if (input.compare("2") == 0) { 
      Square myObj("Square");

    } else if (input.compare("3") == 0) {
      Triangle myObj("Triangle");

    } else if (input.compare("4") == 0) {
      Rectangle myObj("Rectangle");
      
    } else {
      if (input.compare("Q") == 0) {
        cout << "Bye!\n";
        return 0;
      } 
    }
  }
  return 0;
}
