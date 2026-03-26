#include<iostream>
using namespace std;
int power(int n, int exp){
    if(exp==0) return 1; // nếu mũ=0 thì return 1;
    return n*power(n,exp-1);
}
int sum(int n){
    if (n==1) return 1;
    return power(n,n)+sum(n-1);
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int result=sum(n);
    cout<<"Tong "<<": "<<result;
    return 0;
}
// n=2
// 1. 2*power(2,1)
// 2. 2*2*power(2,0)
// 3. 2*2*1
// n=4
// 1. 4*power(4,3)
// 2. 4*4*power(4,2)
// 3. 4*4*4*power(4,1)
// 4. 4*4*4*4*power(4,0)
// 5. 4*4*4*4*1
