/* C++ : Personal Finance Calculator
    "Presents the user with a generalized breakdown of 
    life expenses from a specified income." - @Jhordon
*/

#ifndef PFCALC_H
#define PFCALC_H

#include <string>

class Income {
    public:
        void setIncome(double x);
        void setFlag(std::string f);
        void setState(std::string s);
        void createFiles();

    private:
        void calc();
        double hrRate, grossPay, grossWants, grossNeeds, grossSavings, netPay, netWants, netNeeds, netSavings, fica, federal, state, taxTotal, etr;
        std::string flag, flagState;
};

#endif