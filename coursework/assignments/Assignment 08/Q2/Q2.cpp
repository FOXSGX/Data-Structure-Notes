#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    int leftchild = 0;
    int rightchild = 0;
    int ltag = 1;
    int rtag = 1;

    Node(int v) : val(v) {};
};

Node* NUL = new Node(0);

//线索化
void build(Node* cur, Node*& pre, unordered_map<int, Node*>& m) {
    if (cur == NUL) return;
    build(m[cur->leftchild], pre, m);
    if (cur->leftchild == 0) {
        cur->leftchild = pre->val;
        cur->ltag = 1;
    }
    if (pre != NUL && pre->rightchild == 0) {
        pre->rightchild = cur->val;
        pre->rtag = 1;
    }
    pre = cur;
    build(m[cur->rightchild], pre, m);
}


int main() {
    int n, q, r;
    cin >> n >> q >> r;
    unordered_map<int, Node*> m;
    m[0] = NUL;

    //input
    for (int i = 1 ; i <= n ; ++i) {
        int li, ri;
        cin >> li >> ri;
        Node* newNode = new Node(i);
        if (li != 0) {
            newNode->leftchild = li;
            newNode->ltag = 0;
        }
        if (ri != 0) {
            newNode->rightchild = ri;
            newNode->rtag = 0;
        }
        m[i] = newNode;
    }

    //线索化初始树
    Node* pre = NUL;
    build(m[r], pre, m);

    //output
    for (int i = 0 ; i < q ; ++i) {
        char op;
        int x;
        cin >> op >> x;

        if (op == 'L') {
            Node* newNode = new Node(++n);
            //维护newNOde的前驱后继
            newNode->leftchild = m[x]->leftchild;
            newNode->rightchild = x;
            //维护x的前驱的后继
            if (m[m[x]->leftchild]->rtag == 1) m[m[x]->leftchild]->rightchild = n;
            //维护x的前驱
            m[x]->leftchild = n;
            m[x]->ltag = 0;
            
            m[n] = newNode;
        }

        if (op == 'R') {
            Node* newNode = new Node(++n);
            //维护newNOde的前驱后继
            newNode->leftchild = x;
            newNode->rightchild = m[x]->rightchild;
            //维护x的后继的前驱
            if (m[m[x]->rightchild]->ltag == 1) m[m[x]->rightchild]->leftchild = n;
            //维护x的后继
            m[x]->rightchild = n;
            m[x]->rtag = 0;
            
            m[n] = newNode;
        }

        if (op == 'Q') {
            cout << m[x]->ltag << " " << m[x]->leftchild << " " << m[x]->rtag << " " << m[x]->rightchild << endl;
        }
    }

    return 0;
}