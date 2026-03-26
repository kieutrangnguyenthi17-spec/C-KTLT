#include <iostream>
using namespace std;

int main() {
    char str[] = "HelloWorld";
    char *p = str;
    p += 5;
    cout << p;
    return 0;
}
