#include<iostream>
using namespace std;
int tongSoLe(int n) {
    if (n <= 0) return 0;            // điều kiện dừng
    if (n % 2 == 0)                 // nếu n là lẻ, bỏ qua n
        return tongSoLe(n - 1);
    else                           // nếu n là chẵn, cộng n + gọi tiếp
        return n + tongSoLe(n - 2);
}
int main(){
    int n;
    cin>>n;
    int result=tongSoLe(n);
    cout<<result;
    return 0;
}