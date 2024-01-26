#include <iostream>
using namespace std;

class FloatList
{
private:
    // Declare a structure for the list
    struct node
    {
        float value;
        struct node *next;
    };
    node *head; // List head pointer
public:
    FloatList(void)
    { // Constructor
        head = NULL;
    }
    ~FloatList(void){}; // Destructor
    void appendNode(float);
    void prependNode(float);
    void displayList(void);
    float search(float);
    void deleteNode(float);
    void UpdateNode(float, float);
    void Count();
    void Insertafter(float, float);
    void Insertbefore(float, float);
};

void FloatList::appendNode(float num)
{
    node *q = new node;
    node *p = head;
    // Allocate a new node & store num
    q->value = num;
    q->next = NULL;

    if (!head)
    { // head == NULL
        head = q;
        q->next = head;
    }
    else // Otherwise, insert newNode at end
    {
        while (p->next != head)
        { // Find the last node in the list
            p = p->next;
        }
        p->next = q;
        q->next = head;
    }
}

void FloatList::prependNode(float num)
{
    node *q = new node;
    node *p = head;
    // Allocate a new node & store num
    q->value = num;
    q->next = NULL;

    if (!head) // head == NULL
        head = q;
    else // Otherwise, insert newNode at end
    {
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = q;
        q->next = head;
        head = q;
    }
}

void FloatList::displayList(void)
{
    node *p;
    if (!head)
    {
        cout << "List Empty" << endl;
    }
    else
    {
        p = head;
        do
        {
            cout << p->value << endl;
            p = p->next;
        } while (p != head);
    }
}

float FloatList::search(float num)
{
    node *p;
    p = head;
    if (!head)
    {
        cout << "List Empty" << endl;
    }
    else
    {
        while (p->next != head)
        {
            if (p->value == num)
            {
                cout << "Found !" << endl;
                return 0;
            }
            p = p->next;
        }

        cout << "Not Found";
    }
}

void FloatList::deleteNode(float num)
{
    node *p, *q;
    p = head;
    if (!head)
    {
        return;
    }
    else if (head->value == num)
    { // when 1st value matches
        if (head->next == head)
        {
            head = nullptr;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        p = head;
        while (p != NULL && p->value != num)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
}

void FloatList::UpdateNode(float rep, float num)
{
    node *p;
    p = head;
    if (!head)
    {
        cout << "List Empty" << endl;
    }
    else
    {
        while (p)
        {
            if (p->value == rep)
            {
                p->value = num;
                return;
            }
            p = p->next;
        }

        cout << rep << "Not Found";
    }
}

void FloatList::Count()
{
    node *p = head;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    }while(p!=head);
    cout << "Count is :" << count << endl;
}

void FloatList::Insertafter(float a, float b)
{
    node *q, *p;
    q = new node;
    q->value = b;
    q->next = NULL;
    p = head;
    while (p)
    {
        if (p->value == a)
        {
            q->next = p->next;
            p->next = q;
            return;
        }
        p = p->next;
    }
}

void FloatList::Insertbefore(float a, float b)
{
    node *q, *p;
    q = new node;
    q->value = b;
    q->next = NULL;
    p = head;
    if (head->value == a)
    {
        prependNode(b);
    }
    else
    {
        while (p->next)
        {
            if (p->next->value == a)
            {
                q->next = p->next;
                p->next = q;
                return;
            }
            p = p->next;
        }
    }
}

int main()
{
    FloatList list;
    cout << "start" << endl;
    list.appendNode(12.6);
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(1.6);
    list.prependNode(1.1);
    cout << "DISPLAY\n";
    list.displayList();
    cout << "DEL" << endl;
    // list.deleteNode(1.6);
    // list.displayList();
    // list.search(12.6);
    cout << "Insert..." << endl;
    list.Insertafter(12.6, 5.6);
    list.Insertbefore(1.1, 4.1);
    list.Count();
    // list.displayList();
    list.UpdateNode(12.6, 11.3);
    list.displayList();
    return 0;
}