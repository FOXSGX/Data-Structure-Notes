#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


void exec(vector<vector<int>>& input, int index, ll& sum, ll& minsum) {
    sum -= input[index][0];
    minsum = (minsum < sum) ? minsum : sum;
    if (input[index][2] != 0) {
        for (int i = 0; i < input[index][2] ; ++i) {
            exec(input, input[index][3+i], sum, minsum);
        }
    }
    sum += input[index][1];
}

int main() {
    int n, r;
    cin >> n >> r;

    vector<vector<int>> input(n+1);
    input[0] = vector<int>();
    for ( int i = 1; i <= n; ++i) {
        int ai, bi, ki;
        cin >> ai >> bi >> ki;
        input[i].resize(3+ki);
        input[i][0] = ai;
        input[i][1] = bi;
        input[i][2] = ki;
        if (ki > 0) {
            for (int j = 0; j < ki; ++j) {
                int child;
                cin >> child;
                input[i][3 + j] = child;
            }
        }
    }

    ll sum = 0, minsum = 0;
    exec(input, r, sum, minsum);

    cout << -minsum << endl;

    return 0;
}