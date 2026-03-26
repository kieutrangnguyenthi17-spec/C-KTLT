// 4.18.Hãy liệt kê tất cả các dãy nhị phân độ dài n mà trong đó cụm chữ số “01” xuất  hiện đúng 2 lần. 
#include <iostream>
using namespace std;

int n, a[25];

bool check(){
    int cnt = 0;
    for(int i=1;i<n;i++)
        if(a[i]==0 && a[i+1]==1) cnt++;
    return cnt == 2;
}

void sinh(int i){
    if(i > n){
        if(check()){
            for(int j=1;j<=n;j++)
                cout << a[j];
            cout << "\n";
        }
        return;
    }
    for(int v=0;v<=1;v++){
        a[i]=v;
        sinh(i+1);
    }
}

int main(){
    cin >> n;
    sinh(1);
}
