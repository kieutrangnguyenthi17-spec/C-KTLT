// 4.19.Liệt kê tất cả các cách phân tích số nguyên dương n thành tổng các số nguyên  dương, hai cách phân tích là hoán vị của nhau chỉ tính là một cách.
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

void sinh(int sum, int last){
    if(sum == n){
        for(int x : a) cout << x << " ";
        cout << "\n";
        return;
    }
    for(int v = last; v <= n - sum; v++){
        a.push_back(v);
        sinh(sum + v, v);
        a.pop_back();
    }
}

int main(){
    cin >> n;
    sinh(0, 1);
}
