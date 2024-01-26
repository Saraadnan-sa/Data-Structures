
#include <iostream>
using namespace std;

void cycleSort(int arr[], int n)
{
	int writes = 0;

	for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
		int item = arr[cycle_start];
		int pos = cycle_start;
		for (int i = cycle_start + 1; i < n; i++)
			if (arr[i] < item)
				pos++;
		if (pos == cycle_start)
			continue;

		while (item == arr[pos])
			pos += 1;

		if (pos != cycle_start) {
			swap(item, arr[pos]);
			writes++;
		}
		while (pos != cycle_start) {
			pos = cycle_start;
			for (int i = cycle_start + 1; i < n; i++)
				if (arr[i] < item)
					pos += 1;
			while (item == arr[pos])
				pos += 1;
			if (item != arr[pos]) {
				swap(item, arr[pos]);
				writes++;
			}
		}
	}
}

int main()
{
	int arr[100] , n;
	cout<<"Enter Array Size :  ";
	cin>>n;
	
	for(int i=0 ;i < n ; i++ ){
	    cout<<"Element "<<i+1<<" : ";
	    cin>>arr[i];
	}
	
	cycleSort(arr, n);

	cout << endl<< "After sort : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}