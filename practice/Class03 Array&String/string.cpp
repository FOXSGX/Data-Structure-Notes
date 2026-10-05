#include <iostream>
using namespace std;

struct String{
    size_t length = 0;
    static constexpr size_t capacity = 8;
    char data[capacity]{'\0'};

    bool append(const char* src, size_t n){
        if (n > capacity - 1 -length){
             cout << "Overflow Error" << endl;
             return false;
        }
    else{
        for (size_t i = 0; i<n ; i++){
            data[i+length]=src[i];
        }
        data[length+n]='\0';
        length += n;
        return true;
        }
    }
};