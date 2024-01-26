#include <iostream>
#include <queue>

using namespace std;

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode* left;
    MinHeapNode* right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode* root, string str)
{
    if (!root)
        return;

    if (root->data != '*')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    MinHeapNode** heapArray = new MinHeapNode*[size];
    for (int i = 0; i < size; ++i)
        heapArray[i] = new MinHeapNode(data[i], freq[i]);

    priority_queue<MinHeapNode*, deque<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(heapArray[i]);

    while (minHeap.size() != 1) {
        MinHeapNode* left = minHeap.top();
        minHeap.pop();

        MinHeapNode* right = minHeap.top();
        minHeap.pop();

        MinHeapNode* top = new MinHeapNode('*', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
    
    // Free allocated memory
    for (int i = 0; i < size; ++i)
        delete heapArray[i];
    delete[] heapArray;
}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
