#include "tree.h"

#include <iostream>

// 输入：一行整数，按前序给出二叉树结点，-1 表示空子树
// 输出：前序 / 中序 / 后序 / 层次四行遍历结果
void print(const std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) std::cout << (i ? " " : "") << v[i];
    std::cout << '\n';
}

int main() {
    BinaryTree t(-1);
    t.createFromStream(std::cin, -1);

    t.printTree();
    print(t.preOrder());
    print(t.inOrder());
    print(t.postOrder());
    print(t.levelOrder());
    return 0;
}
