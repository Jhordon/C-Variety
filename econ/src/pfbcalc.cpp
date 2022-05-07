/* C++ : PFB-Calculator
    "Present the user with a generalized breakdown of
    life expenses for their income." - @Jhordon
*/

#include "pfbcalc.h"
#include <iostream>

using namespace std;

/* class Income {}

    'yearly', 'monthly', 'weekly', or 'hourly'
    respective conversions ^

    NC, NY cost preset calculations for:
        - food & necessity
        - *bills (ISP, energy, water/sewer, phone, auto, streaming)
        - taxes (SS, fed, state, additional)
        - retirement contribution (the percentage)
        - emergency funds
        - 'fun money'

    'pfBreakdown'
        - personalFinance.csv
        - analysis.txt || .pdf || .md
*/

Income::Income() {

}

void Income::setIncome(string x) {
    cout << "Provided: " << x;
}

void Income::createFiles() {

}

void Income::pfbCalc() {

}