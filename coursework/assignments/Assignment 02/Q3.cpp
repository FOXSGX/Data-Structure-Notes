#include <iostream>
using namespace std;

static const int N = 1000000007;

struct Px{
    int* a;
    bool isZero;
    Px(){
        a = new int[10];
        for(int i = 0; i < 10; i++){
            a[i] = 0;
        }
        isZero = false;
    }
    Px(const Px& other) {
        a = new int[10];
        for (int i = 0; i < 10; i++) {
            a[i] = other.a[i];
        }
        isZero = other.isZero;
    }
    Px& operator=(const Px& other) {
        if (this != &other) {
            for (int i = 0; i < 10; i++) {
                a[i] = other.a[i];
            }
            isZero = other.isZero;
        }
        return *this;
    }
    Px operator*(const Px& other) const {
        Px res;
        if (isZero || other.isZero){
            res.isZero = true;
            return res;
        }
        int count = 0;
        for(int i = 0; i < 10; i++){
            res.a[i] = a[i] + other.a[i];
            count += res.a[i];
        }
        if (count > 500){
            res.isZero = true;
        }
        return res;

    }
    ~Px(){
        delete[] a;
    }
};
    

struct Poly{
    int* coef;
    Poly(){
        coef = new int[501];
        for(int i = 0; i <= 500; i++){
            coef[i] = 0;
        }
    }
    Poly(const Poly& other) {
        coef = new int[501];
        for (int i = 0; i <= 500; i++) {
            coef[i] = other.coef[i];
        }
    }
    Poly& operator=(const Poly& other) {
        if (this != &other) {
            for (int i = 0; i <= 500; i++) {
                coef[i] = other.coef[i];
            }
        }
        return *this;
    }
    Poly mul(const Poly& other){
        Poly res;
        for(int i = 0; i <= 500; i++){
            if(coef[i] == 0) continue;
            for(int j = 0; i + j <= 500; j++){
                if(other.coef[j] == 0) continue;
                res.coef[i+j] = (res.coef[i+j] + (long long)coef[i] * other.coef[j] ) % N;
            }
        }
        return res;
    }
    Poly pow(int x){
        Poly res;
        res.coef[0] = 1;
        Poly a;
        for(int i = 1; i <= 500; i++){
            a.coef[i] = coef[i];
        }
        while (x) {
            if (x & 1) res = res.mul(a);
            a = a.mul(a);
            x >>= 1;
        }
        return res;
    }
    void print(){
        bool printed = false;
        for (int i = 500; i > 0; i--){
            if (coef[i] == 0) continue;
            cout << i << ' ' << coef[i] << '\n';
            printed = true;
        }
        if (!printed) cout << 0 << '\n';
        return;
    }
    ~Poly(){
        delete[] coef;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, q;
    cin >> k >> q;

    Poly* polys = new Poly[k];
    Px* pxs = new Px[k];
    for (int i = 0; i < k; i++){
        pxs[i].a[i] = 1;
    }


    //record the initial polynomials
    for(int i = 0; i < k; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int c, e;
            cin >> c >> e;
            polys[i].coef[e] = c;
        }
    }

    for(int i = 0; i < q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;

        pxs[x] = pxs[y] * pxs[z];
    }

    for(int i = 0; i < k; i++){
        if (pxs[i].isZero) {
            cout << 0 << '\n';
            continue;
        }
        Poly poly;
        poly.coef[0] = 1;
        for(int j = 0; j < k; j++){
            if (pxs[i].a[j]==0) continue;
            poly = poly.mul(polys[j].pow(pxs[i].a[j]));
        }
        poly.print();
    }

    delete[] polys;
    delete[] pxs;

    return 0;




    
}
