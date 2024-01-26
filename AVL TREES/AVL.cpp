#include <iostream>

using namespace std;
#define SPACE 10
class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};

class avl
{
public:
    node *root;
    avl()
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
            return false;
    }

    int height(node *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
                return (rheight + 1);
        }
    }

    int Balance_factor(node *n)
    {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    node *rightrotate(node *y)
    {
        node *x = y->left;
        node *t2 = x->right;

        x->right = y;
        y->left = t2;

        return x;
    }

    node *leftrotate(node *y)
    {
        node *x = y->right;
        node *t2 = x->left;

        x->left = y;
        y->right = t2;

        return x;
    }

    node *insert(node *r, node *new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            cout << "data inserted successfully" << endl;
            return r;
        }
        if (new_node->data < r->data)
        {
            r->left = insert(r->left, new_node);
        }
        else if (new_node->data > r->data)
        {
            r->right = insert(r->right, new_node);
        }
        else
        {
            cout << "No duplicate datas allowed!" << endl;
            return r;
        }

        int bf = Balance_factor(r);
        // Left Left Case
        if (bf > 1 && new_node->data < r->left->data)
            return rightrotate(r);

        // Right Right Case
        if (bf < -1 && new_node->data > r->right->data)
            return leftrotate(r);

        // Left Right Case
        if (bf > 1 && new_node->data > r->left->data)
        {
            r->left = leftrotate(r->left);
            return rightrotate(r);
        }

        // Right Left Case
        if (bf < -1 && new_node->data < r->right->data)
        {
            r->right = rightrotate(r->right);
            return leftrotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;
    }

    void print(node *r, int space)
    {
        if (r == NULL)
            return;
        space = space + SPACE;
        print(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
        {
            cout << " ";
        }

        cout << r->data << endl;
        print(r->left, space);
    }

    node *minValueNode(node *x)
    {
        node *current = x;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    node *deleteNode(node *r, int v)
    {
        // base case
        if (r == NULL)
        {
            return NULL;
        }
        else if (v < r->data)
        {
            r->left = deleteNode(r->left, v);
        }
        else if (v > r->data)
        {
            r->right = deleteNode(r->right, v);
        }
        else
        {
            if (r->left == NULL)
            {
                node *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                node *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                node *temp = minValueNode(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }  

        int bf = Balance_factor(r);
        if (bf == 2 && Balance_factor(r->left) >= 0)
            return rightrotate(r);
        else if (bf == 2 && Balance_factor(r->left) == -1)
        {
            r->left = leftrotate(r->left);
            return rightrotate(r);
        }
        else if (bf == -2 && Balance_factor(r->right) <= -0)
            return leftrotate(r);
        else if (bf == -2 && Balance_factor(r->right) == 1)
        {
            r->right = rightrotate(r->right);
            return leftrotate(r);
        }

        return r;
    }
};

int main()
{
    avl obj;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        // cout << "2. Search Node" << endl;
        // cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal AVL Tree datas" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        // Node n1;
        node *new_node = new node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "AVL INSERT" << endl;
            cout << "Enter data of TREE NODE to INSERT in AVL Tree: ";
            cin >> val;
            new_node->data = val;
            obj.root = obj.insert(obj.root, new_node);
            cout << endl;
            break;
        // case 2:
        //     cout << "SEARCH" << endl;
        //     cout << "Enter data of TREE NODE to SEARCH in AVL Tree: ";
        //     cin >> val;
        //     // new_node = obj.iterativeSearch(val);
        //     new_node = obj.recursiveSearch(obj.root, val);
        //     if (new_node != NULL)
        //     {
        //         cout << "data found" << endl;
        //     }
        //     else
        //     {
        //         cout << "data NOT found" << endl;
        //     }
        //     break;
        // case 3:
        //     cout << "DELETE" << endl;
        //     cout << "Enter data of TREE NODE to DELETE in AVL: ";
        //     cin >> val;
        //     new_node = obj.recursiveSearch(obj.root, val);
        //     if (new_node != NULL)
        //     {
        //         obj.root = obj.deleteNode(obj.root, val);
        //         cout << "data Deleted" << endl;
        //     }
        //     else
        //     {
        //         cout << "data NOT found" << endl;
        //     }
        //     break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print(obj.root, 5);
            cout << endl;
            // cout <<"Print Level Order BFS: \n";
            // obj.printLevelOrderBFS(obj.root);
            // cout <<endl;
            //	      cout <<"PRE-ORDER: ";
            //	      obj.printPreorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"IN-ORDER: ";
            //	      obj.printInorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"POST-ORDER: ";
            //	      obj.printPostorder(obj.root);
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}