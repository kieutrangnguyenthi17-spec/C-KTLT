//Cài đặt bài Tháp Hà Nội.
#include<iostream>
using namespace std;
void ThapHN(int n,char a, char b, char c){
    if(n==1){
         cout<<"Chuyen dia thu "<<n<<" tu "<<a<<" sang "<<c<<endl;
         return;
    }
    
    ThapHN(n-1,a,c,b);
    cout<<"Chuyen dia thu "<<n<<" tu "<<a<<" sang "<<c<<endl;
    ThapHN(n-1,b,a,c);
}
int main(){
    int n;
    cin>>n;
    ThapHN(n,'a','b','c');
    return 0;
}