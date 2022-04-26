/* C++: Shape Geometry
   Generate details about a shape's geometry - @Jhordon
   'Defining the Object & Functions'
*/

#include <iostream>
#include "shape.h"

using namespace std;

void Shape::setID(string i) {
  id = i;
}

string Shape::getID() {
  return id;
}

/* return a double from string input */
double Shape::handleEntry() {
  for (;;) {
    string input;
    getline(cin, input);
    try
    {
      if (stod(input) < 0) {
        cout << "Type a positive numerical value.\n:";
      } else {
        return stod(input);
      }
    }
    catch (...)
    {
      if (input.compare("Q") == 0)
      {
        cout << "Quitting...\n";
        return 0;
      } else {
        cout << "Type a positive numerical value.\n:";
      }
    }
  }
}

/* 'continue?' */
void Shape::end() {
  string input;
  cout << "continue? [y]  [n]\n: ";
  while (input != "y" || input != "n")
  {
    getline(cin, input);
    if (input.compare("y") == 0)
    {
      break;
    }
    else if (input.compare("n") == 0)
    {
      cout << "Bye!\n";
      exit(0);
    }
    else
    {
      cout << ": ";
    }
  }
}


/* class Shape {} <--- "Circle, Square, Triangle, Rectangle"
                                'OOP |A.P.I.E|' 
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

Square::Square(string id) {
  setID(id);
  setMeasurements();
}

void Square::setMeasurements() {
  cout << "~" << getID() << "'s Measurements~\nSide Length\n: ";
  side = handleEntry();

  if (side == 0) {
    return;
  } else {
    area = side * side;
    perimeter = side * 4;
    geoDeets();
  }
}

void Square::geoDeets() {
  cout << "\n~" << getID() << "'s Geometry~\n";
  cout << "Side -------- " << to_string(side) << endl;
  cout << "Area -------- " << to_string(area) << endl;
  cout << "Perimeter --- " << to_string(perimeter) << endl;
  end();
}


Triangle::Triangle(string id) {
  setID(id);
  setMeasurements();
}

void Triangle::setMeasurements() {
  cout << "~" << getID() << "'s Measurements~\nLength of Base\n: ";
  base = handleEntry();
  if (base == 0) {
    return;
  } else {
    cout << "Height\n: ";
    height = handleEntry();
    // height == 0 check...
    area = 0.5 * base * height;
    perimeter = base * 3;
    geoDeets();
  }
}

void Triangle::geoDeets() {
  cout << "\n~" << getID() << "'s Geometry~\n";
  cout << "Base -------- " << to_string(base) << endl;
  cout << "Height ------ " << to_string(height) << endl;
  cout << "Area -------- " << to_string(area) << endl;
  cout << "Perimeter --- " << to_string(perimeter) << endl;
  end();
}


Rectangle::Rectangle(string id) {
  setID(id);
  setMeasurements();
}

void Rectangle::setMeasurements() {
  cout << "~" << getID() << "'s Measurements~\nLength of Base\n: ";
  base = handleEntry();
  if (base == 0)
  {
    return;
  }
  else
  {
    cout << "Height\n: ";
    height = handleEntry();
    // height == 0 check...
    area = base * height;
    perimeter = (base * 2) + (height * 2);
    geoDeets();
  }
}

void Rectangle::geoDeets() {
  cout << "\n~" << getID() << "'s Geometry~\n";
  cout << "Base -------- " << to_string(base) << endl;
  cout << "Height ------ " << to_string(height) << endl;
  cout << "Area -------- " << to_string(area) << endl;
  cout << "Perimeter --- " << to_string(perimeter) << endl;
  end();
}


Circle::Circle(string id) {
  setID(id);
  setMeasurements();
}

void Circle::setMeasurements() {
  cout << "~" << getID() << "'s Measurements~\nRadius Length\n: ";
  radius = handleEntry();

  if (radius == 0)
  {
    return;
  }
  else
  {
    diameter = radius * 2;
    area = 3.14159256 * (radius * radius);
    perimeter = 3.14159256 * diameter;
    geoDeets();
  }
}

void Circle::geoDeets() {
  cout << "\n~" << getID() << "'s Geometry~\n";
  cout << "Radius -------- " << to_string(radius) << endl;
  cout << "Diameter ------ " << to_string(diameter) << endl;
  cout << "Area   -------- " << to_string(area) << endl;
  cout << "Circumference - " << to_string(perimeter) << endl;
  end();
}