/* C++: Sample Statistics 
    Generates a sample statistical analysis of a provided number list.
    'Inspired by STOR155 - FALL 2018 course content' - @Jhordon
*/

#include "stats.h"
#include <iostream>

using namespace std;

int main() {
    /*  ~Sample Statistics~                          1. Menu Prompt
        [1] Use data.txt                                 On associated key entry, proceed action
        [2] Manual Entry                                 'Nothing' should happen on alternate entries
        [Q] Quit
    */
   string input;

   while (input != "Q") {
       cout << "~Sample Statistics~\n[1] Use data.txt\n[2] Manual Entry\n[Q] Quit\n: ";
       getline(cin, input);
       if (input.compare("1") == 0) {
           InputList data(1);
       } else if (input.compare("2") == 0) {
           InputList data(2);
       } else if (input.compare("Q") == 0) {
           cout << "Bye!\n";
       } else {
           cout << ": ";
       }
   }
   return 0;
}