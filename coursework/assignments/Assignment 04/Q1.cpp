#include <iostream>
#include <deque>
using namespace std;

struct Whale{
    int id;
    long long hunger;
    static int present_id;

    Whale(long long s){
        id = present_id;
        present_id++;
        hunger = s;
    }
};

int Whale::present_id = 1;

void adjust(deque<Whale>& que,Whale whale) {
    int count = 0;
    while (!que.empty()) {
        if (que.back().hunger < whale.hunger) {
            que.pop_back();
            count++;
        }
        else break;
    }
    que.push_back(whale);
    cout << count << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    deque<Whale> que;

    for (int i = 0 ; i < q ; i++) {
        int event;
        cin >> event;

        if (event == 1) {
            long long s;
            cin >> s;
            Whale whale(s);
            adjust(que,whale);
        }
        else if (event == 2) {
            cout << que.front().id << '\n';
            que.pop_front();
        }
    }

    return 0;
}