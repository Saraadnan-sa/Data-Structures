#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void combSort(int arr[], int size) {
    int gap = size;
    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13; // gagp/=1.3
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    int size ;
    int arr[100];
    cout<<"Enter Size : ";
    cin>>size;
  
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout <<endl<< "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] <<" ";
    }
    
    combSort(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}