#include "tree.h"

#include <cassert>
#include <cstdio>
#include <sstream>

static std::string treeText(const BinaryTree& t) {
    std::ostringstream os;
    t.printTree(os);
    return os.str();
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    const std::vector<int> pre = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    BinaryTree t(-1);
    t.createFromPreorder(pre, -1);

    // 四种遍历
    assert(t.preOrder() == (std::vector<int>{1, 2, 4, 5, 3}));
    assert(t.inOrder() == (std::vector<int>{4, 2, 5, 1, 3}));
    assert(t.postOrder() == (std::vector<int>{4, 5, 2, 3, 1}));
    assert(t.levelOrder() == (std::vector<int>{1, 2, 3, 4, 5}));

    // 树形输出
    assert(treeText(t) ==
           "1\n"
           "├─L: 2\n"
           "│  ├─L: 4\n"
           "│  └─R: 5\n"
           "└─R: 3\n");

    // 流式建树与上面等价
    std::istringstream in("1 2 4 -1 -1 5 -1 -1 3 -1 -1");
    BinaryTree t2(-1);
    t2.createFromStream(in, -1);
    assert(t2.inOrder() == t.inOrder());
    assert(treeText(t2) == treeText(t));

    // 单支链：全部只有左孩子
    BinaryTree chain(-1);
    chain.createFromPreorder({7, 8, 9, -1, -1, -1, -1}, -1);
    assert(chain.preOrder() == (std::vector<int>{7, 8, 9}));
    assert(treeText(chain) ==
           "7\n"
           "└─L: 8\n"
           "   └─L: 9\n");

    // 只有根
    BinaryTree single(-1);
    single.createFromPreorder({42, -1, -1}, -1);
    assert(single.preOrder() == (std::vector<int>{42}));
    assert(single.levelOrder() == (std::vector<int>{42}));
    assert(treeText(single) == "42\n");

    // 空树
    BinaryTree emptyTree(-1);
    std::istringstream emptyIn("-1");
    emptyTree.createFromStream(emptyIn, -1);
    assert(emptyTree.empty());
    assert(emptyTree.preOrder().empty());
    assert(emptyTree.levelOrder().empty());
    assert(treeText(emptyTree) == "(空树)\n");

    // clear 后可复用
    t.clear();
    assert(t.empty());
    t.createFromPreorder(pre, -1);
    assert(t.inOrder() == (std::vector<int>{4, 2, 5, 1, 3}));

    std::puts("tree ok");
    return 0;
}
