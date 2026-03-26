// 4.12.Sinh tất cả hoán vị của tập n phần tử. 
#include <iostream>
using namespace std;

int n, a[25];
bool used[25];

void sinh(int i){
    if(i > n){
        for(int j = 1; j <= n; j++)
            cout << a[j] << " ";
        cout << "\n";
        return;
    }
    for(int v = 1; v <= n; v++){
        if(!used[v]){
            used[v] = true;
            a[i] = v;
            sinh(i + 1);
            used[v] = false;
        }
    }
}

int main(){
    cin >> n;
    sinh(1);
}
