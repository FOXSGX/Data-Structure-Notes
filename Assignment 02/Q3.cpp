#include <iostream>
using namespace std;

static const int N = 1000000007;

struct Px{
    int* a;
    bool isZero;
    Px(){
        int a[10]{};
        isZero = false;
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
};

struct Poly{
    int* exp;
    int* coef;
    Poly(){
        exp = new int[500];
        coef = new int[500];
    }
    Poly mul(const Poly& other){
        Poly res;
        for(int i = 0; i < 500; i++){
            res.coef[i] = 0;
            res.exp[i] = 0;
        }
        for(int i = 0; i < 500; i++){
            if(coef[i] == 0) continue;
            for(int j = 0; j < 500; j++){
                if(other.coef[j] == 0) continue;
                int new_exp = exp[i] + other.exp[j];
                int new_coef = (coef[i] * other.coef[j]) % N;
                res.coef[new_exp] = (res.coef[new_exp] + new_coef) % N;
                res.exp[new_exp] = new_exp;
            }
        }
        return res;
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
            cin >> polys[i].coef[j] >> polys[i].exp[j];
        }
    }

    for(int i = 0; i < q; i++){
        int x, y, z;
        cin >> x >> y >> z;

        pxs[x] = pxs[y] * pxs[z];
    }


    
}