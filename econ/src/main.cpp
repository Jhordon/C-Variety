/* C++ : PFB-Calculator
    "Present the user with a generalized breakdown of
    life expenses for their income." - @Jhordon
*/

#include "pfbcalc.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    double num;
    string input, f;
    vector<string> entry;
    Income userIncome;

    cout << "~PFB-Calculator~\n";
    begin:
    cout << "Type your income followed by a specifier:\n-h hourly  -w weekly  -m monthly  -y yearly\n:";
    
    grabEntry:
    getline(cin, input);
    if (input.empty()) {
        cout << ":";
        goto grabEntry;
    }

    stringstream line(input);

    while (line.good()) {
        getline(line, input, ' ');
        entry.push_back(input);
    }

    try {
        if (entry.at(0).compare("Q") == 0) {
            exit(0);
        } else {
            if (entry.at(1) == " ") {
                cout << "\nFlag left blank.\n";
                entry.clear();
                goto begin;
            } else {
                f = entry.at(1);
                if (f.compare("-y") == 0 || f.compare("-m") == 0 || f.compare("-w") == 0 || f.compare("-h") == 0) {
                    try {
                        num = stod(entry.at(0));
                        userIncome.setFlag(f);
                        userIncome.setIncome(num);
                    } catch (exception e) {
                        cout << "\nIncorrect income specified.\n";
                        entry.clear();
                        goto begin;
                    }
                } else {
                    cout << "\nIncorrect flag specified.\n";
                    entry.clear();
                    goto begin;
                }
            }
        }

        cout << "\nYou typed:" << num << " " << f << endl;
    } catch (exception e) {
        if (entry.size() < 2 || entry.size() > 2) {
            entry.clear();
            goto begin;
        } else {
            entry.clear();
            goto begin;
        }
    }
}