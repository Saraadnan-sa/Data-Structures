#include <iostream>

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

    int prec(char c)
    {
        int prec;

        if (c == '+')
        {
            prec = 2;
        }
        else if (c == '-')
        {
            prec = 2;
        }
        else if (c == '*')
        {
            prec = 3;
        }
        else if (c == '/')
        {
            prec = 3;
        }
        else if (c == '^')
        {
            prec = 4;
        }
         else if (c == '(')
        {
            prec = 1;
        }
        return prec;
    }

    void Result(string str)
    {
        string res;
        char temp;
        int i = 0;
        while (size > (i))
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                res += str[i];
                i++;
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^' )
            {

                while (!isEmpty() && (prec(stack[top]) >= prec(str[i])))
                {
                    temp = pop();
                    res += temp;
                }

                push(str[i]);
                i++;
            }
            else if (str[i] == '('){
                 push(str[i]);
                 i++;
            }
            else if (str[i] == ')')
            {
                while (!isEmpty() && stack[top] != '(')
                {
                    temp = pop();
                    res += temp;
                }
                if (!isEmpty())
                {
                    pop();
                }
                i++;
            }
        }

        while (!isEmpty())
        {
            temp = pop();
            res += temp;
        }
        cout << "Result is: " << res << endl;
    }

};

int main()
{
    string exp;
    cin >> exp; // a+b/c*d-e/f
    int size = exp.size();
    Stack s(size);
    s.Result(exp);

    return 0;
}