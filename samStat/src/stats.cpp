/* C++: Sample Statistics - Object Functionality
    Generates a sample statistical analysis of a provided number list.
    'Inspired by STOR155 - FALL 2018 course content' - @Jhordon
*/

#include "stats.h"
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

InputList::InputList(int i) {
  cwd = fs::current_path();
  selection(i);
}

void InputList::selection(int i) {
  switch (i) {
    case 1: {
      auto dataFile = [&]()
      {
        /*    ~Text File Entry~                            3. Upon Text File Entry...
              Searching for 'data.txt'...                       Begin a 'CURRENT DIRECTORY' search for 'data.txt'
              ---------------------------                       Print out respective messages on errors
              No file found. Quitting...
              ---------------------------
              File found...Scanning...
              ---------------------------
              File is empty.
                  [R] Retry  [Q] Quit
              ---------------------------
              1 or more values are not decimals...
                  [R] Retry  [Q] Quit
              ---------------------------
              Scan Complete.
              Would you like 'analysisResults'?
                  [y]   [n]
        */
        string input;
        cout << "~Text File Entry~\n";
        cout << "Searching for 'data.txt' in " << cwd << "\n";
        sleep(1);

        for (const auto & entry : fs::directory_iterator(cwd)) {
          if (fs::exists("data.txt")) {
            begin:
            cout << "File found...Scanning...\n";
            ifstream inTxt("data.txt");
            if (inTxt.is_open())
            {
              getline(inTxt, input);
              stringstream line(input);
              while (line.good())
              {
                string value;
                getline(line, value, ' ');
                try
                {
                  daValues.push_back(stod(value));
                }
                catch (exception e)
                {
                  sleep(1);
                  cout << e.what() << "\nFile is either empty or has a non-decimal value present.\n   [R] Retry   [Q] Quit\n:";
                  while (input != "R" || input != "Q") {
                    getline(cin, input);
                    if (input.compare("R") == 0)
                    {
                      goto begin;
                    }
                    else if (input.compare("Q") == 0)
                    {
                      return;
                    }
                    else
                    {
                      cout << ":";
                    }
                  }
                }
              }
              inTxt.close();
              cout << "Scan Complete.\n";
              calcStats();
              break;
            }
          } else {
            cout << "No file found. Quitting...\n";
            return;
          }
        }
      };
      dataFile();
      printSample();
      break;
    }  

    case 2: {
      auto manEntry = [&]()
      {
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
        string input;
        cout << "~Manual Entry~\nEnter your values.\nType 'done' when finished.\n";
        while (input != "done")
        {
          cout << ":";
          try
          {
            getline(cin, input);
            daValues.push_back(stod(input));
          }
          catch (exception e)
          {
            if (input.compare("done") == 0)
            {
              cout << "Calculating...\n";
              calcStats();
              break;
            }
            else
            {
              cout << e.what() << "\nNumerics only please.\n";
            }
          }
        }
      };
      manEntry();
      printSample();
      break;
    }

    default:
    cout << "That was unexpected...\n";
    return;
  }
}

void InputList::printSample()
{
  string input;
  while (input != "y" || input != "n")
  {
    cout << "Would you like 'analysisResults'?\n  [y]   [n]\n> ";
    getline(cin, input);
    if (input.compare("y") == 0)
    {
      /*  'analysisResults' created in 'CURRENT DIRECTORY'      4. a) Upon [y]...
          Press any key to exit.                                       Create 'analysisResults' w/ .csv & .txt of InputList within 'CURRENT DIRECTORY'
      */
     analysisResults();
     return;
    }
    else if (input.compare("n") == 0)
    {
      /*  ~Sample Statistics~            b) Upon [n]...output to console
          Min --    Max --
          Q1 --     Mean --
          Median -- IQR --
          Q3 --     Sum --

          Population Std Dev ----
          Sample Std Dev ----
          ~~~~~~~~~~~~~~~~~~
          Press any key to exit.
      */
      cout << "~Sample Statistics~\nMin " << min << "   Max " << max << "\nQ1 " << q1 << "    Mean " << mean
           << "\nMedian " << median << "    IQR " << iQR << "\nQ3 " << q3 << "    Sum " << sum
           << "\n\nPopulation Std Dev " << popStnD << "\nSample Std Dev " << samStnD
           << "\n~~~~~~~~~~~~~~~~~~~\n";
      return;
    }
    else
    {
      cout << "  [y]   [n]\n> ";
    }
  }
}

