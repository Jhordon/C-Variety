#include <iostream>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int split(int nums[], int s, int e) {
    int pivot = nums[e];
    int i = (s - 1);

    for (int j = s; j <= e - 1; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i+1], &nums[e]);
    return (i+1);
}

void sort(int nums[], int s, int e) {
    if (s < e) {
        int p = split(nums, s, e);
        sort(nums, s, p - 1);
        sort(nums, p + 1, e);
    }
}

int main() {
    int nums[] = {1, 2345, 23, 43, 534, 324, 2, 23, 8, 6, 547, 6543, 86, 57};
    int n = sizeof(nums) / sizeof(nums[0]);

    std::cout << "Before Sorting:\n";
    for (auto it : nums)
        std::cout << it << ",";

    sort(nums, 0, n-1);

    std::cout << "\n\nAfter Sorting:\n";
    for (auto it : nums)
        std::cout << it << ",";

    std::cout << std::endl;
    return 0;
}