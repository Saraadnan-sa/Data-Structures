#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char using_rod, char to_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, using_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, using_rod, to_rod, from_rod);
}

int main()
{
    int N;
    cout << "Enter Number of disks in Rod A" << endl;
    cin >> N;
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'B', 'C');
    return 0;
}
