/* C++: Sample Statistics - Object Skeleton
    Generates a sample statistical analysis of a provided number list.
    'Inspired by STOR155 - FALL 2018 course content' - @Jhordon
*/

#ifndef SAMSTAT_H
#define SAMSTAT_H

#include <string>
#include <vector>

using namespace std;

/* Statistical Values:
    double sum, min, max, median, mode, popStnD, samStnD, popMean, samMean,
        iQR, q1, q3, lfInnFence, rtInnFence, lfOutFence, rtOutFence, leFlect, rtFlect

    vector daValues, zScores, majLiers, minLiers, zCoefficients, mOE, uppLimit, bttmLimit   
*/

/*   ~Manual Entry~                               2. Upon Manual Entry...
     Enter your values.                               prompt the user to provide data values,
     Type 'done' when finished.                       Error check for .empty(), !ofType<'num'>, 'done'
     :                                                'handleEntry() --> input'
     --------------------------                       Display these messages upon completion
     Numerics only please.
     --------------------------
     Calculating...
     --------------------------
     Would you like 'analysisResults'?
         [y]  [n]
 */

/*    ~Text File Entry~                            3. Upon Text File Entry...
    Searching for 'data.txt'...                       Begin a 'CURRENT DIRECTORY' search for 'data.txt'
    ---------------------------                       Print out respective messages on errors
    No file found. Quitting...
    ---------------------------
    File found...Scanning...
    ---------------------------
    File is empty.
        [Retry]   [Quit]
    ---------------------------
    1 or more values are not decimals...
        [Retry]   [Quit]
    ---------------------------
    Scan Complete.
    Would you like 'analysisResults'?
        [y]   [n]
*/

/*   ~Sample Statistics~                           4. a) Upon [n]...
    // Sum, Min, Max, Median,                              Output to the console
    // Standard Deviation & Mean                           and have escape route
        > population and sample
    // Quartile Information
    --------------------
    Press any key to exit.
*/

/*  'analysisResults' has been created in [dir]       b) Upon [y]...
    -------------------------------------------             Create .csv and .txt files in 'analysisResults'
    Press any key to exit.                                  within 'CURRENT DIRECTORY'
*/
class InputList {
    public:
        InputList();
        void setdaValues(int i);
        vector<double> getdaValues();

    private:
        double sum, min, max, median, mode, popStnD, samStnD, popMean, 
            samMean, leFlect, rtFlect, iQR, q1, q3, lfInnFence, rtInnFence,
            lfOutFence, rtOutFence;
    
        vector<double> daValues, zScores, majLiers, minLiers, mOE, uppLimit, bttmLimit;
};

#endif 
