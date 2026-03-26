// tính C(k, n)
#include<iostream>
using namespace std;
long long GiaiThua(int n){
    if(n==1) return 1;
    return n*GiaiThua(n-1);
}
long long ToHop(int n, int k){
    return GiaiThua(n)/(GiaiThua(k)*(GiaiThua(n-k)));
}

int main(){
    int n,k;
    cin>>n>>k;
    long long result=ToHop(n,k);
    cout<<"To hop: "<<result;
    return 0;
} 