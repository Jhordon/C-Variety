#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// assistant functions
int factorial(int n) {
  int prod = 1;
  while (n != 0) {
    prod *= n;
    n - 1;
  }
  prod += 1;
  return prod;
}

int biCo(int n, int k) {
  if (k == n || k == 0) {
    return 1;
  }
  return (n * biCo(n-1, k-1)) / k;
}


int main() {
  // [&]() -> {} utilized for input ref.
  string input;


  // select2 => 'Two Input' Functions
  auto permutate = [](auto n, auto r, auto isRep) -> auto {
    /* repeating: n^r */
    if (isRep) {
      cout << "\nP(" << n << ", " << r << ") w/ Rep. => " << pow(n, r);
    }
    /* non-repeating: n!/(n-r)! */
    if (!isRep) {
      cout << "\nP(" << n << ", " << r << ") w/o Rep. => " << ((factorial(n)) / (factorial(n-r)));
    }
  };

  auto combo = [](auto n, auto r, auto isRep) -> auto {
    /* repeating: (r+n-1)!/r!(n-1)! */
    if (isRep) {
      cout << "\nC(" << n << ", " << r << ") w/ Rep. => " <<
        ((factorial((r + n - 1))) / (factorial(r)) * (factorial(n-1)));
    }
    /* non-repeating: n!/r!(n-r)! */
    if (!isRep) {
      cout << "C(" << n << ", " << r << ") w/o Rep. => " <<
        ((factorial(n)) / (factorial(r)) * (factorial(n-r)));
    }
  };

  auto nCk = [](auto n, auto r) -> auto {
    int res;
    while (n != 0) {
      res = biCo(n, r);

      if (n == 0 && r == n) {
        cout << "\nnCk => " << res << endl;
      }

      cout << "\nnCk => " << res << endl;
    }
  };



  // select1 => 'One Input' Functions
  auto collatz = [&]() -> auto {
    int n;
    cout << "~Collatz Sequence~\n  Provide a start # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      cout << ": ";
      getline(cin, input);
      try {
        n = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto begin;
        }
      }

      while (n != 1) {
        cout << n << " ";
        if ((n & 1) == 1) {
          n = (3 * n) + 1;
        } else {
          n = n / 2;
        }
      }
      cout << "\n------------------\n";
    }
  };

  auto factorial = [&]() -> void {
    int n, res;
    cout << "~Factorial~\n  Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      cout << ": ";
      getline(cin, input);
      try {
        n = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto begin;
        }
      }

      res = factorial(n);
      cout << n << "! => " << res;
      cout << "\n-----------\n";
    }
  };

  auto isDivisible = [&]() -> auto {
    /*isDivisible(int n)
      checks for 2-12 from brilliant.org/wiki/divisibility-rules*/
  };

  auto ordinal = [&]() -> auto {
    /*ordinal(int n)
      // follow workbench guide*/
  };

  auto triangular = [&]() -> auto {
    int n, x, z, next, sum, temp;
    cout << "~Triangular Numbers~\n  Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      cout << ": ";
      getline(cin, input);
      try {
        n = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto begin;
        }
      }

      while (n != 0) {
        temp = ((8 * n) + 1);
        x = (sqrt(temp) - 1) / 2;
        z = (int) x;
        next = (2 * (2 + 1)) / 2;

        for (int i = 1; i <= n; i++) {
          sum += i;
          if (sum == n) {
            cout << n << " is triangular\n";
          }
          if (i == n) {
            cout << n << " is not triangular, nearest is " << next << endl;
          }
        }
      }
    }
  };

  auto fibonacci = [&]() -> auto {
    int
    /*fibonacci(int n) nth select
      aN = (Phi^n - phi^n) / sqrt(5)
      Phi = (1 + sqrt(5))/2
      phi = (1 - sqrt(5))/2   // -1/Phi

      also
        F0 = 0
        F1 = 1
        Fn = Fn-1 + Fn-2 while n > 1*/
  };

  auto partSum = [&]() -> auto {
    int n, i, sum;
    cout << "~Partial Sum~\n   Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      cout << ": ";
      getline(cin, input);
      try {
        n = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto begin;
        }
      }

      for (i = 0; i < n; i++) {
        sum += i;
      }
      cout << sum << endl;
    }
  };

  auto squareSum = [&]() -> auto {
    int n, i, prod = 1, sum;
    cout << "~Sum of Squares~\n  Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      cout << ": ";
      getline(cin, input);
      try {
        n = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto begin;
        }
      }

      for (i = 1; i < n; i++) {
        prod = i * i;
        sum += prod;
      }

      cout << "The Sum of Squares from 1 to " << n << " => " << sum << endl;
    }
  };

  auto sum2k1 = [&]() -> auto {
    int i, n, res;
    cout << "~Sum Series: 2k+1 ~\n   Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      cout << ": ";
      getline(cin, input);
      try {
        n = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto begin;
        }
      }

      for (i = 1; i < n; i++) {
        res = (2 * i) + 1;
      }

      cout << "From 1 to " << n << " => " << res << endl;
    }
  };


  /*  3rd Entry Point:
      ~Series Selection: Select a Method~
          [1] Collatz     [5] Divisor Check
          [2] Factorial   [6] Partial Sum
          [3] Triangular  [7] Square Sum
          [4] Fibonacci   [8] 2k+1 Sum
          [Q] Quit        [9] Ordinal

      perform related calculations upon successful selection
  */
  auto select1 = [&]() -> auto {
    while (input != "B" || input.compare("B") != 0) {
subSel:
      cout << "~Series Selection: Select a Method~\n" <<
              "   [1] Collatz     [6] Divisor Check\n" <<
              "   [2] Factorial   [7] Partial Sum\n" <<
              "   [3] Triangular  [8] Square Sum\n" <<
              "   [4] Fibonacci   [9] 2k+1 Sum\n" <<
              "   [5] Ordinal     [B] Back\n:";
        getline(cin, input);
        try {
          switch(stoi(input)) {
            case 1: {
              collatz();
            }

            case 2: {
              factorial();
            }

            case 3: {
              triangular();
            }

            case 4: {
              fibonacci();
            }

            case 5: {
              ordinal();
            }

            case 6: {
              isDivisible();
            }

            case 7: {
              partSum();
            }

            case 8: {
              squareSum();
            }

            case 9: {
              sum2k1();
            }

            default:
              break;
          }
        } catch (...) {
          if (input == "B" || input.compare("B") == 0) {
            break;
          } else {
            goto subSel;
          }
        }
    }
  };

  /*  2nd Entry Point:
        ~Series Selection: Permutation/Combination~
            You typed: 'n' & 'r'

            P(n,r) w/ Rep. => 'res'
            P(n,r) w/o Rep. => 'res'

            C(n,r) w/ Rep. => 'res'
            C(n,r) w/o Rep. => 'res'

            nCk => 'res'
  */
  auto select2 = [&]() -> auto {
    int n, r;
    while (input != "B" || input.compare("B") != 0) {
      cout << "~Series Selection: Permutation/Combination~\n Provide 'N' & 'R' values or 'B' for back.\n";
getN:
      cout << "'N' value\n:";
      getline(cin, input);
      try {
        n = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto getN;
        }
      }
getR:
      cout << "'R' value\n:";
      getline(cin, input);
      try {
        r = stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto getR;
        }
      }

      cout << "You typed: " << n << " & " << r << endl;
      permutate(n, r, true);
      permutate(n, r, false);
      combo(n, r, true);
      combo(n, r, false);
      nCk(n, r);
    }
  };

  /*   1st Entry Point:
        ~Series Selection~
            [1] 'One Number Input'
            [2] 'Two Number Input'
            [Q] Quit
  */
  while (input != "Q" || input.compare("Q") != 0) {
start:
    cout << "~Series Selection~\n   [1] w/ One Number\n   [2] w/ Two Numbers\n   [Q] Quit\n:";
    getline(cin, input);
    // error check the input for expected behavior
    try {
      switch (stoi(input)) {
        case 1: {
          select1();
          break;
        }
        case 2: {
          select2();
          break;
        }
        default: {
          break;
        }
      }
    } catch (...) {
      if (input == "Q" || input.compare("Q") == 0) {
        exit(0);
      } else {
        goto start;
      }
    }
  }
}
