#include <iostream>
using namespace std;

//help function
void out(int a[],int last){
    if (last == -1){
        cout << "EMPTY" << "\n";
        return;
    }
    for (int i=0;i<last;i++){
        cout << a[i] << " ";
    }
    cout << a[last] << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //input
    int n, k;
    cin >> n >> k;

    int* a = new int[2000];
    int last = n-1;

    for (int i=0;i<n;i++){
        cin >> a[i];
    }


    //output
    char o;
    for (int _=0;_<k;_++){
        cin >> o;
        if (o == 'I'){
            int p,x;
            cin >> p >> x;
            p--;
            for (int i=last;i>=p;i--){
                a[i+1] = a[i];
            }
            a[p] = x;
            last++;
            out(a,last);
            cout << last-p << "\n";
        }
        if (o == 'D'){
            int p;
            cin >> p;
            p--;
            for (int i=p;i<last;i++){
                a[i] = a[i+1];
            }
            last--;
            out(a,last);
            cout << last-p+1 << "\n";
        }
    }

    delete[] a;
    return 0;
}