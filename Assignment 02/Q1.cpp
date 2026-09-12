#include <iostream>
#include <string>
using namespace std;

struct Stack {
    int top;
    int capacity;
    char* array;

    Stack(int size) {
        capacity = size;
        top = -1;
        array = new char[capacity];
    }
    
    void push(char item) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        array[++top] = item;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return '\0';
        }
        return array[top--];
    }
};

int main(){
    Stack st = Stack(1000000);
    int count = 0;
    string S;
    cin >> S;
    int status = 0;
    //0 for nothing, 1 for N, 2 for NJ

    for (char s :S){
        if (s == 'N'){
            status = 1;
            st.push(s);
        } else if (s == 'J'){
            if (status == 1){
                status = 2;
                st.push(s);
            }else{
                status = 0;
                st.push(s);
            }
        }else if (s == 'U'){
            if (status == 2){
                count++;
                st.pop();
                st.pop();
                if (st.top != -1 && st.array[st.top] == 'N'){
                    status = 1;
                } else if (st.top != -1 && st.array[st.top] == 'J' && st.array[st.top - 1] == 'N'){
                    status = 2;
                } else {
                    status = 0;
                }
            }else{
                status = 0;
                st.push(s);
            }
        }else {
            status = 0;
            st.push(s);
        }
    }
     
    cout << count << endl;
    delete[] st.array;

    return 0;

}