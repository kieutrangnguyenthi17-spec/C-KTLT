#include<iostream>
using namespace std;
int TongDeQuy(int n)
{
if (n == 1)
return 1;
return n + TongDeQuy(n - 1);
}
int TongKhongDeQuy(int n)
{
return n * (n + 1) / 2; // dựa vào csc
}
int TongVongLap(int n)
{
int S = 0;
for (int i = 1; i <= n; i++)
S += i;
return S;
}
int main(){
    int n;
    cin>>n;
    int DQ=TongDeQuy(n);
    int TT=TongKhongDeQuy(n);
    int KDQ=TongVongLap(n);
    cout<<"DQ: "<<DQ;
    cout<<"\nThong thuong: "<<TT;
    cout<<"\nKhu de quy: "<<KDQ;
    return 0;
}