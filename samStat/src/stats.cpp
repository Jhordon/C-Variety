/* C++: Sample Statistics
    Generates a sample statistical analysis of a provided number list.
    'Inspired by STOR155 - FALL 2018 course content' - @Jhordon
*/

#include "stats.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <math.h>
#include <algorithm>

/* class inputList {}
    a list object with additional
    sub-lists, data attributes, and
    publicly accessible methods that set/find the
    private stat attributes pertaining to inputList
*/
class inputList {
private:
  double min, max, median, mean, mode, sum, samStanDev, popStanDev, inQR, q1, q3;
  std::vector<double> zScoVals;
  std::vector<double> minLierVals;
  std::vector<double> majLierVals;
  std::vector<double> inflectVals;
  std::vector<double> inFenVals;
  std::vector<double> outFenVals;
  std::vector<double> lowLimsCI;
  std::vector<double> highLimsCI;
  std::vector<double> margsOErr;

public:
  bool cOut2Txt = false;
  std::vector<double> values;

  /* Median
      if size is odd
        divide size in half take the left
      if size is even
        divide size in half
        take left and right
        avg the two
  */
  double findMedian(std::vector<double> x) {
    if (x.size() % 2 == 1) {
      return x[floor(x.size() / 2)];
    } else {
      return (x.at(ceil(x.size() / 2)) + x.at(floor(x.size() / 2))) / 2;
    }
  }

  /* Standard Deviation
      find mean, find each scores deviation from the mean,
      sum the squares of the deviations,
      square root the variance
  */
  void findStdDev() {
    std::vector<double> deviations;
    double sumOfSquares = 0;
    double sampleV = 0;
    double populationV = 0;

    for (auto i : values) {
      deviations.push_back(i - mean);
    }

    for (auto i : deviations) {
      sumOfSquares += (i * i);
    }

    /* for a sample variance, sample stdDev */
    sampleV = sumOfSquares / (values.size() - 1);
    samStanDev = sqrt(sampleV);

    /* for a population variance, population stdDev */
    populationV = sumOfSquares / values.size();
    popStanDev = sqrt(populationV);
  }

  /* Mode */
  void findMode() {
    int count = 1;
    int max = 0;
    mode = values[0];
    for (int i = 0; i < values.size() - 1; i++) {
      if (values[i] == values[i + 1]) {
        count++;
        if (count > max) {
          max = count;
          mode = values[i];
        }
      } else {
        count = 1;
      }
    }
  }

  /* Outliers
      first find the interquartile range,
      calculate your inner and outer fence values,
      if any of the values fall outside the fence,
      it is classified as a major/minor outlier
  */
  void findOutliers() {
    std::vector<double> lowBound;
    std::vector<double> uppBound;
    std::vector<double>::iterator middle(values.begin() + values.size() /2);

    for (auto i = values.begin(); i != values.end(); i++) {
      if (std::distance(i, middle) > 0) {
        lowBound.push_back(*i);
      } else {
        uppBound.push_back(*i);
      }
    }

    q1 = findMedian(lowBound);
    q3 = findMedian(uppBound);
    inQR = q3 - q1;
    inFenVals.push_back(q1 - (inQR * 1.5));
    inFenVals.push_back(q3 + (inQR * 1.5));
    outFenVals.push_back(q1 - (inQR * 3));
    outFenVals.push_back(q3 + (inQR * 3));

    for (auto i : values) {
      if (i < outFenVals[0] || i > outFenVals[1]) {
        majLierVals.push_back(i);
      } else {
        if (i > outFenVals[0] && i < inFenVals[0]) {
          minLierVals.push_back(i);
        }
        if (i > inFenVals[1] && i < outFenVals[1]) {
          minLierVals.push_back(i);
        }
      }
    }
  }

  /* Confidence Interval
      the user is provided with
      80%, 90%, 95%, 98%, 99% confidence levels w/ coefficients
      which are then used to
      calculate the margin of error associated with the mean of 'values'
      "confidence interval = mean +- margin of error"
  */
  void findCofInt() {
    // confidence level = {80%, 90%, 95%, 98%, 99%}
    std::vector<double> zVal = {1.28, 1.645, 1.96, 2.33, 2.58};

    for (auto i = zVal.begin(); i != zVal.end(); i++) {
      margsOErr.push_back((*i * popStanDev) / sqrt(values.size()));
    }
    for (auto i : margsOErr) {
      lowLimsCI.push_back(mean - i);
      highLimsCI.push_back(mean + i);
    }
  }

