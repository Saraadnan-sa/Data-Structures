#include <bits/stdc++.h>
using namespace std;

void compAndSwap(int a[], int i, int j, int dir)
{
    if (dir == (a[i] > a[j]))
        swap(a[i], a[j]);
}

void bitonicMerge(int a[], int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compAndSwap(a, i, i + k, dir);
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low + k, k, dir);
    }
}

void bitonicSort(int a[], int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        bitonicSort(a, low, k, 1);
        bitonicSort(a, low + k, k, 0);
        bitonicMerge(a, low, cnt, dir);
    }
}

void sort(int a[], int N, int up)
{
    bitonicSort(a, 0, N, up);
}

int main()
{
    int N,x;
    cout << "Enter Size of array in power of 2 (2^x) : ";
    cin >> x;
N=pow(2,x);
    int a[N];
    cout<<"Enter "<<N<<" elements"<<endl;
    for (int i = 0; i < N; i++)
    {
        // cout << "Element " << i + 1 << " : ";
        cin >> a[i];
    }

    int up = 1; // means sort in ascending order
    sort(a, N, up);

    cout << "Sorted array" << endl;
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    return 0;
}
