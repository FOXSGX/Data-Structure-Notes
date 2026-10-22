#include <iostream>
using namespace std;

struct Node {
    int data;
    int row;
    int col;
    Node* right;
    Node* down;

    Node(int value) : data(value), row(0), col(0), right(nullptr), down(nullptr) {}

    Node(int value, int r, int c) : data(value), row(r), col(c), right(nullptr), down(nullptr) {}

    static void func1(int r, int c, int k, Node** rows_head, Node** cols_head) {
        Node* prev = rows_head[r];
        Node* curr = prev->right;
        while (curr && curr->col < c) {
            prev = curr;
            curr = curr->right;
        }
        if (curr && curr->col == c) {
            if (curr->data == -k) {
                Node* prev1 = cols_head[c];
                Node* curr1 = prev1->down;
                while (curr1 && curr1->row < r) {
                    prev1 = curr1;
                    curr1 = curr1->down;
                }
                prev1->down = curr1->down;
                curr1->down = nullptr;

                prev->right = curr->right;
                curr->right = nullptr;
                delete curr;
            } else {
                curr->data += k;
            }
        } else {
            Node* newNode = new Node(k);
            newNode->row = r;
            newNode->col = c;
            newNode->right = curr;
            prev->right = newNode;

            Node* prev1 = cols_head[c];
            Node* curr1 = prev1->down;
            while (curr1 && curr1->row < r) {
                prev1 = curr1;
                curr1 = curr1->down;
            }
            prev1->down = newNode;
            newNode->down = curr1;
        }

        return;
    }

    static void func2(int r, int c, Node** rows_head){
        Node* curr = rows_head[r]->right;
        while (curr && curr->col < c) {
            curr = curr->right;
        }
        if (curr && curr->col == c) {
            cout << curr->data << "\n";
        } else {
            cout << "0\n";
        }
    }

    static void func3(int c, Node** rows_head){
        Node* curr = rows_head[c];
        int col = 0;
        int res = 0;
        while (curr) {
            if (res < curr->data) {
                res = curr->data;
                col = curr->col;
            }
            curr = curr->right;
        }
        cout << col << " "  << res << "\n";
        return;
    }

    static void func4(int c, Node** cols_head){
        Node* curr = cols_head[c];
        int row = 0;
        int res = 0;
        while (curr) {
            if (res < curr->data) {
                res = curr->data;
                row = curr->row;
            }
            curr = curr->down;
        }
        cout << row << " "  << res << "\n";
        return;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, T, q;
    cin >> n >> m >> T >> q;

    Node** rows = new Node*[n+1];
    Node** cols = new Node*[m+1];
    rows[0] = nullptr;
    cols[0] = nullptr;
    for (int i = 1; i <= n; ++ i) {
        rows[i] = new Node(-1);
    }
    for (int i = 1; i <= m; ++ i) {
        cols[i] = new Node(-1);
    }

    Node** rows_head = new Node*[n+1];
    Node** cols_head = new Node*[m+1];
    rows_head[0] = nullptr;
    cols_head[0] = nullptr;
    for (int i = 1; i <= n; ++ i) {
        rows_head[i] = rows[i];
    }
    for (int i = 1; i <= m; ++ i) {
        cols_head[i] = cols[i];
    }





    for (int t = 0; t < T; ++t) {
        int r, c, v;
        cin >> r >> c >> v;
        rows[r]->right = new Node(v, r, c);
        rows[r] = rows[r]->right;
        cols[c]->down = rows[r];
        cols[c] = cols[c]->down;
    }

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int r, c, k;
            cin >> r >> c >> k;
            Node::func1(r, c, k, rows_head, cols_head);
        } else if (op == 2) {
            int r, c;
            cin >> r >> c;
            Node::func2(r, c, rows_head);
        } else if (op == 3) {
            int c;
            cin >> c;
            Node::func3(c, rows_head);
        } else if (op == 4) {
            int c;
            cin >> c;
            Node::func4(c, cols_head);
        }
    }

    delete[] rows;
    delete[] cols;
    delete[] rows_head;
    delete[] cols_head;
    return 0;
}