  /* Z-Score List */
  void findZ() {
    double z = 0;
    for (auto value : values) {
      z = (value - mean) / popStanDev;
      zScoVals.push_back(z);
    }
  }

  void calcStats(std::vector<double> values);
  void showStats(std::vector<double> values);
};
inputList userList;

/* calcStats of userList
      Essential Mechanism:
    utilizing helper functions as needed,
    calculate and set the private stat attributes
    associated with userList.values
*/
void inputList :: calcStats(std::vector<double> values) {
  // sort userList.values small to large
  sort(userList.values.begin(), userList.values.end());

  userList.min = userList.values.at(0);
  userList.max = userList.values.at(userList.values.size() - 1);

  for (auto val : userList.values)
    userList.sum += val;

  userList.mean = userList.sum / userList.values.size();
  userList.median = findMedian(userList.values);
  userList.inflectVals.push_back(userList.mean - userList.popStanDev);
  userList.inflectVals.push_back(userList.mean + userList.popStanDev);

  userList.findMode();
  userList.findStdDev();
  userList.findZ();
  userList.findOutliers();
  userList.findCofInt();
}

/* showStats of userList
      Essential Mechanism:
    if cOut2Txt is true then open a file 'analysisResults.txt'
    if cOut2Txt is false then standard output to std::cout
*/
void inputList :: showStats(std::vector<double> values) {
  if (userList.cOut2Txt == true) {
    std::ofstream results ("analysisResults.txt");
    results << "~SAMPLE STATISTICS: ANALYSIS~\n";
    results << "The provided list has been sorted: Smallest ----> Largest\n";
    for (auto i : userList.values)
      results << i << ", ";
    results << "\n\n";
    results << "The associated Z-Score Values:\n";
    for (auto i : userList.zScoVals)
      results << i << ", ";
    results << "\n\n\n";

    results << "The MINIMUM value is " << userList.min << " and the MAXIMUM value is " << userList.max << "\n";
    results << "The SUM of the list is " << userList.sum << " and the AVERAGE/MEAN is " << userList.mean << "\n";
    results << "The MEDIAN value is " << userList.median << " and the MODE is " << userList.mode << "\n";
    results << "The SAMPLE STANDARD DEVIATION is " << userList.samStanDev << " and the POPULATION STANDARD DEVIATION is " << userList.popStanDev << "\n\n\n";

    results << "QUARTILE ONE is " << userList.q1 << " and QUARTILE THREE is " << userList.q3 << " with an INTERQUARTILE RANGE of " << userList.inQR << "\n";
    results << "The OUTER FENCE values are ";
    for (auto i : userList.outFenVals)
      results << i << ", ";
    results << "and the INNER FENCE values are ";
    for (auto i : userList.inFenVals)
      results << i << ", ";
    results << "with INFLECTIONS at ";
    for (auto i : userList.inflectVals)
      results << i << " ";
    results << "\n";
    results << "The MAJOR OUTLIERS are ";
    for (auto i : userList.majLierVals)
      results << i << ", ";
    results << "and the MINOR OUTLIERS are ";
    for (auto i : userList.minLierVals)
      results << i << ", ";
    results << "\n\n\n";

    results << "Confidence Intervals\n\n";
    results << "Level of Percent     80%   90%   95%   98%   99%\n";
    results << "Z* Coefficients     1.28  1.645 1.96  2.33  2.58\n";
    results << "Margin of Error     ";
    for (auto i : userList.margsOErr)
      results << i << ",  ";
    results << "\nLower Bound     ";
    for (auto i : userList.lowLimsCI)
      results << i << ",  ";
    results << "\nUpper Bound     ";
    for (auto i : userList.highLimsCI)
      results << i << ",  ";
    results.close();

    std::cout << "File 'analysisResults.txt' has been created.\n";
  } else {
    std::cout << std::endl;
    std::cout << "~SAMPLE STATISTICS~\n";
    std::cout << "Minimum: " << userList.min << std::endl;
    std::cout << "Maximum: " << userList.max << std::endl;
    std::cout << "Mean: " << userList.mean << std::endl;
    std::cout << "Median: " << userList.median << std::endl;
    std::cout << "Mode: " << userList.mode << std::endl;
    std::cout << "Sum: " << userList.sum << std::endl;
    std::cout << "Sample Standard Deviation: " << userList.samStanDev << std::endl;
    std::cout << "Population Standard Deviation: " << userList.popStanDev << std::endl;
    std::cout << "Inflection Values: ";
    for (auto i : userList.inflectVals)
      std::cout << i << ", ";
    std::cout << "\n~~~~~~~~~~~~~~~~\n";
    std::cout << "Quartile 1: " << userList.q1 << std::endl;
    std::cout << "Interquartile Range: " << userList.inQR << std::endl;
    std::cout << "Quartile 3: " << userList.q3;
    std::cout << "\n~~~~~~~~~~~~~~~~\n";
    std::cout << "~OUTLIER'S & FENCES~\n";
    std::cout << "Major Outlier's: ";
    for (auto i : userList.majLierVals)
      std::cout << i << ", ";
    std::cout << "\nOuter Fence Values: ";
    for (auto i : userList.outFenVals)
      std::cout << i << ", ";
    std::cout << "\nMinor Outlier's: ";
    for (auto i : userList.minLierVals)
      std::cout << i << ", ";
    std::cout << "\nInner Fence Values: ";
    for (auto i : userList.inFenVals)
      std::cout << i << ", ";
    std::cout << "\n~~~~~~~~~~~~~~~~\n";
    std::cout << "~CONFIDENCE INTERVAL~\n";
    std::cout << "Level of %: 80% 90% 95% 98% 99%\n";
    std::cout << "Z*Values: 1.28 1.645 1.96 2.33 2.58\n";
    std::cout << "Margin of Error: ";
    for (auto i : userList.margsOErr)
      std::cout << i << ", ";
    std::cout << "\nLower Limit: ";
    for (auto i : userList.lowLimsCI)
      std::cout << i << ", ";
    std::cout << "\nUpper Limit: ";
    for (auto i : userList.highLimsCI)
      std::cout << i << ", ";
    std::cout << "\n~~~~~~~~~~~~~~~~\n";
  }
}

