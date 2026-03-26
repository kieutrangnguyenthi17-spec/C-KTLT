#include <iostream>
using namespace std;
int main(){
    int m = 5;
    switch (m + 2) {
    case 6: m += 2;
    case 7: m += 3;
    default: m += 4;
    }
    cout << m;
    return 0;
}