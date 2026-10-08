#include <iostream>
#include <deque>
using namespace std;
using ll = long long;


int main()
{
    int n, k;
    cin >> n >> k;
    ll* pfs = new ll[n + 1];      //prefixSum
    pfs[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        pfs[i] = pfs[i - 1] + x;
    }

    deque<int> q;
    int p = 0;      //指针
    ll maxSum = 0;
    while (p < n)
    {
        while (!q.empty() && pfs[p] <= pfs[q.back()])
        {
            q.pop_back();
        }
        q.push_back(p);
        while (!q.empty() && p - q.front() + 1 > k)
        {
            q.pop_front();
        }
        maxSum = max(maxSum, pfs[++p] - pfs[q.front()]);
    }
    cout << maxSum << endl;

    return 0;
}