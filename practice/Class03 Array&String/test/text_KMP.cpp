#include "../KMP.cpp"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
    string s1 = "abcabcabc";
    cout << s1 << endl;
    for (int x : buildNEXT(s1)){
        cout << x << endl;
    }
    string s2 = "abaabcac";
    cout << s2 << endl;
    for (int x : buildNEXT(s2)){
        cout << x << endl;
    }

    string s3 = "abc";

    cout << "KMP" << endl;
    assert(kmp_find(s1,s2) == -1);
    assert(kmp_find(s1,s3) == 0);

    return 0;
}