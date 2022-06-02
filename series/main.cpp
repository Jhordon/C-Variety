/* C++: Series
    Mathematical formulas resembling series or likeness of - @Jhordon
*/

/* NOTE: some errors occur when certain inputs are either
    less than 'n'
    over a certain input length
    cause crash/faults...
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double foarial(double val) {
  double prod = 1;
  for (unsigned int i = val; i > 0; i--) {
    prod *= i;
  }
  return prod;
}

int biCo(int n, int k) {
  if (k == n || k == 0) {
    return 1;
  }
  return (n * biCo(n-1, k-1)) / k;
}


int main() {
  /* '[&]() -> {}' utilized for input ref. across lambda fn()'s */
  string input;

  auto permutate = [](auto& n, auto& r) -> auto {
    auto a = n, b = r;

    auto diff = a - b;
    auto top = foarial(a);
    auto bottom = foarial(diff);

    /* repeating: n^r */
    cout << "\nP(" << a << ", " << b << ") w/ Rep. => " << pow(a, b);

    /* non-repeating: n!/(n-r)! */
    cout << "\nP(" << a << ", " << b << ") w/o Rep. => " << (top / bottom) << endl;
  };

  auto combo = [](auto& n, auto& r) -> auto {
    auto t = (r + n) - 1;
    auto tm = (n - 1);
    auto tb = (n - r);

    auto top = foarial(t);
    auto bottom = foarial(r) * foarial(tm);

    /* repeating: (r+n-1)!/r!(n-1)! */
    cout << "\nC(" << n << ", " << r << ") w/ Rep. => " << (top / bottom);

    top = foarial(n);
    bottom = foarial(r) * foarial(tb);

    /* non-repeating: n!/r!(n-r)! */
    cout << "\nC(" << n << ", " << r << ") w/o Rep. => " << (top / bottom) << endl;
  };

  auto nCk = [](auto& n, auto& r) -> auto {
    int res;
    while (n != 0) {
      res = biCo(n, r);

      if (n == 0 && r == n) {
        cout << "\nnCk => " << res << endl;
        break;
      }

      cout << "\nnCk => " << res << endl;
      break;
    }
  };


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
      cout << "1\n------------------\n";
    }
  };

  auto factorial = [&]() -> void {
    double n, res;
    cout << "~Factorial~\n  Provide a # or 'B'\n";
    // potentially surround this in a function? 
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

      res = foarial(n);
      cout << n << "! => " << res;
      cout << "\n-----------\n";
    }
  };

  // needs implementation
  auto isDivisible = [&]() -> auto {
    /*isDivisible(int n)
      checks for 2-12 from brilliant.org/wiki/divisibility-rules*/
  };

  // needs implementation
  auto ordinal = [&]() -> auto {
    /*ordinal(int n)
      // follow workbench guide*/
  };

  auto triangular = [&]() -> auto {
    // may need optimization/reduction
    int n, x, z, next, sum, temp;
    cout << "~Triangular Numbers~\n  Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      sum = 0;
      temp = 0;
      x = 0;
      z = 0;
      n = 0;
      next = 0;
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

      temp = ((8 * n) + 1);
      x = (sqrt(temp) - 1) / 2;
      z = (int) x;
      next = (z * (z + 1)) / 2;
      
      for (unsigned int i = 1; i <= n; i++) {
        sum += i;
        if (sum == n) {
          cout << n << " is triangular\n";
          break;
        }
        if (i == n) {
          cout << n << " is not triangular, nearest is " << next << endl;
          break;
        }
      }
    }
  };

  auto fibonacci = [&]() -> auto {
    // perhaps a modification here...
    double n, aN, phiL, phis;
    cout << "~Fibonacci Sequence~\n  Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      cout << ": ";
      getline(cin, input);
      try {
        n = stoi(input);
      }
      catch (...) {
        if (input == "B" || input.compare("B") == 0) {
          break;
        } else {
          goto begin;
        }
      }

      phiL = (1 + sqrt(5)) / 2;
      phis = (1 - sqrt(5)) / 2;

      aN = ((pow(phiL, n) - pow(phis, n)) / sqrt(5));
      cout << aN << endl;
    }
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
    cout << "~Partial Sum~\n   Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      double n = 0, sum = 0;
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

      for (unsigned int i = 1; i <= n; i++) {
        sum += i;
      }
      cout << sum << endl;
    }
  };

  auto squareSum = [&]() -> auto {
    int n, prod, sum;
    cout << "~Sum of Squares~\n  Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      prod = 1;
      sum = 0;
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

      for (unsigned int i = 1; i <= n; i++) {
        prod = i * i;
        sum += prod;
      }

      cout << "The Sum of Squares from 1 to " << n << " => " << sum << endl;
    }
  };

  auto sum2k1 = [&]() -> auto {
    int n, res;
    cout << "~Sum Series: 2k+1 ~\n   Provide a # or 'B'\n";
    while (input != "B" || input.compare("B") != 0) {
begin:
      res = 0;
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

      for (unsigned int i = 1; i <= n; i++) {
        res += (2 * i) + 1;
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
            break;
          }

          case 2: {
            factorial();
            break;
          }

          case 3: {
            triangular();
            break;
          }

          case 4: {
            fibonacci();
            break;
          }

          case 5: {
            ordinal();
            break;
          }

          case 6: {
            isDivisible();
            break;
          }

          case 7: {
            partSum();
            break;
          }

          case 8: {
            squareSum();
            break;
          }

          case 9: {
            sum2k1();
            break;
          }

          default:
            goto subSel;
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

      if (n < r) {
        cout << "Provided r of " << r << " is too large.\n";
        goto getN;
      } else {
        cout << "\nYou typed: " << n << " & " << r;
        permutate(n, r);
        combo(n, r);
        nCk(n, r);
        cout << endl;
      }
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
    /* error check the input for expected behavior */
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
          goto start;
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