void InputList::calcStats() {
  // sort daValues small to large
  sort(daValues.begin(), daValues.end());

  min = daValues.at(0);
  max = daValues.at(daValues.size() - 1);

  for (auto val : daValues)
    sum += val;

  mean = sum / daValues.size();

  /* Median
      if size is odd
        divide size in half take the left
      if size is even
        divide size in half
        take left and right
        avg the two
  */
  auto findMedian = [&](vector<double> x)
  {
    if (x.size() % 2 == 1)
    {
      return x[floor(x.size() / 2)];
    }
    else
    {
      return (x.at(ceil(x.size() / 2)) + x.at(floor(x.size() / 2))) / 2;
    }
  };
  median = findMedian(daValues);

  /* Standard Deviation
      find mean, find each scores deviation from the mean,
      sum the squares of the deviations,
      square root the variance
  */
  auto findStdDev = [&]()
  {
    vector<double> deviations;
    double sumOfSquares = 0;
    double sampleV = 0;
    double populationV = 0;

    for (auto val : daValues)
    {
      deviations.push_back(val - mean);
    }

    for (auto i : deviations)
    {
      sumOfSquares += (i * i);
    }

    /* for a sample variance, sample stdDev */
    sampleV = sumOfSquares / (daValues.size() - 1);
    samStnD = sqrt(sampleV);

    /* for a population variance, population stdDev */
    populationV = sumOfSquares / daValues.size();
    popStnD = sqrt(populationV);
  };
  findStdDev();

  /* Mode */
  auto findMode = [&]()
  {
    int count = 1;
    int max = 0;
    mode = daValues.at(0);
    for (int i = 0; i < daValues.size() - 1; i++)
    {
      if (daValues[i] == daValues[i + 1])
      {
        count++;
        if (count > max)
        {
          max = count;
          mode = daValues[i];
        }
      }
      else
      {
        count = 1;
      }
    }
  };
  findMode();

  /* Outliers
      first find the interquartile range,
      calculate your inner and outer fence values,
      if any of the values fall outside the fence,
      it is classified as a major/minor outlier
  */
  auto findOutliers = [&]()
  {
    vector<double> lowBound;
    vector<double> uppBound;
    vector<double>::iterator middle(daValues.begin() + daValues.size() / 2);

    for (auto i = daValues.begin(); i != daValues.end(); i++)
    {
      if (distance(i, middle) > 0)
      {
        lowBound.push_back(*i);
      }
      else
      {
        uppBound.push_back(*i);
      }
    }

    q1 = findMedian(lowBound);
    q3 = findMedian(uppBound);
    iQR = q3 - q1;
    lfInnFence = (q1 - (iQR * 1.5));
    rtInnFence = (q3 + (iQR * 1.5));
    lfOutFence = (q1 - (iQR * 3));
    rtOutFence = (q3 + (iQR * 3));

    for (auto i : daValues)
    {
      if (i < lfOutFence || i > rtOutFence)
      {
        majLiers.push_back(i);
      }
      else
      {
        if (i > lfOutFence && i < lfInnFence)
        {
          minLiers.push_back(i);
        }
        if (i > rtInnFence && i < rtOutFence)
        {
          minLiers.push_back(i);
        }
      }
    }
  };
  findOutliers();

  /* Confidence Interval
        the user is provided with
        80%, 90%, 95%, 98%, 99% confidence levels w/ coefficients
        which are then used to
        calculate the margin of error associated with the mean of 'values'
        "confidence interval = mean +- margin of error"
    */
  auto findCofInt = [&]() {
      // confidence level = {80%, 90%, 95%, 98%, 99%}
      vector<double> zVal = {1.28, 1.645, 1.96, 2.33, 2.58};

      for (auto i = zVal.begin(); i != zVal.end(); i++) {
        mOE.push_back((*i * popStnD) / sqrt(daValues.size()));
      }
      for (auto i : mOE) {
        bttmLimit.push_back(mean - i);
        uppLimit.push_back(mean + i);
      }
    };
  findCofInt();

  /* Z-Score List */
  auto findZ = [&]() {
    double z = 0;
    for (auto value : daValues) {
      z = (value - mean) / popStnD;
      zScores.push_back(z);
    }
  };
  findZ();

  leFlect = mean - popStnD;
  rtFlect = mean + popStnD;
}

