#include <cassert>
#include <stdexcept>
#include <utility>

#include "CircList.h"

int main()
{
    CircList<int> list;
    assert(list.empty());
    assert(list.size() == 0);

    list.push_back(2);
    list.push_front(1);
    list.push_back(3);
    assert(!list.empty());
    assert(list.size() == 3);
    assert(list.front() == 1);
    assert(list.back() == 3);

    list.pop_front();
    assert(list.front() == 2);
    assert(list.back() == 3);

    list.pop_back();
    assert(list.front() == 2);
    assert(list.back() == 2);
    assert(list.size() == 1);

    CircList<int> copied(list);
    copied.push_back(4);
    assert(copied.front() == 2);
    assert(copied.back() == 4);
    assert(list.back() == 2);

    CircList<int> assigned;
    assigned = copied;
    assert(assigned.size() == 2);
    assert(assigned.front() == 2);
    assert(assigned.back() == 4);

    CircList<int> moved(std::move(assigned));
    assert(moved.size() == 2);
    assert(moved.front() == 2);
    assert(moved.back() == 4);
    assert(assigned.empty());

    moved.clear();
    assert(moved.empty());

    bool threw = false;
    try {
        moved.front();
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    return 0;
}
