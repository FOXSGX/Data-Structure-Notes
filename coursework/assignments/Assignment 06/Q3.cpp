#include <iostream>
#include <string>
using namespace std;

struct Element {
    char value;          // 小写：知识点；大写：表名
    bool isDefinition;   // 此位置是否是输入中的 X(...)，便于后续打印
    Element* next;

    Element(char v, bool def) : value(v), isDefinition(def), next(nullptr) {}
};

struct Table {
    char name;
    Element* head = nullptr;
    Element* tail = nullptr;


    void build(const string& s, int& pos, Table* tables) {
        while (s[pos] != ')') {
            if (s[pos] == ',') {
                pos++;
            }
            else if (s[pos] >= 'a' && s[pos] <= 'z') {
                tables[name-'A'].append(s[pos], false);
                pos++;
            }
            else {
                char child = s[pos];
                pos++;
                if (s[pos] == '(') {
                    tables[name-'A'].append(child, true);
                    tables[child-'A'].build(s, ++pos,tables);
                }
                else {
                    tables[name-'A'].append(child, false);
                }
            }
        }
        pos++;
    }

    void append(char c, bool isDef) {
        if (head == nullptr) {
            head = tail = new Element(c,isDef);
        }
        else {
            tail->next = new Element(c,isDef);
            tail = tail->next;
        }
        return;
    }

    int seek(char x,Table* tables){
        Element* p = head;
        int count = 0;
        while (p != nullptr) {
            if (p->value >= 'a' && p->value <= 'z') {
                if (p->value == x) count++;
            }
            else {
                count += tables[p->value - 'A'].seek(x,tables);
            }
            p = p->next;
        }
        return count;
    }

    int deep(Table* tables){
        Element* p = head;
        int max_child_depth = 0;              //子表能提供的最大深度
        while (p != nullptr) {
            if (p->value >= 'a' && p->value <= 'z') {}
            else {
                max_child_depth = max(max_child_depth, tables[p->value - 'A'].deep(tables));
            }
            p = p->next;
        }
        return 1+max_child_depth;
    }

    void output(Table* tables) {
        cout << name << '(';
        Element* p = head;
        if (p == nullptr) {
            cout << ')';
            return;
        }
        while (p != nullptr && p->next != nullptr) {
            if (p->value >= 'a' && p->value <= 'z') {
                cout << p->value << ',';
            }
            else {
                if (p->isDefinition){
                    tables[p->value-'A'].output(tables);
                    cout << ',';
                }
                else cout << p->value << ',';
            }
            p = p->next;
        }
        if (p->value >= 'a' && p->value <= 'z') {
                cout << p->value;
            }
        else {
            if (p->isDefinition){
                tables[p->value-'A'].output(tables);
            }
            else cout << p->value;
        }
        cout << ')';
        return;
    }

    
};


int main() {
    Table* tables = new Table[26];        // tables['B' - 'A'] 就是表 B 的内容
    for (int i = 0; i < 26; i++) {
        tables[i].name = 'A'+i;
    }
    string input;
    cin >> input;
    char root = input[0];
    int pos = 2;
    tables[root-'A'].build(input,pos,tables);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int op;
        cin >> op;
        if (op == 1) {
            char X, Y;
            cin >> X >> Y;
            tables[Y - 'A'].append(X,false);
        }
        else if (op == 2) {
            char x;
            cin >> x;
            cout << tables[root - 'A'].seek(x, tables) << endl;
        }
        else if (op == 3) {
            char X;
            cin >> X;
            cout << tables[X-'A'].deep(tables) << endl;
        }


    }
    tables[root-'A'].output(tables);


    return 0;
}