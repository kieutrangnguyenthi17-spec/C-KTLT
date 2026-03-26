// 4.15.Viết chương trình sinh tất cả chỉnh hợp chập k của n phần tử cho trước. 
#include <iostream>
using namespace std;

int n, k, a[25];
bool used[25];

void sinh(int i){
    if(i > k){
        for(int j = 1; j <= k; j++)
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
    cin >> n >> k;
    sinh(1);
}
