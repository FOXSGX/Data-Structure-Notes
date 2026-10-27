#pragma once

#include <iostream>
#include <string>
#include <vector>

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;

    BinaryTreeNode();
    BinaryTreeNode(int val);
    BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right);
};

class BinaryTree {
    protected:
        BinaryTreeNode* root;
        int Refvalue;                    // 建树时空子树的标记值

    public:
        BinaryTree();
        explicit BinaryTree(int ref);
        ~BinaryTree();

        BinaryTree(const BinaryTree&) = delete;                 //禁止拷贝构造和操作符重载
        BinaryTree& operator=(const BinaryTree&) = delete;

        // 按前序序列建树，读到 Refvalue 表示该位置为空
        void createFromStream(std::istream& in, int ref);
        void createFromPreorder(const std::vector<int>& pre, int ref);

        void clear();
        bool empty() const { return root == nullptr; }
        BinaryTreeNode* getRoot() const { return root; }

        // 遍历，返回访问序列，方便写算法时对照
        std::vector<int> preOrder() const;
        std::vector<int> inOrder() const;
        std::vector<int> postOrder() const;
        std::vector<int> levelOrder() const;

        // 树形打印：每个结点一行，L/R 表示是左/右孩子
        void printTree(std::ostream& os = std::cout) const;

    private:
        static void destroy(BinaryTreeNode*& t);
        static void build(BinaryTreeNode*& t, std::istream& in, int ref);
        static void build(BinaryTreeNode*& t, const std::vector<int>& pre, int& pos, int ref);
        static void pre(BinaryTreeNode* t, std::vector<int>& out);
        static void in(BinaryTreeNode* t, std::vector<int>& out);
        static void post(BinaryTreeNode* t, std::vector<int>& out);
        static void showTree(BinaryTreeNode* t, const std::string& prefix,
                             const std::string& tag, bool isLast, std::ostream& os);
};
