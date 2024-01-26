#include <iostream>
using namespace std;

class Subtraction {
private:
    int stack[1000];  // Assuming a maximum of 1000 digits in the result
    int top;

public:
    Subtraction() {
        top = -1;
    }

    void push(int value) {
        stack[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1; // Return -1 for an empty stack
        } else {
            int temp = stack[top];
            stack[top] = -1;
            top--;
            return temp;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

Subtraction subtractingLargeNumbers(int num1, int num2) {
    Subtraction stack1, stack2, result_stack; 
    string str1 = to_string(num1);
    string str2 = to_string(num2);

    for (int i = 0; i < str1.size(); i++) {
        stack1.push(str1[i] - '0');
    }

    for (int i = 0; i < str2.size(); i++) {
        stack2.push(str2[i] - '0');
    }

    int borrow = 0;

    while (!stack1.isEmpty() || !stack2.isEmpty()) {
        int digit1 = 0, digit2 = 0;

        if (!stack1.isEmpty()) {
            digit1 = stack1.pop();
        }

        if (!stack2.isEmpty()) {
            digit2 = stack2.pop();
        }

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result_stack.push(diff);
    }

    return result_stack;
}

int main() {
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    Subtraction result_stack = subtractingLargeNumbers(num1, num2);

    cout << "Difference of " << num1 << " and " << num2 << " is: ";
    while (!result_stack.isEmpty()) {
        cout << result_stack.pop();
    }
    cout << endl;

    return 0;
}
