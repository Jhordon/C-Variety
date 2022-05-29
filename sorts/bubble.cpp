#include <iostream>
#include <vector>

int main() {
    std::vector<double> nums = {1, 2345, 23, 43, 534, 324, 2, 23, 8, 6, 547, 6543, 86, 57};
    double temp;

    std::cout << "Before Sorting:\n";
    for (auto it : nums) 
        std::cout << it << ",";

    // Ascending Bubble Sort
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (nums.at(j) > nums.at(i)) {
                temp = nums.at(i);
                nums.at(i) = nums.at(j);
                nums.at(j) = temp;
            }
        }
    }

    std::cout << "\n\nAfter Sorting:\n";
    for (auto it : nums) 
        std::cout << it << ",";

    std::cout << std::endl;
    return 0;
}