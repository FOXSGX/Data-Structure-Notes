#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

struct Project {
    ll m;
    int b;
    bool operator<(const Project& other) const {return m < other.m;}

    Project(ll mm, int bb): m(mm), b(bb){};
};

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<Project> pq;
    for (int i = 0 ; i < n ; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        ll m = ai - bi;
        if (m > 0) pq.push(Project(m,bi));
    }


    ll sum = 0;
    for (int i = 0 ; i < k ; ++i) {
        if (pq.empty()) break;
        Project project = pq.top();
        pq.pop();
        sum += project.m;
        project.m -= 2*project.b;
        if (project.m > 0) pq.push(project);
    }

    cout << sum << endl;

    return 0;

}