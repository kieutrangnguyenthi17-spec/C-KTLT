#include <iostream>
using namespace std;

void Mystery(char *s) {
    char *p = s;
    while (*p) p++;
    while (s < p) {
        char t = *s;
        *s++ = *--p;
        *p = t;
    }
}

int main() {
    char str[] = "Hello";
    Mystery(str);
    cout << str;
    return 0;
}
