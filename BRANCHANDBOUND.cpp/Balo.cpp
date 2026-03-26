#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
    double w,v;
    double unit;
};

int n;
double W;
vector<Item> a;
double bestValue = 0;

double bound(int idx, double curWeight, double curValue){
    double cap = W - curWeight;
    double value = curValue;

    while(idx < n && a[idx].w <= cap){
        cap -= a[idx].w;
        value += a[idx].v;
        idx++;
    }

    if(idx < n)
        value += a[idx].unit * cap;

    return value;
}

void Try(int idx, double curWeight, double curValue){
    if(idx == n){
        bestValue = max(bestValue, curValue);
        return;
    }

    double ub = bound(idx, curWeight, curValue);
    if(ub <= bestValue) return;

    if(curWeight + a[idx].w <= W)
        Try(idx+1, curWeight + a[idx].w, curValue + a[idx].v);

    Try(idx+1, curWeight, curValue);
}

int main(){
    cout << "Nhap so vat: ";
    cin >> n;
    cout << "Nhap suc chua W: ";
    cin >> W;

    a.resize(n);

    cout << "Nhap (trong luong, gia tri):\n";
    for(int i=0;i<n;i++){
        cin >> a[i].w >> a[i].v;
        a[i].unit = a[i].v / a[i].w;
    }

    sort(a.begin(), a.end(),
         [](Item A, Item B){
            return A.unit > B.unit;
         });

    Try(0,0,0);

    cout << "\nGia tri lon nhat = " << bestValue;

    return 0;
}
