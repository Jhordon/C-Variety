#include <iostream>
#include <vector>

double select(std::vector<double> nums, int x) {
    double selected, pos;
    selected = nums.at(x);
    pos = x;
    for (int j = x + 1; j < nums.size(); j++) {
        if (nums.at(j) < selected) {
            selected = nums.at(j);
            pos = j;
        }
    }
    return pos;
}

int main () {
    std::vector<double> nums = {1, 2345, 23, 43, 534, 324, 2, 23, 8, 6, 547, 6543, 86, 57};
    double pos, temp;

    std::cout << "Before Sorting:\n";
    for (auto it : nums)
        std::cout << it << ",";
    
    // Selection Sort
    for (int i = 0; i < nums.size(); i++) {
        pos = select(nums, i);
        temp = nums.at(i);
        nums.at(i) = nums.at(pos);
        nums.at(pos) = temp;
    }

    std::cout << "\n\nAfter Sorting:\n";
    for (auto it : nums)
        std::cout << it << ",";

    std::cout << std::endl;
    return 0;
}