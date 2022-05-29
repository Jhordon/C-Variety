#include <iostream>
using namespace std;

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

int main()
{
    int nums[] = {12, 344, 454, 343, 34, 324, 54, 5, 653, 345, 43, 74, 67, 32853};
    int N = sizeof(nums)/sizeof(nums[0]);

    cout << "Before Sorting: \n";
    for (auto it : nums) 
        cout << it << ",";

    merge_sort(nums, 0, N - 1);
    
    cout << "\n\nAfter Sorting:\n";
    for (auto it : nums) 
        cout << it << ",";
    cout << endl;
}