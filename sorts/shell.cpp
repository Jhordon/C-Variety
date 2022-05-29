#include <iostream>
using namespace std;

int shellSort(int arr[], int N)
{
    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {343, 24, 234, 11, 2, 121, 687, 9, 7, 4, 9, 76, 43, 32, 369};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: \n";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    shellSort(arr, N);

    cout << "\nAfter Sorting: \n";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}