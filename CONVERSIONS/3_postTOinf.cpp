#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    int size;

public:
    char stack[];
    Stack(int a)
    {
        size = a;
        char stack[size];
        top = -1;
        for (int i = 0; i < size; i++)
        {
            stack[i] = '*';
        }
    }

    bool isEmpty()
    {
        if (top < 0)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if (top == size)
        {
            return true;
        }
        else
            return false;
    }

    void push(char val)
    {
        if (isFull())
        {
            cout << "Stack over flow" << endl;
        }
        else
        {
            top++;
            stack[top] = val;
            // cout<<stack[top]<<endl;
        }
    }

    char pop()
    {
        char temp1;
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            temp1 = stack[top];
            stack[top] = -1;
            top--;
        }
        return temp1;
    }

    bool isOperand(char c)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            return true;
        }
        else
            return false;
    }

    string postTOinf(string postfix)
    {
        string op1, op2, res;

        for (int i = 0; i < size; i++)
        {
            if (isOperand(postfix[i]))
            {
                push(postfix[i]);
            }
            else
            {
                op1 = pop();
                op2 = pop();
                
                if(op1=="*"){
                    op1=res;
                }
                res = ('(' + op2 + postfix[i] + op1 + ')');
                push('*');

            }
        }
        cout << "Infix expression is:" << res << endl;
    }
};

int main()
{

    string postfix, infix;
    cout << "Enter postfix expression\n";
    cin >> postfix;
    int size = postfix.size();
    Stack s(size);
    s.postTOinf(postfix);

    return 0;
}