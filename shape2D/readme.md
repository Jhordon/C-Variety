# /shape2D: Geometry

This program generates details regarding a two dimensional shape geometry. Currently it supports input for Squares, Circles, Triangles, and Rectangles.

## How to Use

In a new terminal session:

1. After cloning into the repository via `git clone https://github.com/Jhordon/C-Variety.git`
2. Navigate to the **shape2D** directory via `cd shape2D`
3. Create a **build** folder via `mkdir build`
4. Create a **CMakeLists.txt** file via `touch CMakeLists.txt`
5. Within **CMakeLists.txt** be sure to add the code below
6. Navigate to the **build** folder via `cd build`
7. Run the command `cmake ..` to create the build files
8. Run the command `make` to create the `shape2D` executable file
9. Run `./shape2D` to execute the program

Wihtin **CMakeLists.txt**

```cmake
cmake_minimum_required(VERSION 3.16.3)
project(shape2D)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(shape2D ${SOURCES})
```

---

## Understanding the Prompts

Upon executing `./shape2D` the user will be prompted with five options:

```terminal
~Shape Geometry: 2D Edition
[1] Circle
[2] Square      [Q] Quit
[3] Triangle
[4] Rectangle
:
```

Typing Q closes out the program.

### **Option [1]**

The user will be prompted for the circle's radius to calculate its diameter, area, and circumference.

**Example:**

```terminal
~Circle's Measurements~
Radius Length
: 3

~Circle's Geometry~
Radius -------- 3.000
Diameter ------ 6.000
Area   -------- 28.274
Circumference - 18.849
continue? [y]   [n]
: n
Bye!
```

---

### **Option [2]**

The user will be prompted for the square's side length to calculate its area and perimeter.

**Example:**

```terminal
~Square's Measurements~
Side Length
: 3

~Square's Geometry~
Side -------- 3.000
Area -------- 9.000
Perimeter --- 12.000
continue? [y]   [n]
: n
Bye!
```

---

### **Option [3]**

The user will be prompted for the triangle's base and height measurement to calculate its area and perimeter.

**Example:**

```terminal
~Triangle's Measurements~
Length of Base
: 3
Height
: 4

~Triangle's Geometry~
Base -------- 3.000
Height ------ 4.000
Area -------- 6.000
Perimeter --- 9.000
continue? [y]   [n]
: n
Bye!
```

---

### **Option [4]**

The user will be prompted for the rectangle's base and height measurement to calculate its area and perimeter.

**Example:**

```terminal
~Rectangle's Measurement~
Length of Base
: 3
Height
: 4

~Rectangle's Geometry~
Base -------- 3.000
Height ------ 4.000
Area -------- 12.000
Perimeter --- 14.000
continue? [y]   [n]
: n
Bye!
```
