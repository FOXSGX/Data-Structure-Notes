#include <iostream>
using namespace std;

struct Stack {
    int top;
    int capacity;
    int* array;

    Stack() {
        capacity = 8; // Default capacity
        top = -1;
        array = new int[capacity];
    }

    Stack(int x){
        capacity = 8;
        top = 0;
        array = new int[capacity];
        array[0] = x;
    }
    
    ~Stack() {
    delete[] array;
}

    void push(int item) {
        if (top == capacity - 1) {
            resize();
        }
        array[++top] = item;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return array[top--];
    }

    int remove(int item){
        int index = -1;
        for (int i = 0; i <= top; i++){
            if (array[i] == item){
                index = i;
                break;
            }
        }
        if (index == -1){
            cout << "Item not found" << endl;
            return 0;
        }
        for (int i = index; i < top; i++){
            array[i] = array[i + 1];
        }
        top--;
        return item;
    }

    int index(int item){
        for (int i = 0; i <= top; i++){
            if (array[i] == item){
                return i;
            }
        }
        return -1;
    }

    void resize() {
        int* new_array = new int[capacity * 2];
        for (int i = 0; i <= top; i++) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        capacity = capacity * 2;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    int* pos = new int[n+1];      //recording the position of each card
    Stack** Stacks = new Stack*[n+1];
    for (int i = 1; i <= n; i++){
        pos[i] = i;
        Stacks[i] = new Stack(i);
    }

    for (int _=0;_<m;_++){
        int o, x, p;
        cin >> o;
        if (o == 1){
            cin >> x >> p;
            Stacks[p]->push(x);
            Stacks[pos[x]]->remove(x);
            pos[x] = p;
        }else if (o == 2){
            cin >> x;
            int ind = Stacks[pos[x]]->index(x);
            int up = 0, down = 0;
            if (ind > 0){
                down = Stacks[pos[x]]->array[ind-1];
            }
            if (ind < Stacks[pos[x]]->top){
                up = Stacks[pos[x]]->array[ind+1];
            }
            cout << up << " " << down << '\n';
        }
    }

    delete[] pos;
    for (int i = 1; i <= n; i++){
        delete Stacks[i];
    }
    delete[] Stacks;

    return 0;
}