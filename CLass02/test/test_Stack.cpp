#include <cassert>
#include <stdexcept>
#include <string>
#include <utility>

#include "Stack.h"

int main()
{
    Stack<int> stack;
    assert(stack.empty());
    assert(stack.size() == 0);

    stack.push(1);
    stack.push(2);
    assert(!stack.empty());
    assert(stack.size() == 2);
    assert(stack.top() == 2);

    stack.pop();
    assert(stack.top() == 1);
    stack.pop();
    assert(stack.empty());

    bool threw = false;
    try {
        stack.pop();
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    Stack<std::string> words(2, "hi");
    assert(words.size() == 2);
    assert(words.top() == "hi");

    std::string value = "there";
    words.push(value);
    words.push(std::string("done"));
    assert(words.top() == "done");

    const Stack<std::string>& ref = words;
    assert(ref.top() == "done");

    return 0;
}
