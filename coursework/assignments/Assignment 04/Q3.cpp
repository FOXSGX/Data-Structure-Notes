#include <iostream>
using namespace std;

bool check(int n, int k, int* whales, long long X){
    int* stack = new int[n];
    int top = -1;                //stack top pointer
    long long sum = 0;
    int groups = 1;

    for (int i = 0; i < n;i++) {
        int wh = whales[i];
        long long add = 0;

        while (top != -1 && wh > stack[top]) {
            top--;
            add++;
        }
        if (top != -1) add++;
        if (sum + add <= X) {
            stack[++top] = wh;
            sum += add;
        }
        else{
            groups++;
            top = -1;       //clean the stack
            sum = 0;
            stack[++top] = wh;
        }
    }

    if (groups <= k) return true;       
    else return false;

}

int main() {
    //input
    int n, k;
    cin >> n >> k;
    int* whales = new int[n];       //record heights
    for (int i = 0;i < n; i++){
        cin >> whales[i];
    }
    

    long long l = 0;
    long long r = 1LL * n * (n-1) / 2;

    while (l < r) {
        long long mid = (l + r) / 2;

        if (check(n,k,whales,mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << endl;

    return 0;
}