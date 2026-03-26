#include <iostream>
using namespace std;
class Num { 
public: 
Num(int v) { cout << v; } 
~Num() { cout << 0; } 
}; 
int main() { 
Num a(5), b(6); 
}
