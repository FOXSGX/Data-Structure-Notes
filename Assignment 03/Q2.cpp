#include <iostream>
using namespace std;

struct CirNode;

static bool direct = 0;         //0 for clockwise, 1 for the opposite
static int k = 0;
static CirNode* p = nullptr;

struct CirNode{
    int num;
    int val;
    CirNode* prev;
    CirNode* next;

    CirNode(int i, int x){
        num = i;
        val = x;
        prev = nullptr;
        next = nullptr;
    }

    int pop(){
        if (val > 0){
            k = val;
            direct = 0;
            p = prev;
            if (prev != nullptr){
                prev->next = next;
            }
            if (next != nullptr){
                next->prev = prev;
            }
            return num;
        }
        else{
            k = -val;
            direct = 1;
            p = next;
            if (prev != nullptr){
                prev->next = next;
            }
            if (next != nullptr){
                next->prev = prev;
            }
            return num;
        }
    }

};



int main(){
    //initialize
    int n;
    cin >> n >> k;

    CirNode* dum = new CirNode(0,0) ;       //dummy head
    p = dum;
    for (int i = 1 ; i <= n ; i++) {
        int a;
        cin >> a;
        CirNode* node = new CirNode(i, a);
        p->next = node;
        node->prev = p;
        p = node;
    }
    p->next = dum->next;
    dum->next->prev = p;
    delete dum;

    //main cycle
    for (int i = 0 ; i < n ; i++){
        if (!direct){
            for (int i = 0 ; i < k ; i++){
                p = p->next;
            }
        }
        else {
            for (int i = 0 ; i < k ; i++){
                p = p->prev;
            }
        }

        cout << p->pop();
    }
    cout << endl;
    delete p;

    return 0;    


}