#include <iostream>
using namespace std;

void recursive(int n) {
    if (n <= 0)
        return;
    recursive(n - 1);
    recursive(n - 1);
}

int main() {
    int n = 3;
    recursive(n);
    return 0;
}
