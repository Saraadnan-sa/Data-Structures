#include <iostream>
using namespace std;

double get_max_index(int vals[], int wgts[], int size)
{
    int max_index = 0;
    double max_val_per_wgt = 0;
    for (int i = 0; i < size; i++)
    {
        if (wgts[i] != 0 && (double)vals[i] / wgts[i] > max_val_per_wgt)
        {
            max_val_per_wgt = (double)vals[i] / wgts[i];
            max_index = i;
        }
    }
    return max_index;
}

double get_max_value(int vals[], int wgts[], int num_items, int capacity)
{

    double max_val = 0.0;
    for (int i = 0; i < num_items; i++)
    {
        if (capacity == 0)
        {
            return max_val; // There's no space left in the bag to carry
        }
        int max_value_index = get_max_index(vals, wgts, num_items);                         // See which item has the best value per weight index
        double taken = capacity > wgts[max_value_index] ? wgts[max_value_index] : capacity; // get the minimum of the item's weight and capacity left in the bag
        max_val += taken * (double)vals[max_value_index] / wgts[max_value_index];           // calculate value for the item's weight taken
        capacity -= taken;                                                                  // reduce capacity of the bag by the amount of weight of the item taken
        wgts[max_value_index] -= taken;                                                     // reduce the item's weight by the amount taken
        vals[max_value_index] -= taken * (double)vals[max_value_index] / wgts[max_value_index];
    }
    return max_val;
}

int main()
{
    int num_items, capacity;
    cout << "enter number of items" << endl;
    cin >> num_items;
    cout << "Enter capacity of knapsack" << endl;
    cin >> capacity;

    int *values = new int[num_items];
    int *weights = new int[num_items];

    cout << "enter value and weight of each item" << endl;
    for (int i = 0; i < num_items; i++)
    {
        int val = 0, wgt = 0;
        cout << endl;
        cin >> val >> wgt;
        values[i] = val;
        weights[i] = wgt;
    }

    cout.precision(10);
    cout << fixed << get_max_value(values, weights, num_items, capacity) << endl; // Always display 'precision' number of digits

    delete[] values;
    delete[] weights;

    return 0;
}
