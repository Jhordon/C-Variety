/* C++ : PFB-Calculator
    "Present the user with a generalized breakdown of
    life expenses for their income." - @Jhordon
*/

#include "pfbcalc.h"
#include <iostream>

using namespace std;

int main() {
    string input;
    Income userIncome;
    
    cout << "~PFB-Calculator~\n";
    cout << "Type your total income followed by a specifier:\n-h hourly  -w weekly  -m monthly  -y yearly\n:";
    
    while (input.empty()) {
        getline(cin, input);
        try {
            userIncome.setIncome(input);
        } catch (exception e) {
            if (input.empty()) {
                cout << ":";
            }
        }
    }
}