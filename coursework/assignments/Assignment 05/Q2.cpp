#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> buildNEXT(const string& s){
    if (s.empty()) return {};
    vector<int> next(s.size());
    next[0] = -1;
    int j = 0;
    int k = -1;

    while (j+1 < s.size()){
        if (k == -1 || s[j] == s[k] || s[j] == '.' || s[k] == '.'){
            j++;
            k++;
            next[j] = k;
        }
        else{
            k = next[k];
        }
    }
    return next;
}

vector<int> kmp_find(const string& main,const string& pattern){
    if (pattern.empty()) return {};

    vector<int> result;
    vector<int> next = buildNEXT(pattern);
    int i = 0;      //主串指针
    int j = 0;      //模式串指针

    while (i < main.size() && j < pattern.size()){
        if (main[i] == pattern[j] || main[i] == '.' || pattern[j] == '.'){
            if (j == pattern.size() -1) {
                result.push_back(i - j + 1);
                if (j == 0) {
                    i++;
                }
                else{
                    j = next[j];
                }
            }
            else{
                i++;
                j++;
            }
        }
        else if(j == 0) {
            i++;
        }
        else{
            j = next[j];
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string S,P;
    cin >> S >> P;

    vector<int> result = kmp_find(S, P);

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}