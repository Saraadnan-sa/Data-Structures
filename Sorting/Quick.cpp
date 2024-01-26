#include <iostream>
using namespace std;

// Best Time Complexity : O(nlogn)
// Average Time Complexity : O(nlogn)
// Worst Time Complexity : O(n^2)
// In-place sorting

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[e], arr[pIndex]);

    return pIndex;
}

void Quicksort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        Quicksort(arr, s, (p - 1));
        Quicksort(arr, (p + 1), e);
    }
}

int main()
{
    int len;
    cout << "Enter length of array to be sorted" << endl;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    Quicksort(arr, 0, (len - 1));

    cout << "Sorted array using quick Sort: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}