/* C++: Sample Statistics - Object Functionality
    Generates a sample statistical analysis of a provided number list.
    'Inspired by STOR155 - FALL 2018 course content' - @Jhordon
*/

#include "stats.h"

using namespace std;

InputList::InputList(int i) {
  select(i);
}

void InputList::select(int i) {
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
                  [Retry]   [Quit]
              ---------------------------
              1 or more values are not decimals...
                  [Retry]   [Quit]
              ---------------------------
              Scan Complete.
              Would you like 'analysisResults'?
                  [y]   [n]
        */
        string input;
        cout << "~Text File Entry~\n";
        sleep(1);
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
              cout << e.what() << "\nCould not convert data value. Please format to decimal type and retry.\n";
            }
          }
          inTxt.close();
          cout << "Scan Complete.\n";
          calcStats();
        }
        else
        {
          cout << "Could not find 'data.txt'.\nMake sure the file is in the same location as the program.\nQuitting...\n";
        }
      };
      dataFile();
      getdaValues();
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
      getdaValues();
      break;
    }

    default:
    cout << "That was unexpected...\n";
    exit(1);
  }
}

void InputList::getdaValues()
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
           << "\n~~~~~~~~~~~~~~~~~~~\nPress any key to exit.\n";
      getchar();
      exit(0);
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
//     results.close();

//     std::cout << "File 'analysisResults.txt' has been created.\n";
//   } else {
//     std::cout << std::endl;
//     std::cout << "~SAMPLE STATISTICS~\n";
//     std::cout << "Minimum: " << userList.min << std::endl;
//     std::cout << "Maximum: " << userList.max << std::endl;
//     std::cout << "Mean: " << userList.mean << std::endl;
//     std::cout << "Median: " << userList.median << std::endl;
//     std::cout << "Mode: " << userList.mode << std::endl;
//     std::cout << "Sum: " << userList.sum << std::endl;
//     std::cout << "Sample Standard Deviation: " << userList.samStanDev << std::endl;
//     std::cout << "Population Standard Deviation: " << userList.popStanDev << std::endl;
//     std::cout << "Inflection Values: ";
//     for (auto i : userList.inflectVals)
//       std::cout << i << ", ";
//     std::cout << "\n~~~~~~~~~~~~~~~~\n";
//     std::cout << "Quartile 1: " << userList.q1 << std::endl;
//     std::cout << "Interquartile Range: " << userList.inQR << std::endl;
//     std::cout << "Quartile 3: " << userList.q3;
//     std::cout << "\n~~~~~~~~~~~~~~~~\n";
//     std::cout << "~OUTLIER'S & FENCES~\n";
//     std::cout << "Major Outlier's: ";
//     for (auto i : userList.majLierVals)
//       std::cout << i << ", ";
//     std::cout << "\nOuter Fence Values: ";
//     for (auto i : userList.outFenVals)
//       std::cout << i << ", ";
//     std::cout << "\nMinor Outlier's: ";
//     for (auto i : userList.minLierVals)
//       std::cout << i << ", ";
//     std::cout << "\nInner Fence Values: ";
//     for (auto i : userList.inFenVals)
//       std::cout << i << ", ";
//     std::cout << "\n~~~~~~~~~~~~~~~~\n";
//     std::cout << "~CONFIDENCE INTERVAL~\n";
//     std::cout << "Level of %: 80% 90% 95% 98% 99%\n";
//     std::cout << "Z*Values: 1.28 1.645 1.96 2.33 2.58\n";
//     std::cout << "Margin of Error: ";
//     for (auto i : userList.margsOErr)
//       std::cout << i << ", ";
//     std::cout << "\nLower Limit: ";
//     for (auto i : userList.lowLimsCI)
//       std::cout << i << ", ";
//     std::cout << "\nUpper Limit: ";
//     for (auto i : userList.highLimsCI)
//       std::cout << i << ", ";
//     std::cout << "\n~~~~~~~~~~~~~~~~\n";
//   }
// }