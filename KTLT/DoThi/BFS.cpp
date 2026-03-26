#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Hàm nhập đồ thị
void nhapDoThi(int n, int m, vector<vector<int>>& graph) {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // nếu đồ thị vô hướng
    }
}

// Hàm BFS duyệt đồ thị bắt đầu từ đỉnh start
void BFS(int start, const vector<vector<int>>& graph) {
    int n = graph.size(); // số đỉnh trong đồ thị
    vector<bool> visited(n, false); // mảng đánh dấu các mảng được thăm// hiện tại chưa có đỉnh nào được thăm
    queue<int> q; // hàng đợi lưu các đỉnh chờ duyệt

    visited[start] = true; // đỉnh ban đầu bắt đầu được thăm
    q.push(start); // bỏ vào hàng đợi để bắt đầu duyệt

    cout<<"BFS: "<<"\n";
    while (!q.empty()) { // hàng đợi không rỗng - bắt đầu duyệt
        int u = q.front(); // lấy đỉnh đầu tiên trong hàng đợi
        q.pop(); // xóa khỏi hàng đợi
        cout << u << " "; // nhận đỉnh này nên in ra 

        for (int v : graph[u]) { // được thêm các đỉnh kề từ void nhapDoThi -- duyệt từng đỉnh kề của u
            if (!visited[v]) { // nếu v chưa được thăm
                visited[v] = true;// được thăm -- từ False qua true
                q.push(v); // đưa vào cuối hàng đợi
            }
        }
    }
}
// 1. tạo 1 đồ thị gồm n đỉnh, mỗi cạnh sẽ là 1 cặp (u,v)-> cặp đỉnh
//  trong đó sẽ tìm các đỉnh kề của mỗi đỉnh, bằng cách gán khi nhập đỉnh
// 2. tạo 1 mảng thăm(vector), tạo 1 hàng đợi để duyệt
// 3. gán tất cả đỉnh trong mảng chưa thăm
// 4. bắt đầu từ đỉnh đầu tiên, lấy đỉnh đầu tiên bỏ vào hàng đợi(q) và vào hàm được thăm( visited)
// 5. Chạy vòng lặp while -- hàng đợi(q) không rỗng - rỗng là ngừng chương trình
// - lấy đỉnh đầu tiên(u) trong hàng đợi & xóa khỏi hàng đợi - in ra 
// - duyệt qua các đỉnh kề của đỉnh u (v)- nếu chưa thăm thì đưa vào được thăm(visited)
// - đưa vào hàm đợi -- duyệt lần lượt đến khi hết hàng đợi và tất cả đều được thăm
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);

    nhapDoThi(n, m, graph);

    int start;
    cin >> start;

    BFS(start, graph);

    return 0;
}
