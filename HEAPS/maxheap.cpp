#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node *parent;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class heap
{
public:
    node *root;

    heap()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    node *lastnode()
    {
        queue<node *> q;
        q.push(root);
        node *last;

        while (!q.empty())
        {
            last = q.front();
            q.pop();
            if (last->left)
            {
                q.push(last->left);
            }
            if (last->right)
            {
                q.push(last->right);
            }
            else
            {
                break;
            }
        }
        return last;
    }

    void delete_root()
    {
        if (isEmpty())
        {
            cout << "Heap is Empty\n";
            return;
        }
        node *last = lastnode();

        if (last == root)
        {
            delete last;
            root = NULL;
            return;
        }

        swap(root->data, last->data);
        node *pr = last->parent;
        if (pr->left == last)
        {
            delete last;
            pr->left = NULL;
        }
        else
        {
            delete last;
            pr->right = NULL;
        }

        downheapify(root);
    }

    void downheapify(node *temp)
    {

        node *largest = temp;
        if (temp->left && (temp->left->data > largest->data))
        {
            largest = temp->left;
        }
        if (temp->right && (temp->right->data > largest->data))
        {
            largest = temp->right;
        }
        if (largest != temp)
        {
            swap(largest->data, temp->data);
            downheapify(largest);
        }
    }

    void upheapify(node *temp)
    {
        if (temp->parent == NULL)
        {
            return;
        }
        if (temp->parent->data < temp->data)
        {
            swap(temp->parent->data, temp->data);
            upheapify(temp->parent);
        }
    }

    node *lastparent()
    {
        queue<node *> q;
        q.push(root);
        node *temp;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->left && temp->right)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
            else
            {
                break;
            }
        }
        return temp;
    }

    void insert(int val)
    {
        node *new_node = new node(val);

        if (root == NULL)
        {
            root = new_node;
            return;
        }
        node *lpar = lastparent();

        if (lpar->left == NULL)
        {
            lpar->left = new_node;
            new_node->parent = lpar;
        }
        else
        {
            lpar->right = new_node;
            new_node->parent = lpar;
        }

        upheapify(new_node);
    }

    void InOrder_traversal(node *r)
    {
        if (r != NULL)
        {
            InOrder_traversal(r->left);
            cout << r->data << " ";
            InOrder_traversal(r->right);
        }
    }

    void print()
    {
        node *temp = root;
        InOrder_traversal(temp);
        cout << endl;
    }
};

int main()
{
    heap h;
    cout << "Start\n";
    // h.insert(50);
    // h.insert(70);
    // h.insert(56);
    // h.insert(58);
    // h.insert(89);
    // h.insert(46);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    cout << "Print\n";
    h.print();

    h.delete_root();

    h.print();

    return 0;
}