#include <iostream>
using namespace std;

int n;
int a[25];

void sinh(int i){
    if(i > n){
        for(int j = 1; j <= n; j++)
            cout << a[j];
        cout << "\n";
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
    return 0;
}
