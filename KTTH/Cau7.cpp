#include<iostream>
using namespace std;
int countDown(int n) {
 static int count = 0;
 if (n > 0) {
 count++;
 countDown(n - 1);
 }
 return count;
}
int main() {
 cout << countDown(5) << ", " << countDown(3);
}