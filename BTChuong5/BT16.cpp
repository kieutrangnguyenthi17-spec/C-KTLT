// 4.16.In ra theo thứ tự tăng dần tất cả các phân số tối giản 0<m/n<1 với mẫu số ≤10 
#include <iostream>
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    for(int n=2;n<=10;n++)
        for(int m=1;m<n;m++)
            if(gcd(m,n)==1)
                cout << m << "/" << n << "\n";
}
