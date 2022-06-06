/* C++: Series
    Mathematical formulas in relation/likeness to series - @Jhordon
*/

/* 
  TODO:
    - full implementation for isDivisible() w/ basecases brilliant.org/wiki/divisibility-rules

    challenge: clear terminal after completing a fn() 
*/

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

template <typename T>
double foarial(T val) {
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
  /* '[&]() -> {}'    & => input */
  string input;

  auto permutate = [](auto& n, auto& r) -> auto {
    // auto a = n, b = r;

    // auto diff = a - b;
    // auto top = foarial(a);
    // auto bottom = foarial(diff);

    /* repeating: n^r */
    cout << "\nP(" << n << ", " << r << ") w/ Rep. => " << pow(n, r);

    /* non-repeating: n!/(n-r)! */
    cout << "\nP(" << n << ", " << r << ") w/o Rep. => " << ((foarial(n)) / foarial((n - r))) << endl;
  };

  auto combo = [](auto& n, auto& r) -> auto {
    // auto t = (r + n) - 1;
    // auto tm = (n - 1);
    // auto tb = (n - r);

    // auto top = foarial(t);
    // auto bottom = foarial(r) * foarial(tm);

    /* repeating: (r+n-1)!/r!(n-1)! */
    cout << "\nC(" << n << ", " << r << ") w/ Rep. => " << ((foarial(((r + n) - 1))) / ((foarial(r)) * (foarial((n - 1)))));

    // top = foarial(n);
    // bottom = foarial(r) * foarial(tb);

    /* non-repeating: n!/r!(n-r)! */
    cout << "\nC(" << n << ", " << r << ") w/o Rep. => " << ((foarial(n)) / ((foarial(r)) * (foarial((n - r))))) << endl;
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

  auto getNum = [&](auto& num) -> auto {
    while (input != "B" || input.compare("B") != 0 || input != "b" || input.compare("b") != 0) {
begin:
      cout << "Provide # or 'B'\n:";
      getline(cin, input);
      try {
        return stoi(input);
      } catch (...) {
        if (input == "B" || input.compare("B") == 0 || input == "b" || input.compare("b") == 0) {
          return -1;
        } else {
          goto begin;
        }
      }
    }
    return 0;
  };

  auto collatz = [&]() -> auto {
begin:
    cout << "\n~Collatz Sequence~\n";
    int n = getNum(n);
    if (n > 0 && n < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else if (n == 0) {
        goto begin;
      } else {
        goto begin;
      }
    }

sequence:
    cout << "\nStarting from " << n << ", the sequence is:\n";
    while (n != 1) {
      cout << n << " ";
      if ((n & 1) == 1) {
        n = (3 * n) + 1;
      } else {
        n = n / 2;
      }
    }
    cout << "1\n------------------\n";

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto factorial = [&]() -> auto {
begin:
    cout << "\n~Factorial~\n";
    double n = getNum(n), res = 0;
    if (n > -1 && n < 1000000000) { 
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }

sequence:
    res = foarial(n);
    cout << endl << n << "! => " << res << "\n-----------\n";

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto isDivisible = [&]() -> auto {
begin:
    cout << "\n~Divisor Check~\n";
    int n = getNum(n);
    if (n > -1 && n < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }

sequence:
    // more modifications here
    char inputString[to_string(n).length() + 1];
    strcpy(inputString, to_string(n).c_str());

    if ((n % 2) == 0)
    {
      if (((n % 2) == 0) && ((n % 3) == 0) && (inputString[strlen(inputString) - 1] == '0'))
      {
        cout << endl
             << n << " is divisible by 2, 3, 5, 6, and 10\n";
      }
      else if (((n % 2) == 0) && ((n % 3) == 0))
      {
        cout << endl
             << n << " is divisble by 2, 3, and 6\n";
      }
      else if (inputString[strlen(inputString) - 1] == '0')
      {
        cout << endl
             << n << " is divisible by 2, 5, and 10\n";
      }
      else
      {
        if (((n % 2) == 0) && ((n % 4) == 0) && ((n % 8) == 0))
        {
          cout << endl
               << n << " is divisible by 2, 4, and 8\n";
        }
        else
        {
          cout << endl
               << n << " is divisible by 2\n";
        }
      }
    }
    else
    {
      if ((n % 3) == 0)
      {
        if (((n % 3) == 0) && ((n % 4) == 0))
        {
          cout << endl
               << n << " is divisible by 3, 4, and 12\n";
        }
        else
        {
          cout << endl
               << n << " is divisible by 3\n";
        }
      }
      if (inputString[strlen(inputString) - 1] == '5')
      {
        cout << endl
             << n << " is divisible by 5\n";
      }
    }

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto ordinal = [&]() -> auto {
begin:
    cout << "\n~Ordinal~\n";
    int n = getNum(n);
    if (n > -1 && n < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }

sequence:
    char inputString[to_string(n).length() + 1];
    strcpy(inputString, to_string(n).c_str());

    if (inputString[strlen(inputString) - 1] == '1') {
      if (inputString[strlen(inputString) - 2] == '1') {
        cout << to_string(n) << "th\n";
      } else {
        cout << to_string(n) << "st\n";
      }
    } else if (inputString[strlen(inputString) - 1] == '2') {
      if (inputString[strlen(inputString) - 2] == '1') {
        cout << to_string(n) << "th\n";
      } else {
        cout << to_string(n) << "nd\n";
      }
    } else if (inputString[strlen(inputString) - 1] == '3') {
      if (inputString[strlen(inputString) - 2] == '1') {
        cout << to_string(n) << "th\n";
      } else {
        cout << to_string(n) << "rd\n";
      }
    } else {
      cout << to_string(n) << "th\n";
    }

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto triangular = [&]() -> auto {
begin:
    cout << "\n~Triangular~\n";
    int n = getNum(n);
    if (n > -1 && n < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }

sequence:
    // temp = ((8 * n) + 1);
    // x = (sqrt(temp) - 1) / 2;
    // z = (int)x;
    // next = (z * (z + 1)) / 2;
    int temp = ((8 * n) + 1), x = ((sqrt(temp) - 1) / 2), z = ((int)x), next = ((z * (z + 1)) / 2), sum = 0;
    for (unsigned int i = 0; i <= n; i++) {
      sum += i;
      if (sum == n) {
        cout << endl << n << " is triangular\n";
        break;
      }
      if (i == n) {
        cout << endl << n << " is not triangular, nearest is " << next << endl;
        break;
      }
    }

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto fibonacci = [&]() -> auto {
begin:
    cout << "\n~Fibonacci~\n";
    int n = getNum(n), aN = 0; 
    if (n > -1 && n < 46) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }

sequence:
    double phiL = ((1 + sqrt(5)) / 2), phis = ((1 - sqrt(5)) / 2);
    aN = ((pow(phiL, n) - pow(phis, n)) / sqrt(5));
    cout << "\nThe " << n << " num of F(n) => " << aN << endl;
      /*fibonacci(int n) nth select
        aN = (Phi^n - phi^n) / sqrt(5)
        Phi = (1 + sqrt(5))/2
        phi = (1 - sqrt(5))/2   // -1/Phi

        also
          F0 = 0
          F1 = 1
          Fn = Fn-1 + Fn-2 while n > 1*/
prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto partSum = [&]() -> auto {
begin:
    cout << "\n~Partial Sum~\n";
    int n = getNum(n), sum = 0;
    if (n > -1 && n < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else if (n == 0) {
        goto begin;
      } else {
        goto begin;
      }
    }

sequence:
    for (unsigned int i = 1; i <= n; i++) {
      sum += i;
    }
    cout << "\nSum from 1 to " << n << " => " << sum << endl;

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto squareSum = [&]() -> auto {
begin:
    cout << "\n~Sum of Squares~\n";
    int n = getNum(n), prod = 1, sum = 0;
    if (n > 0 && n < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else if (n == 0) {
        goto begin;
      } else {
        goto begin;
      }
    }

sequence:
    for (unsigned int i = 1; i <= n; i++)
    {
      prod = i * i;
      sum += prod;
    }
    cout << "\nSum of Squares from 1 to " << n << " => " << sum << endl;

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  auto sum2k1 = [&]() -> auto {
begin:
    cout << "\n~Sum Series: 2k+1 ~\n";
    int n = getNum(n), res = 0;
    if (n > -1 && n < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }

sequence:
    for (unsigned int i = 1; i <= n; i++) {
      res += (2 * i) + 1;
    }
    cout << "\nSum of 2k+1 from 1 to " << n << " => " << res << endl;

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };



  /*  'Sub-Menu 1'
      ~Select a Method~
          [1] Collatz     [6] Divisor Check
          [2] Factorial   [7] Partial Sum
          [3] Triangular  [8] Square Sum
          [4] Fibonacci   [9] 2k+1 Sum
          [5] Ordinal     [B] Back

      **perform related calculations upon a successful selection
  */
  auto select1 = [&]() -> auto {
    while (input != "B" || input.compare("B") != 0 || input != "b" || input.compare("b") != 0) {
subSel:
      cout << "\n~Select a Method~\n" <<
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
            goto subSel;
          }

          case 2: {
            factorial();
            goto subSel;
          }

          case 3: {
            triangular();
            goto subSel;
          }

          case 4: {
            fibonacci();
            goto subSel;
          }

          case 5: {
            ordinal();
            goto subSel;
          }

          case 6: {
            isDivisible();
            goto subSel;
          }

          case 7: {
            partSum();
            goto subSel;
          }

          case 8: {
            squareSum();
            goto subSel;
          }

          case 9: {
            sum2k1();
            goto subSel;
          }

          default:
            goto subSel;
          }
      } catch (...) {
        if (input == "B" || input.compare("B") == 0 || input == "b" || input.compare("b") == 0) {
          return;
        } else {
          goto subSel;
        }
      }
    }
  };

  /*  'Sub-Menu 2'
        ~Permutation, Combination, Binomial Coefficient~
            You typed: 'n' & 'r'

            P(n,r) w/ Rep. => 'res'
            P(n,r) w/o Rep. => 'res'

            C(n,r) w/ Rep. => 'res'
            C(n,r) w/o Rep. => 'res'

            nCk => 'res'
  */
  auto select2 = [&]() -> auto {
begin:
    cout << "\n~Permutation, Combination, Binomial Coefficient~\n";
    int n = 0, r = 0;

getN:
    n = getNum(n);
    if (n > 0 && n < 1000000000) {
      goto getR;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }
   
getR:
    r = getNum(r);
    if (r > 0 && r < 1000000000) {
      goto sequence;
    } else {
      if (n == -1) {
        return;
      } else {
        goto begin;
      }
    }

sequence:
    if (n < r) {
      cout << "Provided r: " << r << " is too large.\n";
      cout << "r: " << r << " must be < n: " << n << endl;
      goto getR;
    } else {
      cout << "\nYou typed: " << n << " & " << r;
      permutate(n, r);
      combo(n, r);
      nCk(n, r);
    }

prompt:
    cout << "Again?\n   [y] [n]\n: ";
    getline(cin, input);
    if (input.compare("y") == 0) {
      goto begin;
    } else if (input.compare("n") == 0) {
      return;
    } else {
      goto prompt;
    }
  };

  /* 'Main Menu'
        ~Series Selection~
            [1] 'One Number Input'
            [2] 'Two Number Input'
            [Q] Quit
  */
  while (input != "Q" || input.compare("Q") != 0 || input != "q" || input.compare("q") != 0) {
start:
    cout << "\n~Series Selection~\n   [1] w/ One Number\n   [2] w/ Two Numbers\n   [Q] Quit\n:";
    getline(cin, input);
    /* error check the input for expected behavior here */
    try {
      switch (stoi(input)) {
        case 1: {
          select1();
          goto start;
        }
        case 2: {
          select2();
          goto start;
        }
        default: {
          goto start;
        }
      }
    } catch (...) {
      if (input == "Q" || input.compare("Q") == 0 || input == "q" || input.compare("q") == 0) {
        exit(0);
      } else {
        goto start;
      }
    }
  }
}
