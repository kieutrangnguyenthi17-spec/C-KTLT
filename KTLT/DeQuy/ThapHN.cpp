#include<iostream>
using namespace std;
void ThapHN(int n,char a, char b, char c){ //a-c
    if (n == 1) {
        cout << "Chuyen dia 1 tu " << a << " sang " << c << "\n";
        return;
    }   
    ThapHN(n-1,a,c,b); //a-b
    cout << "Chuyen dia " << n << " tu " << a << " sang " << c << "\n";// lớn nhất: a-c
    ThapHN(n-1,b,a,c); //b-c
}
int main(){
    int n;
    int a,b,c;
    cin>>n;
    ThapHN(n,'a','b','c');
    return 0;
}

