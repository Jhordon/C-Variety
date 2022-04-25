/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
*/

#include <iostream>
#include "shape.h"

using namespace std;

void geoDeets(Shape & obj) {
  /* ~'shape'.getID() 's Geometry~          3. Shape's Geometry
      Base      -->  [ base ]                     Upon success, the corresponding attributes
      Height    -->  [ height ]                   of the shape are shown as well as a prompt
      Area      -->  [ area ]                     that again does nothing unless [y] [n] are
      Perimeter -->  [ perimeter ]                pressed.
      _______________________________             "[y] --> 1."   "[n] --> [Q]"
      continue?  [y] [n]
      _____________________________________________________________________________________
   */
  
  cout << "~" << obj.getID() << "'s Geometry~\n";
  if (obj.getID() == "Circle") {
    cout << "Radius -------- " << to_string(obj.getRadius()) << endl;
    cout << "Area   -------- " << to_string(obj.getArea()) << endl;
    cout << "Circumference - " << to_string(obj.getPerimeter()) << endl;

  } else if (obj.getID() == "Square") {
    cout << "Side -------- " << to_string(obj.getBase()) << endl;
    cout << "Area -------- " << to_string(obj.getArea()) << endl;
    cout << "Perimeter --- " << to_string(obj.getPerimeter()) << endl;

  } else if (obj.getID() == "Triangle" || obj.getID() == "Rectangle") {
    cout << "Base -------- " << to_string(obj.getBase()) << endl;
    cout << "Height ------ " << to_string(obj.getHeight()) << endl;
    cout << "Area -------- " << to_string(obj.getArea()) << endl;
    cout << "Perimeter --- " << to_string(obj.getPerimeter()) << endl;

  } else {
    cout << "'Just to suffer?...'\n";
  }
}

double handleEntry(string i) {
  // return a double from string input
  do {
    try {
      return stod(i);
    } catch (exception e) {
      if (i.compare("Q") == 0) {
        cout << "Quitting...";
        return 0;
      } else if (stod(i) < 0) {
        cout << "Type a positive numerical value.\n";
      } else {
        cout << "Type a numerical value.\n";
      }
    }
    // vvv is this the proper way to loop in this instance?
  } while (true);
}

void setMeasurement(Shape & obj) {
  string input;
  double temp;
  /* ~'shape'.getID() 's Measurements~      2. Shape's Measurements
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

  if (obj.getID() == "Circle") {
    cout << "~" << obj.getID() << "'s Measurments~\nProvide a radius\n: ";
    getline(cin, input);
    temp = handleEntry(input);

    if (temp == 0) {
      // exit
    } else {
      obj.setRadius(temp);
      obj.findArea();
      obj.findPerimeter();
    }

  } else if (obj.getID() == "Square") {
    cout << "~" << obj.getID() << "'s Measurements~\nProvide a base\n: ";
    getline(cin, input);
    temp = handleEntry(input);
    
    if (temp == 0) {
      // exit
    } else {
      obj.setBase(temp);
      obj.findArea();
      obj.findPerimeter();
    }

  } else if (obj.getID() == "Triangle" || obj.getID() == "Rectangle") {
    cout << "~" << obj.getID() << "'s Measurements~\nProvide a base\n: ";
    getline(cin, input);
    temp = handleEntry(input);

    if (temp == 0) {
      // exit
    } else {
      obj.setBase(temp);
    }

    cout << "Provide a height\n: ";
    getline(cin, input);
    temp = handleEntry(input);

    if (temp == 0) {
      // exit
    } else {
      obj.setHeight(temp);
      obj.findArea();
      obj.findPerimeter();
    }

  } else {
    cout << "'Why are we still here?....'\n";
  }
}

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
    cout << "~Shape Geometry: 2D Edition\n[1] Circle\n[2] Square      [Q] Quit\n[3] Triangle\n[4] Rectangle\n:";
    getline(cin, input);

    if (input.compare("1") == 0) {
      Circle myObj;
      setMeasurement(myObj);
      geoDeets(myObj);

      cout << "continue? [y]  [n]\n: ";
      while (input != "y" || input != "n") { 
        getline(cin, input);
        if (input.compare("y") == 0) {
          continue;
        } else if (input.compare("n") == 0) {
          cout << "Bye!";
          return 0;
        } else {
          cout << ": ";
        }      
      }
    
    } else if (input.compare("2") == 0) { 
      Square myObj;
      setMeasurement(myObj);
      geoDeets(myObj);

      cout << "continue? [y]  [n]\n: ";
      while (input != "y" || input != "n")
      {
        getline(cin, input);
        if (input.compare("y") == 0)
        {
          continue;
        }
        else if (input.compare("n") == 0)
        {
          cout << "Bye!";
          return 0;
        }
        else
        {
          cout << ": ";
        }
      }

    } else if (input.compare("3") == 0) {
      Triangle myObj;
      setMeasurement(myObj);
      geoDeets(myObj);

      cout << "continue? [y]  [n]\n: ";
      while (input != "y" || input != "n")
      {
        getline(cin, input);
        if (input.compare("y") == 0)
        {
          continue;
        }
        else if (input.compare("n") == 0)
        {
          cout << "Bye!";
          return 0;
        }
        else
        {
          cout << ": ";
        }
      }

    } else if (input.compare("4") == 0) {
      Rectangle myObj;
      setMeasurement(myObj);
      geoDeets(myObj);

      cout << "continue? [y]  [n]\n: ";
      while (input != "y" || input != "n")
      {
        getline(cin, input);
        if (input.compare("y") == 0)
        {
          continue;
        }
        else if (input.compare("n") == 0)
        {
          cout << "Bye!";
          return 0;
        }
        else
        {
          cout << ": ";
        }
      }
      
    } else {
      if (input.compare("Q") == 0) {
        cout << "Bye!";
        return 0;
      } else {
        cout << ":";
      }
    }
  }
  return 0;
}
