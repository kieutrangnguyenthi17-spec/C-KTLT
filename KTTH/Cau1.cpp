#include<iostream>
using namespace std;
int main() {     
    char s[] = "ABCDE";     
    int *p = (int*)(s + 1);     
    *p = 0x5A5A5A5A; 
    cout << s; 
} 
