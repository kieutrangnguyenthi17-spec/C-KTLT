#include <iostream>
using namespace std;

template<typename T>
T absVal(T x) {
    return x < 0 ? -x : x;
}

int main() {
    cout << absVal(-5) + absVal(-5.0);
    return 0;
}
