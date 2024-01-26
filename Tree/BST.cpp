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

    // node *insert(node *r, int value)
    // {
    //     if (r == NULL)
    //     {
    //         return new node(value);
    //     }
    //     if (value > r->data)
    //     {
    //         r->right = insert(r->right, value);
    //     }
    //     else if (value < r->data)
    //     {
    //         r->left = insert(r->left, value);
    //     }
    //     return r;
    // }

    // void insertValue(tree &t, int value)
    // {
    //     t.root = insert(t.root, value);
    // }

    void traversal(node *root) //preorder
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
             << "traversal: ";
        traversal(root);
        cout << endl
             << endl;
    }

    node *search(int val)
    {
        node *temp;
        if (root == NULL)
        {
            return root;
        }
        else
        {
            temp = root;
            while (temp != NULL)
            {
                if (val == temp->data)
                {
                    return temp;
                }
                else if (val < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    node *Delete(node *r, int value)
    {
        node *temp;
        if (r == NULL)
        {
            return NULL;
        }
        else if (value < r->data)
        {
            r->left = Delete(r->left, value); // Value returned from delete function will e stored i r->left
        }
        else if (value > r->data)
        {
            r->right = Delete(r->right, value); // Value returned from delete function will e stored i r->left
        } 
            
        else
        {
            if (r->left==NULL)
            {
                temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right==NULL)
            {
                temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                temp = minValueNode(r->right);
                r->data = temp->data;
                r->right = Delete(r->right, temp->data);
            }
        }
        return r;
    }

    node *minValueNode(node *n)
    {
        node *temp = n;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    void levelOrderTraversal(node *root)
    {
        if (root == NULL)
            return;

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *current = q.front();
            cout << current->data << " ";
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
            q.pop();
        }
    }
    void DFS(node *root)
    {
        if (root == NULL)
            return;

        stack<node *> s;
        s.push(root);

        while (!s.empty())
        {
            node *current = s.top();
            s.pop();
            cout << current->data << " ";
            if (current->right != NULL)
            {
                s.push(current->right);
            }
           
            if (current->left != NULL)
            {
                s.push(current->left);
            }
           
            
        }
    }
};

int main()
{
    tree t;
    // t.insertValue(t, 25);
    // t.insertValue(t, 15);
    // t.insertValue(t, 5);
    // t.insertValue(t, 20);
    // t.insertValue(t, 18);
    // t.insertValue(t, 40);
    // t.insertValue(t, 45);

    t.insert(t.root, 25);
    t.insert(t.root, 15);
    t.insert(t.root, 5);
    t.insert(t.root, 20);
    t.insert(t.root, 18);
    t.insert(t.root, 40);
    t.insert(t.root, 45);
    
    // t.insert(t.root, 5);
    // t.insert(t.root, 4);
    // t.insert(t.root, 7);
    // t.insert(t.root, 3);
    // t.insert(t.root, 6);
    // t.insert(t.root, 8);
    // t.levelOrderTraversal(t.root);
    // t.print();

    // t.Delete(t.root, 15);
    //  t.levelOrderTraversal(t.root);
    t.print();

    t.DFS(t.root);
    return 0;
}
