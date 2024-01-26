#include <iostream>
using namespace std;

class Node
{
public:
    Node() { next = prev = 0; }
    Node(int i, Node *in = 0, Node *p = 0)
    {
        info = i;
        next = in;
        prev = p;
    }
    int info;
    Node *next, *prev;
};

class AccessNode
{
private:
    Node *head, *tail;

public:
    AccessNode() { head = tail = NULL; }
    int isEmpty() { return head == 0; }
    void addToHead(int);
    void addToTail(int);
    void addMid(int, int);
    void deleteFromHead();
    void deleteFromTail();
    void deleteNode(int);
    void display();
    // bool isInList(int) const;
    // ~AccessNode();
};

void AccessNode ::addToHead(int e1)
{
    head = new Node(e1, head, 0);
    if (tail == 0)
        tail = head;
}

void AccessNode::addToTail(int el)
{
    if (tail != 0)
    { // if list not empty;
        tail->next = new Node(el, 0, tail);
        tail = tail->next;
    }
    else
        head = tail = new Node(el, 0, 0);
}

void AccessNode::addMid(int loc, int el)
{
    Node *p = head;
    int count = 1;
    while (p)
    {
        if (loc == 1)
        {
            addToHead(el);
            return;
        }
        else if (p->next == NULL)
        {
            addToTail(el);
            return;
        }
        else if (count == (loc - 1))
        {
            p->next = p->next->prev = new Node(el, p->next, p);
            return;
        }

        p = p->next;
        count++;
    }
}

void AccessNode::deleteFromHead()
{
    Node* temp;
    temp=head;
    if (head == tail)
    { // if only one node in the list;
        delete head;
        head = tail = 0;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void AccessNode::deleteNode(int el)
{
    Node *p = head;
    if (head == tail)
    { // if only one node in the list;
        delete head;
        head = tail = 0;
    }
    while (p)
    {
        if (p->info == el)
        {
            deleteFromHead();
            return;
        }
        else if (p->next->info == el)
        {
            p=p->next;
            p->next->prev=p->prev;
            p->prev->next=p->next;
            delete p;
            return;
        }
        else if (p->next == NULL)
        {
            deleteFromTail();
            return;
        }
    }
}

void AccessNode::deleteFromTail()
{
     int el = tail->info;
    if (head == tail)
    { // if only one node in the list;
        delete head;
        head = tail = 0;
    }
    else
    { // if more than one node in the list;
        tail = tail->prev;
        delete tail->next;
        tail->next=NULL;
    }
    return;
}

void AccessNode::display()
{
    Node *p;
    if (!head)
    {
        cout << "List Empty" << endl;
    }
    else
    {
        p = head;
        while (p)
        {
            cout << p->info << endl;
            p = p->next;
        }
    }
}

int main()
{
     AccessNode n;
    n.addToHead(5);
    n.addToTail(7);
    n.addMid(2, 6);
    // n.addMid(2, 2);
    n.display();
    n.deleteFromHead();
    // n.deleteNode(6);
    // n.deleteFromTail();
    cout<<"HH\n";
        n.display();
    return 0;
}