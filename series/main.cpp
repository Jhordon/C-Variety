#include <iostream>

using namespace std;

int main() {
    /* Multiple Function Calls in a loop statement

    1st Entry Point:
        ~Series Selection~
            [1] One Number Input
            [2] Two Number Input


    Lambda Functions:
        permutate(int n, int r)
            repeating
                n^r
            non-repeating
                n!/(n-r)!

        combo(int n, int r)
            repeating
                (r+n-1)!/r!(n-1)!
            non-repeating
                n!/r!(n-r)!

        nCk(int n, int k)
            if (k == n || k == 0)
                return 1
            return (n*nCk(n-1,k-1))/k

            ...if (n==0&&k==n) << 'res' break
            'res' normally
    
    Used in 2nd Entry Point:
        [2]~Series Selection: Permutation/Combination~
            You typed: 'n' & 'r'

            P(n,r) w/ Rep. => 'res'
            P(n,r) w/o Rep. => 'res'

            C(n,r) w/ Rep. => 'res'
            C(n,r) w/o Rep. => 'res'

            nCk => 'res'
    

    Lambda Functions:
      collatz(int n)
        while (n != 1)
            if (n & 1) == 1
                n = (3n) + 1
            else 
                n = n/2

      isDivisible(int n)
        checks for 2-12 from brilliant.org/wiki/divisibility-rules

      factorial(int n)
            while (n != 0)
                prod *= n
                n - 1
            prod += 1

      ordinal(int n)
        // follow workbench guide

      triangular(int n)
        while (n != 0)
            temp = ((8n) + 1)
            x = (sqrt(temp) - 1)/2
            z = (int)x
            next = (2(2+1)) / 2

            for (i = 1 <= n)
                sum += i
                if sum == n
                    'isTri'
                if i == n
                    !'isTri' << 'next'

      fibonacci(int n) nth select
        aN = (Phi^n - phi^n) / sqrt(5)
        Phi = (1 + sqrt(5))/2
        phi = (1 - sqrt(5))/2   // -1/Phi

        also 
          F0 = 0
          F1 = 1
          Fn = Fn-1 + Fn-2 while n > 1


      partSum(int n)
        for (i = 0 < n)
            sum += i

      sqaureSum(int n)
        for (i = 1 < n) 
            prod = i * i
            sum += prod

      2k+1 Series()
        for (i = 1 < n)
            res = (2i) + 1

    Used in 3rd Entry Point:
        [1]~Series Selection: Select a Method~
            [1] Collatz     [5] Divisor Check
            [2] Factorial   [6] Partial Sum
            [3] Triangular  [7] Square Sum
            [4] Fibonacci   [8] 2k+1 Sum
            [Q] Quit        [9] Ordinal
    
        [1.5]~Selected: 'Method'~
            You typed: 'n'

            'Method' => 'res'
    */
}