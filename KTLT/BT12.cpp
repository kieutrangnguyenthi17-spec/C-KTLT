// Liệt kê tất cả các dãy nhị phân có độ dài n.
// ""                    (bắt đầu)
// ├─ "0"
// │   ├─ "00"
// │   │   ├─ "000"  (in)
// │   │   └─ "001"  (in)
// │   └─ "01"
// │       ├─ "010"  (in)
// │       └─ "011"  (in)
// └─ "1"
//     ├─ "10"
//     │   ├─ "100"  (in)
//     │   └─ "101"  (in)
//     └─ "11"
//         ├─ "110"  (in)
//         └─ "111"  (in)
#include<iostream>
using namespace std;
void Binary(int n, int index, string s){
    if(index==n){
        cout<<s<<"\n";
    }
    else {
    Binary(n,index+1,s+"0");
    Binary(n,index+1,s+"1");
    }
}
int main(){
    int n;
    cin>>n;
    Binary(n,0,""); 
    return 0;
}
