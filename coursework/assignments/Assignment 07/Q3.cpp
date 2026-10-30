#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int weight;
    char minasc;
    Node* Nchild;
    Node* Jchild;
    Node* Uchild;

    Node(int w, char asc): weight(w), minasc(asc),Nchild(nullptr), Jchild(nullptr), Uchild(nullptr) {}

    bool operator<(const Node& other) const {
        if (weight != other.weight) return weight < other.weight;
        return minasc > other.minasc;
    }

};

string read(Node* root, string& S) {
        string ans = "";
        Node* p = root;
        for (char op : S) {
            if (op == 'N') p = p->Nchild;
            if (op == 'J') p = p->Jchild;
            if (op == 'U') p = p->Uchild;

            if (p->Nchild == nullptr) {
                ans += p->minasc;
                p = root;
            }
        }
        return (p == root) ? ans : "INVALID";
    }

int main() {

    auto cmp = [](const Node* a, const Node* b) { return *a < *b; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < 27; i++) {
        int weight;
        cin >> weight;
        char asc = (i == 0) ? ' ' : 96+i;
        if (weight != 0) pq.push(new Node(weight, asc));
    }

    while (pq.size() > 1) {
        Node* newN = pq.top();
        pq.pop();
        Node* newJ = pq.top();
        pq.pop();
        Node* newU = pq.top();
        pq.pop();

        Node* newNode = new Node(newN->weight + newJ->weight + newU->weight, min({newN->minasc, newJ->minasc, newU->minasc}));
        newNode->Nchild = newN;
        newNode->Jchild = newJ;
        newNode->Uchild = newU;
        pq.push(newNode);
    }

    Node* root = pq.top();
    string S;
    cin >> S;

    cout << read(root, S) << endl;

    return 0;
}