#include <iostream>
using namespace std;

int shellSort(int arr[], int n)
{
      // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cout << "Enter Array Size :  ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        // cout<<"Element "<<i+1<<" : ";
        cin >> arr[i];
    }

    cout << "Array before sorting: \n";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);

    return 0;
}