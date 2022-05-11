/* C++ : PFB-Calculator
    "Present the user with a generalized breakdown of
    life expenses for their income." - @Jhordon
*/

#include "pfbcalc.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

void Income::setFlag(string f) {
    flag = f;
}

void Income::setIncome(double x) {
    /* respective conversions 
        based on a 32 hr work week of five days
        not including holiday/vacation
    */
   if (flag.compare("-y") == 0) {
       salary = x;
       mthInc = (salary / 12);
       wkPay = (mthInc / 4);
       hrRate = (wkPay / 32);
   }

   if (flag.compare("-m") == 0) {
       mthInc = x;
       wkPay = (mthInc / 4);
       hrRate = (wkPay / 32);
       salary = (mthInc * 12);
   }

   if (flag.compare("-w") == 0) {
       wkPay = x;
       hrRate = (wkPay / 32);
       mthInc = (wkPay * 4);
       salary = (mthInc * 12);
   }

   if (flag.compare("-h") == 0) {
       hrRate = x;
       wkPay = (hrRate * 32);
       mthInc = (wkPay * 4);
       salary = (mthInc * 12);
   }
   createFiles();
}

void Income::createFiles() {
    fs::create_directory("pfBreakdown");
    auto makeCSV = [&]() {
        ofstream file("pfBreakdown/expenses.csv");
        file << salary;
        file.close();
    };

    auto makeMD = [&]() {
        ofstream file("pfBreakdown/description.md");
        file << "TEST";
        file.close();
    };

    makeCSV();
    makeMD();
}

void Income::pfbCalc() {
    /*  NC, NY cost preset calculations for:
        - food & necessity
        - *bills (ISP, electricity, propane, fuel, water/sewer, phone, streaming, insurance*(healthcare, auto))
        - taxes (SS12.4%, fed(sliding scale20%~), state .0535NC, osda/fica?, medicare2.9%) 
        - retirement contribution (10-15% gross/aftertax)
        - emergency funds (about 1k-1.5k)
        - 'fun money' (leftover)

        "500+1625 monthly 401k&Roth, 70K or more assuming 1400 rent..." -T
        "2040 hrs typical, 2080, 80hrs two weeks vacation" - T
        
        paycheck city...
        self employed pays double...
        employed normal

        Messages to Display:
        - Calculating Food & Necessiteis
        - Setting aside Emergency Funds
        - Estimating for Bills
        - Deducting proposed taxes...(ouch)
        - Factoring Returment Contribution
        - Final crunch for 'fun money'
        Your 'pfBreakdown' has been created. You can find it at (path)
    */
    createFiles();
}