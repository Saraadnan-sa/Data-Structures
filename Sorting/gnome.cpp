#include <iostream>
using namespace std; 

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void gnomeSort(int arr[], int size) {
    int i = 0;

    while (i < size) {
        if (i == 0 || arr[i] >= arr[i - 1]) {
            ++i;
        } else {
            swap(arr[i], arr[i - 1]);
            --i;
        }
    }
}

int main() {
    int arr[100];
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
       cout << "Invalid array size\n";
        return 1; 
    }

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    
    gnomeSort(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}