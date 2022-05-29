/* C++ : PFB-Calculator
    "Present the user with a generalized breakdown of 
    life expenses for their income." - @Jhordon
*/

#ifndef PFBCALC_H
#define PFBCALC_H

#include <string>
class Income {
    public:
        void setIncome(double x);
        void setFlag(std::string f);
        void createFiles();

    private:
        void pfbCalc();
        double hrRate, wkPay, mthInc, salary;
        std::string flag;

        // variables for all expenses and deductions to be taken out
};

#endif