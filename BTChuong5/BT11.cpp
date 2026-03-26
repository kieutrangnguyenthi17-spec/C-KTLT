// 4.11.Sinh tất cả tập con của tập n phần tử. 
#include <iostream>
using namespace std;

int n;
int a[25];

void sinh(int i){
    if(i > n){
        cout << "{ ";
        for(int j = 1; j <= n; j++)
            if(a[j]) cout << j << " ";
        cout << "}\n";
        return;
    }
    for(int v = 0; v <= 1; v++){
        a[i] = v;
        sinh(i + 1);
    }
}

int main(){
    cin >> n;
    sinh(1);
}
