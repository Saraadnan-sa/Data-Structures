#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        maxHeapify(arr, n, largest);
    }
}

int deleteRoot(int arr[], int &n)
{
    // Store the maximum value, and remove it from heap
    int root = arr[0];
    arr[0] = arr[n - 1];
    n--;

    // Heapify the root node
    maxHeapify(arr, n, 0);

    return root;
}

int main()
{
    int n;
    cout << "Entr size of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "Given array is \n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }

    cout << "Max Heap array is \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Deleting the root: " << deleteRoot(arr, n) << endl;

    cout << "Max Heap array after deletion is \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
