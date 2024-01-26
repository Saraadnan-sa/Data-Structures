// C++ program to sort an
// array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to sort arr[] of
// size n using bucket sort
void bucketSort(float arr[], int n)
{

	// 1) Create n empty buckets
	vector<float> b[n];

	// 2) Put array elements
	// in different buckets
	for (int i = 0; i < n; i++) {

		// Index in bucket
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

void bucketSort_int(int arr[], int n, int size) {
    // Step1: Create n empty buckets
    vector<int> b[n];
    int max = *max_element(arr, arr + size);
    int min = *min_element(arr, arr + size);
    int range = (max - min) / n + 1;
    // Step2: Put each element in suitable bucket
    for (int i = 0; i < size; i++) {
        int bi = floor((arr[i] - min) / range);  // index of bucket
        b[bi].push_back(arr[i]);
    }
    // Step3: Sort all buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end()); // built-In sort function
    // Step4: Gather all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];  // updating previous data
}


// Driver program to test above function
int main()
{
	float arr[]
		= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

cout<<endl;
int arr1[]= { 6, 5,4,3,2,1 };
	int n2 = sizeof(arr) / sizeof(arr[0]);
	bucketSort_int(arr1, n2,n2);

	cout << "Sorted array is \n";
	for (int i = 0; i < n2; i++)
		cout << arr[i] << " ";

	return 0;
}
