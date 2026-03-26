// Bài tập 5: Viết hàm thực hiện thuật toán DFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách  kề vector< list<int> > . Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát  từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size(), false);

    S.push(1);

    while (!S.empty()) {
        int u = S.top();
        S.pop();

        if (visited[u]) continue;

        visited[u] = true;
        cout << u << " ";

        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
            if (!visited[*it]) {
                S.push(*it);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< list<int> > adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(adj);

    return 0;
}
