#include <iostream>

using namespace std;

    void BubbleSort(int array[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                }
            }
        }
        for (int i = 0; i < size; i++) {
            cout << array[i] << "  ";
        }
        cout << endl;
    }

    // Function to print the array
    void printArray(int array[], int size) {
        cout << "Sorted Array: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << "  ";
        }
        cout << endl;
    }

    

int main() {
    int size, array[100];

    cout << "How many elements in the array do you want? " << endl;
    cout << "Enter: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout<<"Element : "<<i+1<<" :";
        cin >>  array[i];
    }
    cout << endl;

BubbleSort(array, size);
printArray(array , size);


    return 0;
}