#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printOptimal(int i, int j, vector<vector<int>>& s) {
    if (i == j) {
        cout << "A" << i + 1;
        return;
    }
    cout << "(";
    printOptimal(i, s[i][j], s);
    cout << " x ";
    printOptimal(s[i][j] + 1, j, s);
    cout << ")";
}

int matrixChainOrder(vector<int>& p, int n, vector<vector<int>>& s) {

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; ++k) {
                long long q =
                    dp[i][k] + dp[k + 1][j]
                    + 1LL * p[i] * p[k + 1] * p[j + 1];

                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return dp[0][n - 1];
}

void input(int &n, vector<int> &p) {
    cout << "Nhap so luong ma tran: ";
    cin >> n;

    cout << "Nhap kich thuoc ma tran: ";
    p.resize(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> p[i];
}

void output(int ans, vector<vector<int>> &s, int n) {
    cout << "\n===== KET QUA =====\n";
    cout << "So phep nhan toi thieu: " << ans << endl;

    cout << "Cach dat ngoac toi uu: ";
    printOptimal(0, n - 1, s);
    cout << endl;
}

int main() {

    int n;
    vector<int> p;

    input(n, p);

    vector<vector<int>> s(n, vector<int>(n));

    int ans = matrixChainOrder(p, n, s);

    output(ans, s, n);

    return 0;
}
