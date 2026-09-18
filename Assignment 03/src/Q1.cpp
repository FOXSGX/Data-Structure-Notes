#include <iostream>
using namespace std;

struct Stack{
    
    int top;
    int capacity;
    int* arr;

    Stack(int size) {
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1; // Return an invalid value to indicate underflow
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1; // Return an invalid value to indicate empty stack
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    bool ans = true;
    int n;
    cin >> n;
    int* out = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> out[i];
    }

    Stack s(n);
    int x = 0;     //index of out
    for (int i = 1; i <= n; i++) {
        if (s.isEmpty() || s.peek() <= out[x]) {
            s.push(i);
        }
        while (!s.isEmpty() && x < n && s.peek() == out[x]){
            s.pop();
            x++;
        }
        if (!s.isEmpty() && s.peek() > out[x]){
            ans = false;
            break;
        }   
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    delete[] out;

    return 0;

}