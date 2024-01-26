#include <iostream>
#include <cmath>

using namespace std;

class Stack
{
private:
    int top;
    int size;

public:
    int stack[];
    Stack(int a)
    {
        size = a;
        int stack[size];
        top = -1;
        for (int i = 0; i < size; i++)
        {
            stack[i] = -1;
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

    int pop()
    {
        int temp1;
        if (isEmpty())
        {
            cout << "Stack under flow" << endl;
        }
        else
        {
            temp1 = stack[top];
            stack[top] = -1;
            top--;
        }
        return temp1;
    }

    void Result(string str)
    {
        int i = size;
        int temp1, temp2;
        int res;
        while (i>=0)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                push(str[i] - '0');
            }
            if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^')
            {
                temp2 = pop();
                temp1 = pop();
                if (str[i] == '+')
                    res = temp1 + temp2;
                if (str[i] == '-')
                    res = temp2 - temp1;
                if (str[i] == '*')
                    res = temp1 * temp2;
                if (str[i] == '/')
                    res = temp2 / temp1;
                if (str[i] == '^')
                    res = pow(temp2, temp1);
                cout<<"RESS"<<res<<endl;
                push(res);
            }
            i--;
        }
        cout << "Result is: " << res << endl;
    }

};

int main()
{
    string exp;
    cin >> exp; // 623+-382/+*2^3+
    int size = exp.size();
    Stack s(size);
    s.Result(exp);

    return 0;
}