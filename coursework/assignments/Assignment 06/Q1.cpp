#include <iostream>
#include <string>
using namespace std;

class BinaryTree {
public:
    char data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(char value) : data(value), left(nullptr), right(nullptr) {}

    static BinaryTree* build() {
        char x;
        cin >> x;

        if (x == '@')
            return new BinaryTree('@');

        BinaryTree* p = new BinaryTree(x);
        p->left = build();
        p->right = build();
        return p;
    }

    void read() {
        if (data == '@') {
            cout << "@" << " ";
            return;
        }
        left->read();
        right->read();
        cout << data << " ";
        return;
    }
};

int main() {
    BinaryTree* root = BinaryTree::build();
    root->read();

    return 0;
}
