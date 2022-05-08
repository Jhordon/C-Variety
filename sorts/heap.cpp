#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root)
{
    int largest = root;   
    int l = 2 * root + 1; 
    int r = 2 * root + 2;

    // left > root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // right > root
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != root)
    {
        swap(arr[root], arr[largest]);

        // do recursion
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int nums[] = {4, 17, 3, 12, 9, 324, 242, 675, 54, 3, 7, 56, 5, 8, 6, 34, 5, 78, 5, 34};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Before Sorting\n";
    for (auto it : nums) 
        cout << it << ",";
    
    heapSort(nums, n);

    cout << "\n\nAfter Sorting\n";
    for (auto it : nums) 
        cout << it << ",";
    cout << endl;
}