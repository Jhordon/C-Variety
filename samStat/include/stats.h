/* C++: Sample Statistics - Object Skeleton
    Generates a sample statistical analysis of a provided number list.
    'Inspired by STOR155 - FALL 2018 course content' - @Jhordon
*/

#ifndef SAMSTAT_H
#define SAMSTAT_H

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <filesystem>

/* Statistical Values Attributed to List:
    - Sum, Minimum, Maximum, Mean, Median, Mode, 
    - Population Standard Deviation, Sample Standard Deviation,
    - Inter Quartile Range, Quartile 1, Quartile 3,
    - Inflection & Fence Values, Outliers, 
    - Z-Score's, Calculated Confidence Interval(s)   
*/
class InputList {
    public:
        InputList(int i);
        void select(int i);
        void getdaValues();

    private:
    // 'CURRENT DIRECTORY'
        void calcStats();
        double sum, min, max, median, mode, popStnD, samStnD, mean, leFlect, rtFlect, iQR, q1, q3,
         lfInnFence, rtInnFence, lfOutFence, rtOutFence;
    
        std::vector<double> daValues, zScores, majLiers, minLiers, mOE, uppLimit, bttmLimit;
};

#endif 
