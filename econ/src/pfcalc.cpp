/* C++ : Personal Finance Calculator
    "Presents the user with a generalized breakdown of
    life expenses from a specified income." - @Jhordon
*/

#include "pfcalc.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

void Income::setFlag(string f) {
    flag = f;
}

void Income::setState(string s) {
    flagState = s;
}

void Income::setIncome(double x) {
    /* Based on a 40hr/wk */
   if (flag.compare("-y") == 0) {
       grossPay = x;
       hrRate = (grossPay / 2080);
       grossNeeds = (grossPay * 0.5);
       grossWants = (grossPay * 0.3);
       grossSavings = (grossPay * 0.2);
   }

   if (flag.compare("-h") == 0) {
       hrRate = x;
       grossPay = (hrRate * 2080);
       grossNeeds = (grossPay * 0.5);
       grossWants = (grossPay * 0.3);
       grossSavings = (grossPay * 0.2);
   }

   calc();
}

void Income::createFiles() {
    fs::create_directory("budgetplan");

    auto makeCSV = [&]() {
        ofstream file("budgetplan/expenses.csv");
        file << "Hourly Rate " << hrRate << "\n";
        file << "Gross Pay " << grossPay << "\n";
        file << "Gross Needs " << grossNeeds << "\n";
        file << "Gross Wants " << grossWants << "\n";
        file << "Gross Savings " << grossSavings << "\n";
        file << "Net Pay " << netPay << "\n";
        file << "Net Needs " << netNeeds << "\n";
        file << "Net Wants " << netWants << "\n";
        file << "Net Savings " << netSavings << "\n";
        file << "NC State Tax " << state << "\n";
        file << "Fica " << fica << "\n";
        file << "Federal " << federal << "\n";
        file << "Effective Tax Rate " << etr << "\n";
        file << "Tax Total for NC " << taxTotal << "\n";
        file.close();
    };

    auto makeMD = [&]() {
        ofstream file("budgetplan/description.md");
        file << "~Brief Memo: North Carolina~\n";
        file << "Your hourly rate " << "(" << hrRate << ")" << " is how much you would make per hour.\n";
        file << "Your salary " << "(" << grossPay << ")" << " is how much you would be paid in a standard year.\n";
        file << "   Based off of a 40 hour work week, that's 2,080 hours in a standard year.\n";
        file << "   You would pay a grand total of " << "(" << taxTotal << ")" << " in taxes.\n";
        file << "   7.65% toward FICA => " << fica << " + Federal Tax Amount => " << federal << " + NC Tax of 4.99% => " << state << "\n";
        file << "   FICA => Social Security 6.2% + Medicare 1.45%\n";
        file << "   Federal Effective Tax Rate => " << etr << "%\n";
        file << "   After taxes your net pay would be => " << "(" << netPay << ")\n";
        file << "Fifty percent of your salary could go towards your needs.\n";
        file << "   (i.e. rent/mortgage, car payment, groceries, insurance, health care, utilities).\n";
        file << "   Gross needs calculation => " << "(" << grossNeeds << ")\n";
        file << "   Net needs calculation => " << "(" << netNeeds << ")\n";
        file << "Thirty percent of your salary could go towards your wants.\n";
        file << "   (i.e. lifestyle expenses, events, vacations).\n";
        file << "   Gross wants calculation => " << "(" << grossWants << ")\n";
        file << "   Net wants calculation => " << "(" << netWants << ")\n";
        file << "Twenty percent of your salary could go towards your savings.\n";
        file << "   (i.e. retirement, emergency savings, debt repayments).\n";
        file << "   Gross savings calculation => " << "(" << grossSavings << ")\n";
        file << "   Net savings calculation => " << "(" << netSavings << ")\n";
        file.close();
    };

    makeCSV();
    makeMD();
    cout << "Your analysis has been generated in build/budgetplan.\n";
}

