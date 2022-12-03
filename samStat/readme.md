# /samStat: Sample Statistics

This program generates statistical data relating to a list of supplied numbers. The program can read in data from a **data.txt** file or read in data from manually typed entries. There is an option to output the results to a directory titled **analysisResults** that houses two files:

analysis.txt
: a description of the data and how to interpret

data.csv
: an excel compatible document housing the resulting values from the calculation

## How to Use

In a terminal session:

1. After cloning into the repository via `git clone https://github.com/Jhordon/C-Variety.git`
2. Navigate to the **samStat** directory via `cd samStat`
3. Create a **build** folder via `mkdir build`
4. Create a **CMakeLists.txt** file via `touch CMakeLists.txt`
5. Within **CMakeLists.txt** be sure to add the code below
6. Navigate to the **build** folder via `cd build`
7. Run the command `cmake ..` to create the build files
8. Run the command `make` to create the `stats` exectuable file
9. Run `./stats` to execute the program

Within **CMakeLists.txt** add the following:

```cmake
cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)
project(stats)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(stats ${SOURCES})
```

---

## Sample Walkthrough

If reading in data from **data.txt**, be sure it is within the **build** directory and the values are separated by a space.

```terminal
~Sample Statistics~
[1] Use data.txt
[2] Manual Entry
[Q] Quit
: 2

~Manual Entry~
Enter your values.
Type 'done' when finished.
:23
:34
:34
:76
:-12
:done
Calculating...
Would you like 'analysisResults'?
  [y]   [n]
> n
~Sample Statistics~
Min -12   Max 76
Q1 23    Mean 31
Median 34    IQR 11
Q3 34    Sum 155

Population Std Dev 28.1283
Sample Std Dev 31.4484
~~~~~~~~~~~~~~~~~~~
```

```terminal
~Sample Statistics~
[1] Use data.txt
[2] Manual Entry
[Q] Quit
: 2

~Manual Entry~
Enter your values.
Type 'done' when finished.
:-12
:23
:73
:34
:done
Calculating...
Would you like 'analysisResults'?
  [y]   [n]
> y
'analysisResults' created in samStat/build
```
