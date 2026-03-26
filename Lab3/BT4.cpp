// Cho dãy a có n phần tử. Một dãy con của a là dãy thu được bằng cách xóa đi một số phần tử
// của a và giữ nguyên thứ tự các phần tử còn lại (có thể không xóa phần tử nào). Hãy tìm dãy con
// tăng dài nhất của a
// Dữ liệu vào:
// Dòng 1: Chứa số nguyên n (1≤n≤1000)
// Dòng 2: Chứa n số nguyên a1 a2 ... an (|ai|≤109)
// Kết quả:
// Dòng đầu tiên chứa độ dài dãy con tăng dài nhất
// Dòng thứ 2 chứa chỉ số các phần tử được chọn vào dãy con đó
// Nếu có nhiều dãy con tăng dài nhất, in ra dãy bất kỳ trong số đó
// Ví dụ:
// Dữ liệu mẫu:
// 6
// 2 1 5 4 3 6
// Kết quả mẫu:h
// 3
// 2 5 6
// Hướng dẫn:
// Bài toán này được giải bằng phương pháp quy hoạch động.
// Giả sử lis(i) là độ dài dãy con tăng dài nhất kết thúc tại ai. Khi đó ta có công thức truy hồi sau:
// lis(i)=max1≤j≤i−1:aj<ai(lis(j)+1)
// In [ ]:
#include <iostream>
#include <cstring>
using namespace std;
int a[1000], n;
int mem[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải
void init(){
memset(mem, -1, sizeof(mem));
}
//# Quy hoạch động,
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    if(mem[i]!=-1) return mem[i];
    mem[i]=1;
    for(int j=0;j<i;j++){
        if(a[j]<a[i]){
            mem[i]=max(mem[i], lis(j)+1);
        }
    }
    return mem[i];
}
//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
    if (a[j] < a[i] && mem[i] == 1 + mem[j]){
        trace(j);
        break;}
    }
        cout << a[i] << " ";
    }
    int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
    if (res < lis(i)){
    res = lis(i);
    pos = i; }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}