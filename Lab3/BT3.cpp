// Một người xuất phát tại thành phố 1, muốn đi thăm tất cả các thành phố khác, mỗi thành phố đúng 1
// lần và quay về 1. Chi phí để đi từ thành phố i sang thành phố j là ci,j. Hãy tìm tổng chi phí nhỏ nhất
// có thể
// Dữ liệu vào:
// Dòng 1: Chứa số nguyên n (1≤n≤16)
// n dòng tiếp theo: Chứa ma trận c (0≤ci,j≤1000000)
// Kết quả:
// Ghi tổng chi phí nhỏ nhất có thể
// Ví dụ:
// Dữ liệu mẫu: 4
// 0 2 1 3
// 4 0 1 2
// 2 1 0 3
// 3 4 2 0
// Kết quả mẫu:
// 7
// In [ ]:
#include <iostream>
#include <climits>
using namespace std;
    #define MAX 100
    int n, c[MAX][MAX];
    int cmin = INT_MAX;
    int best = INT_MAX;
    int curr = 0;
    int mark[MAX] = {0};
    int x[MAX];
//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j){
    cin >> c[i][j];
    if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
    }
}
//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if (!mark[i]){
            x[k]=i;
            mark[i]=1;
            curr +=c[x[k-1]][i];
            if (k==n){
                best= min(best,curr+c[i][1]);
            }
            else {
                TRY(k+1);
            }
            curr -=c[x[k-1]][i];
            mark[i]=0;
        }
    }
}
int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}