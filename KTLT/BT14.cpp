//Liệt kê tất cả hoán vị của tập n phần tử
#include<iostream>
#include<vector>
using namespace std;
void hoanVi(vector<int>& a, int start) {
    if (start == a.size() - 1) {   
        for (int x : a) cout << x << " ";
        cout << "\n";
        return;       // in ra hoán vị hiện tại
    }
    for (int i = start; i < a.size(); i++) {
        swap(a[start], a[i]);           // hoán đổi
        hoanVi(a, start + 1);             // đệ quy tiếp phần tử kế tiếp
        swap(a[start], a[i]);           // hoàn tác hoán đổi
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    hoanVi(a, 0);
    return 0;
}