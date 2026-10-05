#include <iostream>
#include <cassert>
#include "../string.cpp"
using namespace std;

int main(){
    String s;
    assert(s.length == 0);
    assert(s.data[0] == '\0');

    //cap=8:7 is full
    assert(s.append("abcdefg",7));
    assert(s.length==7);
    assert(s.data[7] == '\0');

    // 失败后内容和长度不变
    assert(!s.append("z", 1));
    assert(s.length == 7);
    assert(s.data[0] == 'a');
    assert(s.data[7] == '\0');

    // 内部 '\0' 仍计入显式长度
    const char raw[] = {'A', '\0', 'B'};
    String t;
    assert(t.append(raw, 3));
    assert(t.length == 3);
    assert(t.data[1] == '\0');
    assert(t.data[2] == 'B');
    assert(t.data[3] == '\0');
}