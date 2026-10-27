#include "tree.h"

#include <queue>

BinaryTreeNode::BinaryTreeNode() : val(0), leftChild(nullptr), rightChild(nullptr) {}

BinaryTreeNode::BinaryTreeNode(int val) : val(val), leftChild(nullptr), rightChild(nullptr) {}

BinaryTreeNode::BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right)
    : val(val), leftChild(left), rightChild(right) {}

BinaryTree::BinaryTree() : root(nullptr), Refvalue(0) {}

BinaryTree::BinaryTree(int ref) : root(nullptr), Refvalue(ref) {}

BinaryTree::~BinaryTree() { clear(); }

void BinaryTree::clear() { destroy(root); }

void BinaryTree::destroy(BinaryTreeNode*& t) {
    if (t == nullptr) return;
    destroy(t->leftChild);
    destroy(t->rightChild);
    delete t;
    t = nullptr;
}

void BinaryTree::createFromStream(std::istream& in, int ref) {
    clear();
    Refvalue = ref;
    build(root, in, ref);
}

void BinaryTree::createFromPreorder(const std::vector<int>& pre, int ref) {
    clear();
    Refvalue = ref;
    int pos = 0;
    build(root, pre, pos, ref);
}

void BinaryTree::build(BinaryTreeNode*& t, std::istream& in, int ref) {
    int x;
    if (!(in >> x) || x == ref) {
        t = nullptr;
        return;
    }
    t = new BinaryTreeNode(x);
    build(t->leftChild, in, ref);
    build(t->rightChild, in, ref);
}

void BinaryTree::build(BinaryTreeNode*& t, const std::vector<int>& pre, int& pos, int ref) {
    if (pos >= static_cast<int>(pre.size()) || pre[pos] == ref) {
        ++pos;
        t = nullptr;
        return;
    }
    t = new BinaryTreeNode(pre[pos++]);
    build(t->leftChild, pre, pos, ref);
    build(t->rightChild, pre, pos, ref);
}

std::vector<int> BinaryTree::preOrder() const {
    std::vector<int> out;
    pre(root, out);
    return out;
}

std::vector<int> BinaryTree::inOrder() const {
    std::vector<int> out;
    in(root, out);
    return out;
}

std::vector<int> BinaryTree::postOrder() const {
    std::vector<int> out;
    post(root, out);
    return out;
}

std::vector<int> BinaryTree::levelOrder() const {
    std::vector<int> out;
    if (root == nullptr) return out;
    std::queue<BinaryTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode* cur = q.front();
        q.pop();
        out.push_back(cur->val);
        if (cur->leftChild != nullptr) q.push(cur->leftChild);
        if (cur->rightChild != nullptr) q.push(cur->rightChild);
    }
    return out;
}

void BinaryTree::printTree(std::ostream& os) const {
    if (root == nullptr) {
        os << "(空树)\n";
        return;
    }
    showTree(root, "", "", true, os);
}

void BinaryTree::showTree(BinaryTreeNode* t, const std::string& prefix,
                          const std::string& tag, bool isLast, std::ostream& os) {
    os << prefix << (tag.empty() ? "" : (isLast ? "└─" : "├─")) << tag << t->val << '\n';

    std::string childPrefix = prefix;
    if (!tag.empty()) childPrefix += isLast ? "   " : "│  ";

    const bool hasLeft = t->leftChild != nullptr;
    const bool hasRight = t->rightChild != nullptr;
    if (hasLeft) showTree(t->leftChild, childPrefix, "L: ", !hasRight, os);
    if (hasRight) showTree(t->rightChild, childPrefix, "R: ", true, os);
}

void BinaryTree::pre(BinaryTreeNode* t, std::vector<int>& out) {
    if (t == nullptr) return;
    out.push_back(t->val);
    pre(t->leftChild, out);
    pre(t->rightChild, out);
}

void BinaryTree::in(BinaryTreeNode* t, std::vector<int>& out) {
    if (t == nullptr) return;
    in(t->leftChild, out);
    out.push_back(t->val);
    in(t->rightChild, out);
}

void BinaryTree::post(BinaryTreeNode* t, std::vector<int>& out) {
    if (t == nullptr) return;
    post(t->leftChild, out);
    post(t->rightChild, out);
    out.push_back(t->val);
}
