#include <iostream>
using namespace std;

int main() {
    int x = 6;
    if (x & 3 == 2)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
