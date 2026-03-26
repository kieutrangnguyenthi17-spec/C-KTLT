#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> nhap(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    return a;
}

int main(){
    vector<int> a = nhap();

    cout << "Mang truoc khi sap xep: ";
    for(int i : a) cout << i << " ";
    cout << endl;

    sort(a.begin(), a.end());

    cout << "Mang sau khi sap xep: ";
    for(int i : a) cout << i << " ";
    cout << endl;

    cout << "Nhap so can tim x: ";
    int x; 
    cin >> x;

    cout << (binary_search(a.begin(), a.end(), x) ? "YES" : "NOT FOUND") << endl;

    auto it = lower_bound(a.begin(), a.end(), x);

    if(it == a.end()) 
        cout << "Khong ton tai vi tri đau tien cua x\n";
    else 
        cout << "Vi tri dau tien của x: " << (it - a.begin())+1 << endl;
}