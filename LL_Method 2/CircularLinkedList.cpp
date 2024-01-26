#include <iostream>
using namespace std;

class Node
{
public:
    Node() { next = 0; }
    Node(int i, Node *in = 0)
    {
        info = i;
        next = in;
    }
    int info;
    Node *next;
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
    head = new Node(e1, head);
    if (tail == 0)
    {
        tail = head;
    }
    tail->next = head;
}

void AccessNode::addToTail(int el)
{
    if (tail != 0)
    { // if list not empty;
        tail->next = new Node(el, head);
        tail = tail->next;
    }
    else
    {
        head = tail = new Node(el, head);
        tail->next = head;
    }
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
            p->next = new Node(el, p->next);
            return;
        }

        p = p->next;
        count++;
    }
}

void AccessNode::deleteFromHead()
{
    Node *temp;
    temp = head;
    if (head == tail)
    { // if only one node in the list;
        delete head;
        head = tail = 0;
    }
    else
    {
        head = head->next;
        tail->next=head;
        delete temp;
        // head->next = 0;
    }
}

void AccessNode::deleteNode(int el)
{
    Node *p, *q;
    p = head;
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
            q = p->next;
            p->next = p->next->next;
            delete q;
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
    Node *p = head;
    if (head == tail)
    { // if only one node in the list;
        delete head;
        head = tail = 0;
    }
    else
    { // if more than one node in the list;
        while (p)
        {
            if (p->next->next == head)
            {
                tail = p;
                delete tail->next;
                tail->next = head;
                return;
            }
            p = p->next;
        }
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
        do
        {
            cout << p->info << endl;
            p = p->next;
        } while (p != head);
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
    cout << "HH\n";
    n.display();
    return 0;
}