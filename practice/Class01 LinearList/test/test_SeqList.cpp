#include <cassert>
#include <iostream>
#include <sstream>

#include "SeqList.h"

int main() {
    SeqList<int> list(5);

    assert(list.Size() == 5);
    assert(list.IsEmpty());
    assert(!list.IsFull());
    assert(list.Length() == 0);

    list.Insert(1, 10);
    list.Insert(2, 20);
    list.Insert(3, 30);

    assert(!list.IsEmpty());
    assert(list.Length() == 3);
    assert(*list.getData(1) == 10);
    assert(*list.getData(2) == 20);
    assert(*list.getData(3) == 30);

    list.setData(2, 25);
    assert(*list.getData(2) == 25);

    int value = 0;
    assert(list.Find(1, value));
    assert(value == 10);
    assert(list.Find(2, value));
    assert(value == 25);
    assert(list.Search(25) == 2);

    list.Insert(2, 15);
    assert(list.Length() == 4);
    assert(*list.getData(1) == 10);
    assert(*list.getData(2) == 15);
    assert(*list.getData(3) == 25);
    assert(*list.getData(4) == 30);

    list.Remove(3);
    assert(list.Length() == 3);
    assert(*list.getData(1) == 10);
    assert(*list.getData(2) == 15);
    assert(*list.getData(3) == 30);

    SeqList<int> copied(5);
    copied = list;
    assert(copied.Length() == list.Length());
    assert(*copied.getData(1) == 10);
    assert(*copied.getData(2) == 15);
    assert(*copied.getData(3) == 30);

    std::ostringstream out;
    copied.Output(out);
    assert(!out.str().empty());

    std::cout << "SeqList tests passed." << std::endl;
    return 0;
}
