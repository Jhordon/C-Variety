/* C++ : Personal Finance Calculator
    "Presents the user with a generalized breakdown of
    life expenses from a specified income." - @Jhordon
*/

#include "pfcalc.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    /* Setting variables for use in program */
    double num;
    string input, f;
    vector<string> entry;
    Income userIncome;

    /* Title and dialogue */
    cout << "~Personal Finance Calculator~\n";
begin:
    cout << "Type your income followed by a specifier:\n-h hourly   -y yearly. To quit type Q.\n:";

grabEntry:
    /* Grab the typed input */
    getline(cin, input);
    if (input.empty())
    {
        cout << ":";
        goto grabEntry;
    }

    /* Parsing the input */
    stringstream line(input);

    while (line.good())
    {
        getline(line, input, ' ');
        entry.push_back(input);
    }

    try
    {
        if (entry.at(0).compare("Q") == 0 || entry.at(0).compare("q") == 0)
        {
            cout << "Bye!\n";
            exit(0);
        }
        else
        {
            if (entry.at(1) == " ")
            {
                cout << "\nFlag left blank.\n";
                entry.clear();
                goto begin;
            }
            else
            {
                f = entry.at(1);
                if (f.compare("-y") == 0 || f.compare("-h") == 0)
                {
                    try
                    {
                        num = stod(entry.at(0));
                        userIncome.setFlag(f);
                        userIncome.setIncome(num);
                    }
                    catch (exception e)
                    {
                        cout << "\nIncorrect income specified.\n";
                        entry.clear();
                        goto begin;
                    }
                }
                else
                {
                    cout << "\nIncorrect flag specified.\n";
                    entry.clear();
                    goto begin;
                }
            }
        }

        // cout << "\nYou typed:" << num << " " << f << endl;
    }
    catch (exception e)
    {
        if (entry.size() < 2 || entry.size() > 2)
        {
            entry.clear();
            goto begin;
        }
        else
        {
            entry.clear();
            goto begin;
        }
    }
}