void Income::calc() {
    /*  Federal Tax Brackets: 2023 Single Filer
        RATE    Income Bracket          Tax Owed
        10%     $0 - $10,275            10% of income
        12%     $10,276 - $41,775       $1,027.50 + (12% of that > $10,275)
        22%     $41,776 - $89,075       $4,807.50 + (22% of that > $41,775)
        24%     $89,076 - $170,050      $15,213.50 + (24% of that > $89,075)
        32%     $170,051 - $215,950     $34,647.50 + (32% of that > $170,050)
        35%     $215,951 - $539,900     $49,335.50 + (35% of that > $215,950)
        37%     $539,901+               $162,718 + (37% of that > $539,900)
        
        Example:
        Making $32 an hour yields a gross pay of $66,560 putting the individual in the 22% federal tax bracket
        
        federal = (10% of $10,275) + (12% of $41,775) + ($4,807.50 + (22% > $41,775))
        federal = ($1,027.50) + ($5,013) + ($4,807.50 + $10,260.20)
        federal = $16,300.70

        effective tax rate = (federal / grosspay) * 100 rounded to two decimal places
        effective tax rate of 24% - 25%
        
        FICA = 7.65% of $66,560
        FICA = $5091.84
        
        NC Tax = 4.99% of $66,560
        NC Tax = $3,321.344

        taxTotal = fica + federal + state
        taxTotal = $5,091.84 + $16,300.70 + $3,321.344
        taxTotal = $24,713.884

        Leaving a netPay of $41,846.12
    */

   fica = (0.0765 * grossPay);
   state = (0.0499 * grossPay);

   /* Different State Tax Rates 
      if (flagState.compare("NC") == 0) {
        // North Carolina 4.99%
        state = (0.0499 * grossPay);
      } else if (flagState.compare("MD") == 0) {
        // Maryland ...
      } else if (flagState.compare("NY") == 0) {
        // prompt to ask if NYC resident as well... as there's an additional tax
      } else if (flagState.compare("VA") == 0) {
        // Virginia
      } // per each state supported
   */

    /* Federal Tax Bracket Breakdown */
    if (grossPay < 10275) {
        cout << "10% Tax Bracket Calculation...\n";
        federal = grossPay * 0.1;
        etr = (federal / grossPay) * 100;
    } else if (grossPay > 10276 && grossPay < 41775) {
        cout << "12% Tax Bracket Calculation...\n"; 
        federal = (1027.50 + ((grossPay - 10,275)) * 0.12);
        etr = (federal / grossPay);
    } else if (grossPay > 41776 && grossPay < 89075) {
        cout << "22% Tax Bracket Calculation...\n";
        federal = (1027.5 + 5013 + 4807.5 + ((grossPay - 41775) * 0.22));
        etr = (federal / grossPay) * 100; 
    } else if (grossPay > 89076 && grossPay < 170050) {
        cout << "24% Tax Bracket Calculation...\n"; 
        federal = (1027.5 + 5013 + 19596.5 + 15313.50 + ((grossPay - 89075) * 0.24));
        etr = (federal / grossPay) * 100;
    } else if (grossPay > 170051 && grossPay < 215950) {
        cout << "32% Tax Bracket Calculation...\n"; 
        federal = (1027.5 + 5013 + 19596.5 + 40812 + 34647.50 + ((grossPay - 170050) * 0.32));
        etr = (federal / grossPay) * 100;
    } else if (grossPay > 215951 && grossPay < 539900) {
        cout << "35% Tax Bracket Calculation...\n"; 
        federal = (1027.5 + 5013 + 19596.5 + 40812 + 69104 + 49335.50 + ((grossPay - 215950) * 0.35));
        etr = (federal / grossPay) * 100;        
    } else if (grossPay > 539901) {
        cout << "37% Tax Bracket Calculation...\n"; 
        federal = (1027.5 + 5013 + 19596.5 + 40812 + 69104 + 188965 + 162718 + ((grossPay - 539900) * 0.37));
        etr = (federal / grossPay) * 100;
    }

   taxTotal = fica + federal + state;
   netPay = grossPay - taxTotal;
   netNeeds = netPay * 0.5;
   netWants = netPay * 0.3;
   netSavings = netPay * 0.2;
   createFiles();
}