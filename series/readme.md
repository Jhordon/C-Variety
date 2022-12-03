# /series: Fun w/ Math

This program houses various mathematical formulas resembling the likeness of a series operation. The user can operate with one number supplied or two numbers supplied into the query. The program offers prompts for the user to follow to initiate sub operations.

**One Number Operations:**

- Collatz Sequence
- Factorial
- Triangular Number
- Fibonacci Sequence
- Ordinal Check
- Divisor Check
- Partial Sum
- Square Sum
- 2k+1 Sum

**Two Number Operations:**

- Permutation
- Combination
- Binomial Coefficient

---

## Sample Prompts

Main Menu:

```terminal
~Series Selection~
    [1] w/ One Number
    [2] w/ Two Numbers
    [Q] Quit
:
```

Sub Menu [1]:

```terminal
~Select a Method~
   [1] Collatz     [6] Divisor Check
   [2] Factorial   [7] Partial Sum
   [3] Triangular  [8] Square Sum
   [4] Fibonacci   [9] 2k+1 Sum
   [5] Ordinal     [B] Back
:
```

Sub Menu [2]:

```terminal
~Permutation, Combination, Binomial Coefficient~
Provide # or 'B'
:
```

---

## Terminal Testing

After running `git clone https://github.com/Jhordon/C-Variety.git`, navigate to the **series** directory via `cd series` and run the following command `g++ -o [nameOfExecutable] [nameOfFile].cpp`.

Example:

```terminal
g++ -o series main.cpp
```

Creates an executable **series** from file `main.cpp`. To run the **[nameOfExecutable]**, run the following command `./[nameOfExecutable]`.

Example:

```terminal
./series
```
