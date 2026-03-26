// Cho 2 đa thức A(x) và B(x) tương ứng có bậc N và M. Hãy tính ma trận tích C(x) = A(x) * B(x) có
// bậc N+M−1.
// Input: Gồm 2 dòng biểu diễn các đa thức A(x) và B(x), mỗi dòng
//  Số đầu tiên N là bậc của đa thức;
//  N+1 số nguyên tiếp theo, số thứ i là hệ số của xi−1.
// Output: Một số nguyên duy nhất là XOR của các hệ số của đa thức C(x).
// Ví dụ:
// Input:
// 3 83 86 77 15
// 4 93 35 86 92 49
// Output:
// 20731
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cout<<"Nhap N:";
    cin >> N;  // bậc của đa thức - mũ
    vector<int> A(N+1);  // hệ số mũ dựa vào i
    for (int i = 0; i <= N; i++) cin >> A[i];
    cout<<"Nhap M:";
    cin >> M;
    vector<int> B(M+1);  // hệ số mũ dựa vào i
    for (int i = 0; i <= M; i++) cin >> B[i];

    vector<long long> C(N+M+1, 0);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            C[i+j] += 1LL * A[i] * B[j];
        }
    }

    long long result = 0;
    for (int i = 0; i <= N+M; i++) {
        result ^= C[i];  // XOR
    }

    cout << "Ket qua:"<<result << "\n";
    return 0;
}
