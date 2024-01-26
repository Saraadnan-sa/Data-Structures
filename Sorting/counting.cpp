#include <iostream>
using namespace std;

// Best Time Complexity : O(n + m)
// Average Time Complexity : O(n + m)
// Worst Time Complexity : O(n + m)
// Not In-place sorting

int maximum(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n)
{
    int i, j;
    // Find the max element in the arry
    int m = maximum(A, n);
    // Creating count array
    int countArray[m + 1];
    // Initializ the array element to 0
    for (i = 0; i <= m; i++)
    {
        countArray[i] = 0;
    }
    // Increasing the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        countArray[A[i]] += 1;
    }

    i = 0; // counter for the count array
    j = 0; // counter for given array
    while (i <= m)
    {
        if (countArray[i] > 0)
        {
            A[j] = i;
            countArray[i] -= 1;
            j++;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
{
   cout<<A[i]<<" ";
}
} // End

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    countSort(arr, n);
    return 0;
}