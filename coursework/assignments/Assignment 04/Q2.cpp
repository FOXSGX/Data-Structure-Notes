#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;
//统计各字符数量
void count(array<int,26>& cnt,string s){
    for (char c : s){
        cnt[c - 'a']++;
    }
    return;
}

//找到不可能字符
string find_impossible(array<int,26>& cnt,int k){
    string ans;
    for (int i = 0;i < 26;i++){
        if (cnt[i] < k && cnt[i] > 0){
            ans += ('a'+i);
        }
    }
    return ans;
}

//分割字符串
vector<string> split(string s, string delims) {
    vector<string> res;
    string cur;

    for (char c : s) {
        if (delims.find(c) != string::npos) {
            if (!cur.empty()) {
                res.push_back(cur);
                cur.clear();
            }
        } else {
            cur += c;
        }
    }

    if (!cur.empty()) {
        res.push_back(cur);
    }

    return res;
}



int func(string s, int k) {
    if (k > s.length()) {
        return 0;
    }

     array<int,26> cnt{};
     count(cnt,s);
     string impo = find_impossible(cnt, k);
     if (impo.empty()) {
        return s.length();
     }
     else {
        int ans = 0;
        vector<string> v = split(s, impo);
        for (string ss : v) {
            ans = max(ans, func(ss, k));
        }
        return ans;
     }
}






int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    cout << func(s, k) << endl;
   
    // //test
    // array<int,26> cnt{};
    // string s = "aabbccdd";
    // cout << func(s, 2) << endl;

    return 0;
}