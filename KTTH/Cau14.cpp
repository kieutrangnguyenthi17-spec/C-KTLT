#include <iostream>
using namespace std;
int f(int n) {
    return f(n - 1) + 1;
}
int main() {
    cout << f(5);
}
