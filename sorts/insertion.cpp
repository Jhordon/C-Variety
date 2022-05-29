#include <iostream>
#include <vector>

int main()
{
    std::vector<double> nums = {1, 2345, 23, 43, 534, 324, 2, 23, 8, 6, 547, 6543, 86, 57};
    double temp;

    std::cout << "Before Sorting:\n";
    for (auto it : nums)
        std::cout << it << ",";

    // Insertion Sort
    for (int k = 1; k < nums.size(); k++) {
        temp = nums.at(k);
        int j = k - 1;
        while (j >= 0 && temp <= nums.at(j)) {
            nums.at(j+1) = nums.at(j);
            j = j - 1;
        }
        nums.at(j+1) = temp;
    }

    std::cout << "\n\nAfter Sorting:\n";
    for (auto it : nums)
        std::cout << it << ",";

    std::cout << std::endl;
    return 0;
}