/* main()
      Essential Mechanism:
    user provides a list of numerical input to calculate statistics,
    error checking for improper input for userList.values,
    userList.calcStats(userList.values) call when input check is done,
    user decides if they would like a .txt file of results,
    error checking for out of bound entry for userList.cOut2Txt,
    userList.showStats() at the end of main() dependent on userList.cOut2Txt value
*/
int main() {
  std::string input;
  std::cout << "~SAMPLE STATISTICS~\n";

  std::cout << "[1] Text File Entry\n[2] Manual Entry\n:";
  do {
    std::getline(std::cin, input);

    if (input.compare("1") == 0) {
      // .txt file entry
      sleep(1);
      std::ifstream inTxt ("data.txt");
      if (inTxt.is_open()) {
        std::cout << "Reading 'data.txt'...\n";
        sleep(1);

        getline(inTxt, input);
        std::stringstream line(input);
        while (line.good()) {
          std::string value;
          std::getline(line, value, ' ');
          try {
            userList.values.push_back(std::stod(value));
          } catch (std::exception e) {
            std::cout << e.what() << "\nCould not convert data value. Please format to decimal type and retry.\n";
            return 0;
          }
        }
        inTxt.close();

        std::cout << "Finished.\n";
        sleep(1);
        std::cout << "Calculating...\n";
        sleep(1);
        userList.calcStats(userList.values);

      } else {
        std::cout << "Could not find 'data.txt'.\nMake sure the file is in the same location as the program.\nQuitting...\n";
        return 0;
      }
      break;

    } else if (input.compare("2") == 0) {
      // manual entry
      sleep(1);
      std::cout << "Please provide a list of numerical input to perform a statistical analysis.\nType 'done' when finished.\n";

      do {
        std::cout << ":";
        try {
          std::getline(std::cin, input);
          userList.values.push_back(std::stod(input));
        } catch (std::exception e) {
          if (input.compare("done") == 0) {
            if (userList.values.size() == 0) {
              sleep(1);
              std::cout << "No list provided.\nQuitting...\n";
              sleep(1);
              return 0;
            } else {
              sleep(1);
              std::cout << "Calculating...\n";
              sleep(1);
              userList.calcStats(userList.values);
              break;
            }
          } else {
            std::cout << e.what() << "\nPlease provide a +/- decimal number or type 'done'.\n";
          }
        }
      } while (input != "done");
      break;

    } else {
      std::cout << "[1] -or- [2]\n:";
    }

  } while (input != "1" || input != "2");

  std::cout << "Would you like a '.txt' file of the results? [y] -or- [n]\n:";
  do {
    std::getline(std::cin, input);

    if (input.compare("y") == 0) {
      userList.cOut2Txt = true;
      break;
    } else if (input.compare("n") == 0) {
      userList.cOut2Txt = false;
      break;
    } else {
      std::cout << "[y] -or- [n]\n:";
    }
  } while (input != "y" || input != "n");

  sleep(2);
  userList.showStats(userList.values);
  return 0;
}
