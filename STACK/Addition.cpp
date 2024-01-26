#include <iostream>
using namespace std;

class CustomStack {
private:
    int stack[1000];  // Assuming a maximum of 1000 digits in the result
    int top;

public:
    CustomStack() {
        top = -1;
    }

    void push(int value) {
        stack[++top] = value;
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
            stack[top--] = -1;
            // top--;
        }
        return temp1;
    }


    bool isEmpty() {
        return top == -1;
    }
};
CustomStack addingLargeNumbers(int num1, int num2) {
    CustomStack stack1, stack2, result_stack;
    string str1 = to_string(num1);
    string str2 = to_string(num2);

    for (int i = 0 ; i <str1.size(); i++) {
        stack1.push(str1[i] - '0');
    }

    for (int i = 0; i < str2.size(); i++) {
        stack2.push(str2[i] - '0');
    }

    int carry = 0;

    while (!stack1.isEmpty() || !stack2.isEmpty()) {
        int digit1 = 0, digit2 = 0;

        if (!stack1.isEmpty()) {
            digit1 = stack1.pop();
        }

        if (!stack2.isEmpty()) {
            digit2 = stack2.pop();
        }

        int sum = digit1 + digit2 + carry;
        result_stack.push(sum % 10);
        carry = sum / 10;
    }

    if (carry != 0) {
        result_stack.push(carry);
    }

    return result_stack;
}

int main() {
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    CustomStack result_stack = addingLargeNumbers(num1, num2);

    cout << "Sum of " << num1 << " and " << num2 << " is: ";
    while (!result_stack.isEmpty()) {
        cout << result_stack.pop();
    }
    cout << endl;

    return 0;
}
