#include <iostream>
using namespace std;
// #define space 10;

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
    node( int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

class tree{
public:
    node *root ;
    node *temp;
    node* current;

    tree(){
        root=NULL;
    }
    
    bool isEmpty()
    {
        if (root==NULL)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    void insert(node *node_new)
    {
        if (root==NULL)
        {
            root=node_new;
            cout<<"Value inserted at root"<<endl;
        }
        else 
        {
            temp=root;
            while(temp != NULL)
            {
                if (node_new->data==temp->data)
                {
                    cout<<"No duplicates allowed"<<endl;
                    return;
                }
                else if ((node_new->data < temp->data) && (temp->left==NULL))
                {
                    temp->left=node_new;
                    cout<<"Value inserted at left side"<<endl;
                    break;
                }
                else if (node_new->data < temp->data)
                {
                    temp=temp->left;
                }
                else if ((node_new->data > temp->data) && (temp->right==NULL))
                {
                    temp->right=node_new;
                      cout<<"Value inserted at right side"<<endl;
                    break;
                }
                else if (node_new->data > temp->data)
                {
                    temp=temp->right;
                }
            }
        }
    }

    node *search(int val)
    {
        if (root==NULL){
            return root;
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {
               if (val==temp->data)
               {
                return temp;
               }
               else if (val<temp->data)
               {
                temp=temp->left;
               }
               else 
               {
                temp=temp->right;
               }
            }
            return NULL;
        }
    }

    node* Delete(node *r,int value)
    {
        if (r==NULL){
            return NULL;
        }
        else if (value < r->data)
        {
            r->left = Delete(r->left,value);
        }
        else if (value > r->data)
        {
            r->right = Delete(r->right,value);
        }
        else 
        {
            if (r->left==NULL)
            {
                temp=r->right;
                delete r;
                return temp;
            }
            else if (r->right ==NULL)
            {
                temp=r->left;
                delete r;
                return temp;
            }
            else 
            {
                temp=minValueNode(r->right);
                r->data=temp->data;
                r->right = Delete(r->right,temp->data);
            }
        }
        return r;
    }

    node *minValueNode(node *node)
    {
        current = node;
        while (current->left!=NULL)
        {
            current=current->left;
        }
        return current;
    }

    void print (node *r,int space)
    {
        if (r==NULL){
            return;
        }
        space+=10;
        print(r->right, space);
        cout<<endl;
        for(int i=10; i<space;i++)
        {
            cout<<" ";
        }
        cout<<r->data<<endl;
        print(r->left,space);
    }

    void printINORDER(node *r)
    {
      if (r==NULL){
            return;
        }  
        printINORDER(r->left);
        cout<<r->data<<" ";
        printINORDER(r->right);
    }

    void printPOSTORDER(node *r)
    {
      if (r==NULL){
            return;
        }  
        printINORDER(r->left);
        printINORDER(r->right);
        cout<<r->data<<" ";
    }
};

int main()
{
tree t;
    int option, val;
    do
    {
        cout << endl;
        cout << "Select what operation you want to do" << endl;
        cout << "1. Insert Node()" << endl;
        cout << "2. Search Node()" << endl;
        cout << "3. Delete Node()" << endl;
        cout << "4. Print Tree()" << endl;
        cout << "5. Clear Screen()" << endl;
        cout << "0. Exit program" << endl
             << endl;
        cin >> option;
        node *new_node = new node(); // dynamic memory allocation

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT"<<endl;
            cout<<"Enter value to be inserted in tree"<<endl;
            cin>>val;
            new_node->data=val;
            t.insert(new_node);
            break;
        case 2:
            cout << "SEARCH"<< endl;
            cout<<"Enter value to search in tree"<<endl;
            cin>>val;
            new_node=t.search(val);
            if (new_node!=NULL)
            {
                cout<<"Value Found"<<endl;
            }
            else 
            {
                cout<<"Value NOT Found"<<endl;
            }
            break;
        case 3:
            cout << "DELETE"<<endl;
            cout<<"Enter value to delete from tree"<<endl;
            cin>>val;
            new_node=t.search(val);
            if (new_node!=NULL){
                t.Delete(t.root,val);
                cout<<"Value Deleted"<<endl;
            }
            else 
            {
                cout<<"Value NOT found"<<endl;
            }
            break;
        case 4:
            cout << "PRINT TREE" << endl;
            t.print(t.root,10);
            break;
        case 5:
            system("cls");
            break;

        default:
            cout<<"Enter a valid option"<<endl;
            break;
        }

    } while (option != 0);

    return 0;
}