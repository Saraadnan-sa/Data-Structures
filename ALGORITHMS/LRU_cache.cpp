#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class LRUCache
{
    list<int> dq;
    int csize; // maximum capacity of cache

public:
    LRUCache(int);
    void add(int);
    void display();
};

LRUCache::LRUCache(int n) { csize = n; }

void LRUCache::add(int x)
{
    auto it = find(dq.begin(), dq.end(), x);

    if (it == dq.end())
    {
        if (dq.size() == csize)
        {
            int last = dq.back();
            dq.pop_back();
        }
    }
    else
    {
        dq.erase(it);
    }

    dq.push_front(x);
}

void LRUCache::display()
{
    for (auto it = dq.begin(); it != dq.end(); it++)
        cout << (*it) << " ";
    cout << endl;
}

int main()
{
    LRUCache ca(8);
    ca.add(4);
    ca.add(3);
    ca.add(25);
    ca.add(8);
    ca.add(19);
    ca.add(6);
    ca.add(25);
    ca.add(8);
    ca.add(16);
    ca.add(35);
    ca.add(45);
    ca.add(22);
    ca.add(8);
    ca.add(3);
    ca.add(16);
    ca.add(25);
    ca.add(7);

    ca.display();

    return 0;
}
