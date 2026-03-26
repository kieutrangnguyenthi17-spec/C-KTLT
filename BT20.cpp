// Có N chi tiết được đánh số từ 0 đến N-1 cần được gia công. Các chi tiết có
// thể hoàn thành trên một máy A hoặc trên một máy B. Các máy này có thể hoạt động
// độc lập và làm việc đồng thời. Biết rằng thời gian gia công chi tiết i trên máy A là
// A[i] và trên máy B là B[i]. Hãy tìm một phương án phân công cho các máy để thời
// gian hoàn thành cả N chi tiết là sớm nhất.
/**/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<int> A, B;
int minTime = INT_MAX;
vector<int> bestAssign;
vector<int> currentAssign;

void Try(int i, int timeA, int timeB) {
    if (i == N) {
        int finishTime = max(timeA, timeB);
        if (finishTime < minTime) {
            minTime = finishTime;
            bestAssign = currentAssign;
        }
        return;
    }
    currentAssign[i] = 0;
    Try(i + 1, timeA + A[i], timeB);

    currentAssign[i] = 1;
    Try(i + 1, timeA, timeB + B[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    currentAssign.resize(N);

    Try(0, 0, 0);

    cout << "Thoi gian hoan thanh nho nhat: " << minTime << "\nPhan cong chi tiet:\n";
    for (int i = 0; i < N; i++) {
        cout << "Chi tiet " << i << ": May " << (bestAssign[i] == 0 ? "A" : "B") << "\n";
    }
    return 0;
}
