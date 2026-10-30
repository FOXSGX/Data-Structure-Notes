#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node* leftchild;
    Node* rightchild;

    Node(): val(0), leftchild(nullptr), rightchild(nullptr){}
    Node(int v): val(v), leftchild(nullptr), rightchild(nullptr){}
    Node(int v, Node* left, Node* right): val(v), leftchild(left), rightchild(right){}
};

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int preL, int preR,
                int inL, int inR, const unordered_map<int, int>& map) {
    if (preL == preR) return nullptr;

    int rootval = preorder[preL];
    Node* root = new Node(rootval);
    
    int idx = map.at(rootval);

    int leftsize = idx - inL;
    int rightsize = inR - idx - 1;

    root->leftchild = buildTree(preorder, inorder, preL+1, preL+1+leftsize, inL, idx, map);
    root->rightchild = buildTree(preorder, inorder, preL+1+leftsize, preL+1+leftsize+rightsize, idx+1, idx+1+rightsize, map);

    return root;
}

void print(Node* root) {
    if (root == nullptr) return;
    print(root->leftchild);
    print(root->rightchild);
    cout << root->val << ' ';
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n);
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    unordered_map<int, int> map;
    map.reserve(n);

    for (int i = 0; i < n; ++i) {
    map[inorder[i]] = i;
    }

    Node* root = buildTree(preorder, inorder, 0, n, 0, n, map);

    print(root);

    cout << endl;

    return 0;

}