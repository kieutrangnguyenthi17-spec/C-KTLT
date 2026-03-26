//DFS – Depth First Search (Tìm kiếm theo chiều sâu)
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000;         // Số đỉnh tối đa
vector<int> adj[MAX];         // Danh sách kề
bool visited[MAX];            // Đánh dấu đỉnh đã thăm
// Hàm DFS đệ quy
void DFS(int u) {
    visited[u] = true;        // Đánh dấu đỉnh u đã thăm
    cout << u << " ";         // Xử lý đỉnh (ở đây in ra)
    for (int v : adj[u]) {    // Duyệt tất cả đỉnh kề v của u
        if (!visited[v]) {
            DFS(v);           // Gọi đệ quy duyệt đỉnh v
        }
    }
}
int main() {
    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    cout << "Nhap cac canh (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Do là đồ thị vô hướng nên thêm ngược lại
    }

    vector<bool> visited(n, false); // mảng đánh dấu các mảng được thăm// hiện tại chưa có đỉnh nào được thăm

    int k;
    cout<<"Nhap dinh bat dau: ";
    cin>>k;
    cout << "Thu tu dinh sau khi DFS bat dau tu dinh bat ki: ";
    DFS(k);

    cout << endl;
    return 0;
}