void InputList::analysisResults() {
  fs::create_directory("analysisResults");
  auto makeCSV = [&]()
  {
    ofstream file("analysisResults/data.csv");
    file << "Values,";
    for (auto it : daValues) 
      file << it << ",";
    
    file << "\nZ-Scores,";
    for (auto it : zScores)
      file << it << ",";

    file << "\nMajor Outliers,";
    for (auto it : majLiers)
      file << it << ",";

    file << "\nMinor Outliers,";
    for (auto it : minLiers) 
      file << it << ",";

    file << "\nSum," << sum
         << "\nMin," << min
         << "\nMax," << max
         << "\nMean," << mean
         << "\nMedian," << median
         << "\nMode," << mode
         << "\nPopulation Standard Deviation," << popStnD
         << "\nSample Standard Deviation," << samStnD
         << "\nLeft Inflection," << leFlect
         << "\nRight Inflection," << rtFlect
         << "\nInter-Quartile Range," << iQR
         << "\nQuartile 1," << q1
         << "\nQuartile 3," << q3
         << "\nLeft Inner Fence," << lfInnFence
         << "\nRight Inner Fence," << rtInnFence
         << "\nLeft Outer Fence," << lfOutFence
         << "\nRight Outer Fence," << rtOutFence;

    file << "\nConfidence Level, 80%, 90%, 95%, 98%, 99%";
    vector<double> zVal = {1.28, 1.645, 1.96, 2.33, 2.58};
    file << "\nConfidence Coefficient,";
    for (auto it : zVal) 
      file << it << ",";

    file << "\nMargin of Error,";
    for (auto it : mOE) 
      file << it << ",";

    file << "\nLower Bound CI,";
    for (auto it : bttmLimit)
      file << it << ",";

    file << "\nUpper Bound CI,";
    for (auto it : uppLimit)
      file << it << ",";
  };

  auto makeTXT = [&]()
  {
    ofstream file("analysisResults/analysis.txt");
    file << "The SUM represents the total of all values.\nThe MIN, MEDIAN, and MAX values assist in distinguishing spread of data as well as MODE representing most frequent data values.\n";
    file << "The Inter-Quartile Range or IQR represents the middle spread of data with Q1 and Q3 assisting to further separate and distinguish boundaries.\n";
    file << "Inflection values leFlect/rtFlect are verbatim, the points that assist in indicating concave/convex curving.\n";
    file << "The Outliers represented by Major/Minor are determined by the Inner and Outer Fences found from IQR.\n";
    file << "Standard Deviation assists in determining dispersion of the mean across the values. Population for an entirety of a set, and sample for a selection of the population.\n";
    file << "Z-Scores alongside the Values are presented which assist in determining how far off from the mean the value is when standardized.\n";
    file << "The Confidence Interval Calculation with respective Margin of Error and Upper/Lower Limits are provided for use in further analysis...\n";
  };

  makeCSV();
  makeTXT();
  if (fs::exists("analysisResults")) 
    cout << "'analysisResults' created in " << cwd << "\n";
}





















/* showStats of userList
      Essential Mechanism:
    if cOut2Txt is true then open a file 'analysisResults.txt'
    if cOut2Txt is false then standard output to std::cout
*/
// void inputList :: showStats(std::vector<double> values) {
//   if (userList.cOut2Txt == true) {
//     std::ofstream results ("analysisResults.txt");
//     results << "~SAMPLE STATISTICS: ANALYSIS~\n";
//     results << "The provided list has been sorted: Smallest ----> Largest\n";
//     for (auto i : userList.values)
//       results << i << ", ";
//     results << "\n\n";
//     results << "The associated Z-Score Values:\n";
//     for (auto i : userList.zScoVals)
//       results << i << ", ";
//     results << "\n\n\n";

//     results << "The MINIMUM value is " << userList.min << " and the MAXIMUM value is " << userList.max << "\n";
//     results << "The SUM of the list is " << userList.sum << " and the AVERAGE/MEAN is " << userList.mean << "\n";
//     results << "The MEDIAN value is " << userList.median << " and the MODE is " << userList.mode << "\n";
//     results << "The SAMPLE STANDARD DEVIATION is " << userList.samStanDev << " and the POPULATION STANDARD DEVIATION is " << userList.popStanDev << "\n\n\n";

//     results << "QUARTILE ONE is " << userList.q1 << " and QUARTILE THREE is " << userList.q3 << " with an INTERQUARTILE RANGE of " << userList.inQR << "\n";
//     results << "The OUTER FENCE values are ";
//     for (auto i : userList.outFenVals)
//       results << i << ", ";
//     results << "and the INNER FENCE values are ";
//     for (auto i : userList.inFenVals)
//       results << i << ", ";
//     results << "with INFLECTIONS at ";
//     for (auto i : userList.inflectVals)
//       results << i << " ";
//     results << "\n";
//     results << "The MAJOR OUTLIERS are ";
//     for (auto i : userList.majLierVals)
//       results << i << ", ";
//     results << "and the MINOR OUTLIERS are ";
//     for (auto i : userList.minLierVals)
//       results << i << ", ";
//     results << "\n\n\n";

//     results << "Confidence Intervals\n\n";
//     results << "Level of Percent     80%   90%   95%   98%   99%\n";
//     results << "Z* Coefficients     1.28  1.645 1.96  2.33  2.58\n";
//     results << "Margin of Error     ";
//     for (auto i : userList.margsOErr)
//       results << i << ",  ";
//     results << "\nLower Bound     ";
//     for (auto i : userList.lowLimsCI)
//       results << i << ",  ";
//     results << "\nUpper Bound     ";
//     for (auto i : userList.highLimsCI)
//       results << i << ",  ";
