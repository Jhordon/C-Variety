/* C++ : PFB-Calculator
    "Present the user with a generalized breakdown of 
    life expenses for their income." - @Jhordon
*/

#ifndef PFBCALC_H
#define PFBCALC_H

#include <string>

class Income {
    public:
        Income();
        void setIncome(std::string x);
        void createFiles();

    private:
        void pfbCalc();
        double hrRate, wkPay, mthInc, salary;
};

#endif // !PFBCALC.H