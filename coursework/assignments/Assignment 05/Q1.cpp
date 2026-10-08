#include <iostream>
using namespace std;

struct Triple
{
    int row;
    int col;
    int value;

    Triple() : row(0), col(0), value(0) {}
    Triple(int r, int c, int v) : row(r), col(c), value(v) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, q;
    cin >> n >> m >> p >> q;
    Triple* A = new Triple[p];
    Triple* B = new Triple[q];
    for (int i = 0; i < p; i++)
    {
        int r, c, v;
        cin >> r >> c >> v;
        A[i] = Triple(r, c, v);
    }
    for (int i = 0; i < q; i++)
    {
        int r, c, v;
        cin >> r >> c >> v;
        B[i] = Triple(r, c, v);
    }


    Triple* C = new Triple[p + q];
    int k = 0;
    int i = 0, j = 0;
    while (i < p && j < q)
    {
        if (A[i].row < B[j].row)
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else if (A[i].row > B[j].row)
        {
            C[k] = B[j];
            j++;
            k++;
        }
        else
        {
            if (A[i].col < B[j].col)
            {
                C[k] = A[i];
                i++;
                k++;
            }
            else if (A[i].col > B[j].col)
            {
                C[k] = B[j];
                j++;
                k++;
            }
            else
            {   
                if (A[i].value + B[j].value != 0)
                {
                    C[k] = Triple(A[i].row, A[i].col, A[i].value + B[j].value);
                    i++;
                    j++;
                    k++;
                }
                else
                {
                    i++;
                    j++;
                }
                
            }
        }
    }
    while (i < p)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j < q)
    {
        C[k] = B[j];
        j++;
        k++;
    }
    //Print the result
    cout << k << '\n';
    if (k != 0)
    {
        for (int i = 0; i < k; i++)
        {
            cout << C[i].row << " " << C[i].col << " " << C[i].value << '\n';
        }
    }

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}