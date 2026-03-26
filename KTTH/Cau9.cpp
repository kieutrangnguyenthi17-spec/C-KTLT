#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;
    int &r = a;   // r là tham chiếu đến a
    r = b;        // gán giá trị của b cho r (tức là cho a)
    cout << a << ", " << b;
    return 0;
}
