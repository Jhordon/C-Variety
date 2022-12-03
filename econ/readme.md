# /econ: Personal Finance & Budget Planning

This program is designed to assist the user with planning out a workable budget based on the [50/30/20 Rule](https://www.investopedia.com/ask/answers/022916/what-502030-budget-rule.asp). The user is prompted to type in their hourly income or annual salary and the program calculates the budget sheet outputted to a `.csv` file for use in further analysis.

## How to Use

In a new terminal session:

1. After cloning into the repository via `git clone https://github.com/Jhordon/C-Variety.git`
2. Navigate to the **econ** directory via `cd econ`
3. Create a **build** folder via `mkdir build`
4. Create a **CMakeLists.txt** file via `touch CMakeLists.txt`
5. Within **CMakeLists.txt** be sure to add the code below
6. Navigate to the **build** folder via `cd build`
7. Run the command `cmake ..` to create the build files
8. Run the command `make` to create the `econ` executable file
9. Run `./econ` to execute the program

Within **CMakeLists.txt**:

```cmake
cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)
project(econ)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(econ ${SOURCES})
```

## Understanding the Output

After successful execution of `./econ` there will be a new directory titled **budgetplan** within the **build** directory. Within it, there will be two files:

**description.md**
: details the [50/30/20 Rule](https://www.investopedia.com/ask/answers/022916/what-502030-budget-rule.asp) and expenses with tax deductions

**expenses.csv**
: breaks down and outlines a budget plan from the supplied hourly income or annual salary

**Currently the program only supports After Tax deductions for the state of North Carolina. The program can still be used to create a budget plan for other states following the program prompts.**
