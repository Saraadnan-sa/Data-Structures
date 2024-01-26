#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
};

class stack
{
    int size;
    node *top;

public:
    stack()
    {
        size = 0;
        top = NULL;
    }
    void push(int);
    int pop();
    bool isEmpty();
    void display();
};

void stack::push(int el)
{
    node *temp;
    temp = new node;
    if (top == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = top;
    }
    temp->value = el;
    top = temp;
    size++;
}

int stack::pop()
{
    int d;
    if (isEmpty())
    {
        cout << "\nStack is Empty\n";
        return 0;
    }
    else
    {
        node *temp = top;
        top = top->next;
        d = temp->value;
        delete temp;
        size--;
    }
    return d;
}

void stack::display(){
     node *p;
    if (isEmpty() )
    {
        cout << "List Empty" << endl;
    }
    else
    {
        p = top;
        while (p)
        {
            cout << p->value << endl;
            p = p->next;
        }
    }
}


bool stack::isEmpty()
{
    if (top == NULL)
        return true;
    return false;
}



int main()
{
    stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();
    s.display();

    return 0;
}