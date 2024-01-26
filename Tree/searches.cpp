#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *right; // memory address of next node
    node *left;
    node()
    {

        data = 0;
        right = NULL;
        left = NULL;
    }
    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

class tree
{
public:
    node *root;

    tree()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    void insert(node *&r, int val)
    {
        if (r == NULL)
        {
            r = new node(val);
        }
        else if (val < r->data)
        {
            insert(r->left, val);
        }
        else
        {
            insert(r->right, val);
        }
    }

    void traversal(node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            traversal(root->left);
            traversal(root->right);
        }
    }

    void InOrder_traversal(node *root)
    {
        if (root != NULL)
        {
            InOrder_traversal(root->left);
            cout << root->data << " ";
            InOrder_traversal(root->right);
        }
    }

    void PostOrder_traversal(node *root)
    {
        if (root != NULL)
        {

            PostOrder_traversal(root->right);
            cout << root->data << " ";
            PostOrder_traversal(root->left);
        }
    }

    void print()
    {
        cout << "Print\n";
        cout << "inorder: ";
        InOrder_traversal(root);
        cout << endl;
        cout
            << "post order: ";
        PostOrder_traversal(root);
        cout << endl
             << "pre traversal: ";
        traversal(root);
        cout << endl
             << "BFS: ";
        BFS_print(root);
        cout << endl
             << "DFS: ";
        DFS_print(root);
    }

    void BFS_print(node *root)
    {
        node *temp = root;
        queue<node *> q;
        q.push(temp);
        if(isEmpty()){
            return;
        }
        while (!isEmpty())
        {
            temp = q.front();
            cout << temp->data << " ";
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << "AYEIN" << endl;
    }

    void DFS_print(node *root)
    {
        node *temp = root;
        stack<node *> s;
        s.push(temp);
        while (!isEmpty())
        {
            temp = s.top();
            cout << temp->data << " ";
            s.pop();
            if (temp->right)
            {
                s.push(temp->right);
            }
            if (temp->left)
            {
                s.push(temp->left);
            }
        }
    }

    void BFS(node *root, int val)
    {
        node *temp = root;
        queue<node *> q;
        q.push(temp);
        while (!isEmpty())
        {
            temp = q.front();
            cout << temp << " ";
            q.pop();

            if (temp->data == val)
            {
                cout << "Value found" << endl;
                return;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }

    void DFS(node *root, int val)
    {
        node *temp = root;
        stack<node *> s;
        s.push(temp);
        while (!isEmpty())
        {
            temp = s.top();
            s.pop();
            if (temp->data == val)
            {
                cout << "Value found" << endl;
                return;
            }
            else
            {
                if (temp->right)
                {
                    s.push(temp->right);
                }
                if (temp->left)
                {
                    s.push(temp->left);
                }
            }
        }
    }
};

int main()
{
    tree t;

    t.insert(t.root, 5);
    t.insert(t.root, 2);
    t.insert(t.root, 7);
    t.insert(t.root, 1);
    t.insert(t.root, 3);
    t.insert(t.root, 6);
    t.insert(t.root, 8);
    t.insert(t.root, 4);

    t.print();
    t.DFS(t.root, 20);
    return 0;
}
