#include<iostream>
using namespace std;
long Tinhx(int n){
    if(n==0) return 1;
    return Tinhx(n-1)+Tinhy(n-1);
}
long Tinhy(int n){
    if(n==0) return 1;
    return n*n*Tinhx(n-1)+Tinhy(n-1);
}
int main(){
    int n;
    cin>>n;
    long kqx=Tinhx(n);
    long kqy=Tinhy(n);
    cout<<"X: "<<kqx;
    cout<<"Y: "<<kqy;
    return 0;
}