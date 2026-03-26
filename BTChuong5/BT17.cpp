// 4.17.Cho hàm F(n) với n nguyên không âm được xác định như sau: F(0)=0, F(1)=1, F(2n)=F(n), F(2n+1) = F(n) + F(n+1). 
// Viết chương trình tính F(n) với điều kiện không dùng mảng độ dài N. 
#include <iostream>
using namespace std;

long long F(long long n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n%2==0) return F(n/2);
    return F(n/2) + F(n/2 + 1);
}

int main(){
    long long n;
    cin >> n;
    cout << F(n);
}
