#include<iostream>
using namespace std;
int UCLN(int a, int b){
    if (a*b==0) return a+b;
    return UCLN(b,a%b);
}
int main(){
    int a,b;
    cin>>a>>b;
    int result=UCLN(a,b);
    cout<<result;
    return 0;
}