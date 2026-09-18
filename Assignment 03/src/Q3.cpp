#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Stack{
    int top;
    int capacity;
    T* arr;

    Stack(int size) {
        capacity = size;
        top = -1;
        arr = new T[capacity];
    }

    void push(T x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1; // Return an invalid value to indicate underflow
        }
        return arr[top--];
    }

    T peek() {
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

int isp(char c) {
    switch (c) {
        case '#':
            return 0;

        case '(':
            return 1;

        case '+':
        case '-':
            return 3;

        case '*':
        case '/':
            return 5;

        case '^':
            return 6;

        case '~':
            return 8;
        case ')':
            return 11;

        default:
            return -1;
    }
}

int icp(char c) {
    switch (c) {
        case '#':
            return 0;

        case '(':
            return 10;

        case '+':
        case '-':
            return 2;

        case '*':
        case '/':
            return 4;

        case '^':
            return 7;

        case '~':
            return 9;

        case ')':
            return 1;

        default:
            return -1;
    }
}

long long Pow(long long base, long long exponent) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }

        exponent /= 2;

        if (exponent > 0) {
            base *= base;
        }
    }

    return result;
}
long long calculate(long long a, long long b, char op){
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return Pow(a,b);
    }
}
int main(){
    //initialize
    string input;
    getline(cin >> ws,input);
    input += '#';
    string s = "";  //后缀表达式
    Stack<char> st0(10000);
    st0.push('#');

    //中缀转后缀
    for (char ch : input) {
        if (icp(ch) < 0){
            s += ch;
        }
        else{
            char op = st0.peek();
            while (icp(ch) <= isp(op)) {
                if (icp(ch) < isp(op)) {
                    s += st0.pop();
                    op = st0.peek();
                }
                else{
                    char pop = st0.pop();
                    if (pop == '(' || pop == '#'){
                        break;
                    }
                    else op = st0.peek();
                }
            }
            if (icp(ch) > isp(op)) {
                st0.push(ch);
            }
            
        }
    }

    Stack<long long> st1(10000);
    for (char ch : s){
        if (icp(ch) < 0) {
            st1.push(static_cast<long long>(ch - '0'));
        }
        else if (ch == '~'){
            long long a = st1.pop();
            st1.push(-a);
        }
        else {
            long long right = st1.pop();
            long long left = st1.pop();
            long long result = calculate(left, right, ch);
            st1.push(result);
        }
    }
    cout << st1.peek() << endl;

    return 0;
}