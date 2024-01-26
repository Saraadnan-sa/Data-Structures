#include <iostream>
using namespace std;

class queue
{

private:
    int arr[5];
    int rear = -1;
    int front = -1;
    int n = sizeof(arr) / sizeof(arr[0]);
    int item_count;

public:
    queue()
    {
        item_count = 0;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if ((rear + 1) % n == front)
        {
            return true;
        }
        else
            return false;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % n; // for circular queue
        }
        arr[rear] = value;
        item_count++;
    }

    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else if (front == rear) // only one element
        {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % n;
        }
        item_count--;
        return x;
    }

    int count()
    {
        // return (rear - front + 1); // no of elements in stack
        return item_count;
    }

    void display()
    {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        int temp = front;
        while (temp != rear) {
            cout << arr[temp] << " ";
            temp = (temp + 1) % n;
        }
        cout << arr[rear] << endl;
    }
    
};

int main()
{
    queue q;
   
    q.enqueue(1);
    q.enqueue(2); 
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    // q.display();
    q.enqueue(6);
    q.enqueue(7);
    q.display();

    return 0;
}
