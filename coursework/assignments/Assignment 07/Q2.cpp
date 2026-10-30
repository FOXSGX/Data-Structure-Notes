#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    //通道
    vector<vector<int>> channels(K);
    for (int i = 0; i < K; i++) {
        int L;
        cin >> L;
        
        channels[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> channels[i][j];
        }
    }

    //指针数组
    vector<int> pts(K, 0);

    //最大堆
    priority_queue<tuple<int, int>> pq;
    for (int i = 0; i < K; i++) {
        if (!channels[i].empty()) {
            pq.emplace(channels[i][0], -i);
        }
    }

    while (!pq.empty()) {
        tuple<int, int> top = pq.top();
        pq.pop();
        int val, idx;
        tie(val, idx) = top;
        idx = -idx;                                 //取回原来的大小
        int pt = ++pts[idx];
        cout << val << ' ';

        if (pt < channels[idx].size()) {
            tuple<int, int> newitem{channels[idx][pt], -idx};
            pq.push(newitem);
        }
    }

    return 0;



    


}