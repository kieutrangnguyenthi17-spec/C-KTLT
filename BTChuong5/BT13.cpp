// 4.13.Viết chương trình sinh tất cả tổ hợp chập k của n phần tử cho trước. 
#include <iostream>
using namespace std;

int n, k, a[25];

void sinh(int i, int last){
    if(i > k){
        for(int j = 1; j <= k; j++)
            cout << a[j] << " ";
        cout << "\n";
        return;
    }
    for(int v = last + 1; v <= n; v++){
        a[i] = v;
        sinh(i + 1, v);
    }
}

int main(){
    cin >> n >> k;
    sinh(1, 0);
}
