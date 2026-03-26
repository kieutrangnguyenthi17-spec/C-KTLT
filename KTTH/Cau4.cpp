#include <iostream>
using namespace std;
class Base {
public:
 Base(int val) { a = val * 2; cout << a; }
protected:
 int a;
};
class Derived : public Base {
public:
 Derived(int val) : Base(val) { cout << val; }
};
int main() {
 Derived obj(3);
}