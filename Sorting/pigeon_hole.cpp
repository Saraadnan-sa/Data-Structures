#include <iostream>

// Adjust the maximum array size as needed

void pigeonholeSort(int arr[], int size) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max - min + 1;
    int holes[range] = {0};

    for (int i = 0; i < size; ++i) {
        holes[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (holes[i] > 0) {
            arr[index++] = i + min;
            holes[i]--;
        }
    }
}

int main() {
    int arr[] = {8, 3, -2, 7, 4, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    pigeonholeSort(arr, size);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
