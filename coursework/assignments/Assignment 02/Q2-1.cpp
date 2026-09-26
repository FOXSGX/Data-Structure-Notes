#include <iostream>
using namespace std;

struct card{  
    int value;
    int pos;
    card* up;
    card* down;
    card(int i): value(i), pos(i), up(nullptr), down(nullptr) {}
    ~card() {
        if (up != nullptr) {
            up->down = down;
        }
        if (down != nullptr) {
            down->up = up;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    card** cards = new card*[n+1];  //cards[0] is dummy
    card** top = new card*[n+1];      //recording the position of each card
    for (int i = 1; i <= n; i++){
        top[i] = cards[i] = new card(i);
    }

    for (int _=0;_<m;_++){
        int o, x, p;
        cin >> o;
        if (o == 1){
            cin >> x >> p;
            card* c = cards[x];
            int oldPos = c->pos;
            if (c->up != nullptr) {
                c->up->down = c->down;
            } else {
                // c 原来是栈顶
                top[oldPos] = c->down;
            }
            if (c->down != nullptr) {
                c->down->up = c->up;
            }
            c->up = nullptr;
            c->down = top[p];
            if (top[p] != nullptr) {
                top[p]->up = c;
            }
            top[p] = c;
            c->pos = p;
        }else if (o == 2){
            cin >> x;
            card* c = cards[x];
            int up = 0, down = 0;
            if (c->up != nullptr){
                up = c->up->value;
            }
            if (c->down != nullptr){
                down = c->down->value;
            }
            cout << up << " " << down << '\n';
        }
    }

    for (int i = 1; i <= n; i++) {
        delete cards[i];
    }
    delete[] cards;
    delete[] top;
    return 0;
}