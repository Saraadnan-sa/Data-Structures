#include <iostream>
#include <math.h>
#define INT_MAX 100
using namespace std;
class heap
{
public:
    int *arr;
    int size;
    int capacity;
    heap(int cap)
    {
        arr = new int[cap];
        capacity = cap;
        size = cap;
    }
    
    int getParent(int i)
    {
        return (i - 1) / 2;
    }
    
    int getLeft(int i)
    {
        return (2 * i + 1);
    }
    
    int getRight(int i)
    {
        return (2 * i + 2);
    }
    
    void swap(int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    
    int extractMax()
    {
        if (size <= 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        if (size > 0)
        {
            int root = arr[0];
            arr[0] = arr[size - 1];
            size--;
            MaxHeapify(0);
            return root; // after max-heapifying
        }
    }
    
    int getMax()
    {
        return arr[0];
    }
    
    void MaxHeapify(int i)
    {
        int largest = i;
        int l = getLeft(i);
        int r = getRight(i);
        if (l <= size && arr[l] > arr[i])
        {
            largest = l;
        }
        if (r <= size && arr[r] > arr[i])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            MaxHeapify(largest);
        }
    }
    
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void height()
    {
        ceil(log2(size + 1)) - 1;
    }
    
    void deleted(int i)
    {
        if (size <= 0)
        {
            cout << "NOT POSSIBLE" << endl;
        }
        else
        {
            increasekey(i, INT_MAX);
            extractMax();
        }
    }
    
    void increasekey(int i, int k)
    {
        arr[i] = k;
        while (i != 0 && arr[getParent(i)] < arr[i])
        {
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
        }
    }
    
    void insert(int k)
    {
        if (size == capacity)
        {
            cout << "FULL" << endl;
        }
        size++;
        int i = size - 1;
        arr[i] = k;
        while (i != 0 && getParent(i) < arr[i])
        {
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
        }
    }
    
    void linearsearch(int k)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == k)
            {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value NOT Found!";
    }
    
    void getUnsortedArray()
    {
        cout << "Enter " << capacity << " no of elements to sort using HEAPSORT" << endl;
        for (int i = 0; i < capacity; i++)
            cin >> arr[i];
    }
    
    void heapSort()
    {
        int temp[capacity];
        for (int j = 0; j < capacity; j++)
        {
            temp[j] = extractMax();
            cout << temp[j] << " ";
        }
    }
};
int main()
{
    int s;
    cout << "Enter Size of Max Heap" << endl;
    cin >> s;

    heap obj(s);
    obj.getUnsortedArray(); // Input the unsorted array

    cout << "Unsorted Array:" << endl;
    obj.print();

    // Perform max-heapify
    for (int i = s / 2 - 1; i >= 0; i--)
    {
        obj.MaxHeapify(i);
    }

    cout << "Heapified Array:" << endl;
    obj.print();

    // If you want to demonstrate heap sort, you can uncomment the following lines:
    // cout << "Heap Sorted Array:" << endl;
    // obj.heapSort();
    // obj.print();

    cout << "Max Extracted Value: " << obj.extractMax() << endl;

    return 0;
}