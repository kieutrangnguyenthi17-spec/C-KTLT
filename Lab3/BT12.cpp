// Cho đồ thị vô hướng G, hãy đếm số đường đi đi qua k cạnh và không đi qua đỉnh nào quá một lần.
// Dữ liệu vào:
// Dòng 1: Chứa hai số nguyên n và k (1≤n≤30, 1≤k≤10) với n là số đỉnh của G. Các đỉnh sẽ
// được đánh số từ 1 đến n
// Dòng 2: Chứa số nguyên m (1≤m≤60) là số cạnh của G
// m dòng tiếp theo: Mỗi dòng chưa hai số nguyên là một cạnh của G
// Kết quả:
// Số lượng đường đi đơn độ dài k
// Ví dụ:
// Dữ liệu mẫu:
// 4 3
// 5
// 1 2
// 1 3
// 1 4
// 2 3
// 3 4
// Kết quả mẫu:
// 6
// In [ ]:
#include <iostream>
#include <vector>

using namespace std;

int n, k, m;
vector<int> adj[31];
bool visited[31];
long long cnt = 0;

void dfs(int u, int depth) {
    if (depth == k) {
        cnt++;
        return;
    }
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v, depth + 1);
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // đồ thị vô hướng
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << cnt;
    return 0;
}
